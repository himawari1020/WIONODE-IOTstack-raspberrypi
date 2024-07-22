# ラズベリーパイIOTstack構築方法
## IOTstackのインストールは[https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server](https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server)

# 準備するもの
<dl>
    <dt><strong>raspberrypi</strong></dt>
    <dd>microSDカードライタと32GBのmicroSDが必要、OSはraspberrypi-Imagerソフトを使ってください。<br><a href="https://downloads.raspberrypi.org/imager/imager_latest.exe">https://downloads.raspberrypi.org/imager/imager_latest.exe</a></dd>
    <dt><strong>WIONODE ESP8266</strong></dt>
    <img src="https://jp.images-monotaro.com/Monotaro3/pi/full/mono89744113-180516-02.jpg">
    <dd><a href="https://www.arduino.cc/en/software">Arduino IDE</a>を使います、センサーはPanasonic CT250Aを想定しています。WIONODEのプログラムコードは下記Githubのリンクからダウンロードしてください。<br><a href="https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi">https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi</a></dd>
    <dt><strong></strong></dt>
    <dd></dd>
</dl>

# 手順

1. [https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server](https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server)でraspberrypiのセットアップを完了させてください。
2. [https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/NODERED_flows_FOR_WIONODE.json](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/NODERED_flows_FOR_WIONODE.json)をダウンロード、ブラウザから\<RaspberryのIPアドレス\>:1880にアクセスし、**Ctrl+i→読み込むファイルを選択**でjsonファイルをインポートしてください。

<img src="https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/001_%E6%89%8B%E9%A0%86.jpg?raw=true">