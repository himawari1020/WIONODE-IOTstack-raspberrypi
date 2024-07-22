  #include <ESP8266WiFi.h>
  #include <PubSubClient.h>
  #include <Wire.h>

  // WiFi credentials
  const char* ssid = "ctc-g-86df8f";
  const char* password = "50793f0041a3b";

  // MQTT server details
  const char* mqtt_server = "192.168.0.32";
  const int mqtt_port = 1883;
  const char* mqtt_topic = "/home/sensors2";

  // Pin definitions
  const uint8_t PORT0A = 1;
  const uint8_t PORT0B = 3;
  const uint8_t PORT1A = 4;
  const uint8_t PORT1B = 5;
  const uint8_t PORT_POWER = 15;
  const uint8_t FUNC_BTN = 0;
  const uint8_t BLUE_LED = 2;
  const uint8_t RED_LED = PORT_POWER;

  const uint8_t UART_TX = PORT0A;
  const uint8_t UART_RX = PORT0B;
  const uint8_t I2C_SDA = PORT1A;
  const uint8_t I2C_SCL = PORT1B;

  unsigned long durationtime;
  unsigned long pretime;

  // WiFi and MQTT clients
  WiFiClient espClient;
  PubSubClient client(espClient);

  void setup() {
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(mqttCallback);

    pinMode(PORT1B, INPUT);
    pinMode(FUNC_BTN, INPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(PORT_POWER, OUTPUT);
    digitalWrite(PORT_POWER, HIGH);
    
    Wire.begin(I2C_SDA, I2C_SCL);
  }

  void setup_wifi() {
    delay(10);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }

  void mqttCallback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (unsigned int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
  }

  void reconnect() {
    while (!client.connected()) {
      Serial.print("Attempting MQTT connection...");
      if (client.connect("ESP8266Client")) {
        Serial.println("connected");
        client.subscribe("inTopic");
      } else {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        delay(5000);
      }
    }
  }

  void loop() {
    if (!client.connected()) {
      reconnect();
    }
    client.loop();

    if (WiFi.status() == WL_CONNECTED) {
      float sending_data = MeasureCurrent();

      durationtime = (millis() - pretime) / 1000;
      pretime = millis();

      Serial.print("duration time: ");
      Serial.print(durationtime);
      Serial.println(" sec for this loop");

      Serial.println(sending_data);

      String payload = String("{\"sensor\": \"current\", \"espvalue\": ") + sending_data + String(", \"duration\": ") + durationtime + String("}");
      client.publish(mqtt_topic, payload.c_str());

      delay(5000); // delay for 5 seconds
    } else {
      Serial.println("Not connected to the Internet");
      delay(250);
    }
  }

  float MeasureCurrent() {
    int ad_data[100];
    unsigned long micro_time1 = micros();
    for (int i = 0; i < 100; i++) {
      while (micros() - micro_time1 < 1000) {
        delayMicroseconds(10);
      }
      micro_time1 = micros();
      ad_data[i] = (float)analogRead(A0);
    }

    int max_data = 0;
    int min_data = 1023;
    for (int i = 0; i < 100; i++) {
      if (ad_data[i] > max_data) max_data = ad_data[i];
      if (ad_data[i] < min_data) min_data = ad_data[i];
    }

    float current_amplitude = (max_data - min_data) * 32.0 / 1000;
    return (float)current_amplitude;
  }
