# ラズベリーパイIOTstack構築方法
## IOTstackのインストールは[https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server](https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server)

# 準備するもの
<dl>
    <dt><strong>raspberrypi</strong></dt>
    <dd>microSDカードライタと32GBのmicroSDが必要、OSはraspberrypi-Imagerソフトを使ってください。<br><a href="https://downloads.raspberrypi.org/imager/imager_latest.exe">https://downloads.raspberrypi.org/imager/imager_latest.exe</a></dd>
    <dt><strong>WIONODE ESP8266</strong></dt>
    <dd><img width=350 src="https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/003_%E8%B3%87%E6%96%99.jpg?raw=true"><br><a href="https://www.arduino.cc/en/software">Arduino IDE</a>を使います、WIONODEのプログラムコードは下記Githubのリンクからダウンロードしてください。<a href="https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/WIONODE_%E9%9B%BB%E5%9C%A7%E6%B8%AC%E5%AE%9A%E7%94%A8.ino">https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/WIONODE_%E9%9B%BB%E5%9C%A7%E6%B8%AC%E5%AE%9A%E7%94%A8.ino</a></dd>
    <dt><strong>WIONODEシリアル変換アダプタ</strong></dt>
    <dd>書き込みには下の画像のアダプタが必要です。取扱方法に関しては<a href="https://dev-moyashi.hatenablog.com/entry/2016/09/08/185933">もやし丸様の「Wio NodeをArduinoとして動作させる」</a>を参照してください。<br><img width=350 src="https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/002_%E8%B3%87%E6%96%99.jpg?raw=true"></dd>
</dl>

# 手順

1. [https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server](https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server)でraspberrypiの構築を全て完了させてください。

2. [プログラムをダウンロード](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/WIONODE_%E9%9B%BB%E5%9C%A7%E6%B8%AC%E5%AE%9A%E7%94%A8.ino)し、６・７行目を現場のSSIDとパスを、１０行目に任意のIPアドレスを保存しArduinoIDEでWIONODEに書き込みをしてください。<br>![手順2](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/004_%E6%89%8B%E9%A0%86.jpg?raw=true)

3. [https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/NODERED_flows_FOR_WIONODE.json](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/NODERED_flows_FOR_WIONODE.json)をダウンロード、ブラウザから\<RaspberryのIPアドレス\>:1880にアクセスし、**Ctrl+i→読み込むファイルを選択**でjsonファイルをインポートしてください。<br>![手順1](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/001_%E6%89%8B%E9%A0%86.jpg?raw=true)

4.1. **「mqtt inノード」をダブルクリック→「サーバ項目」のエンピツマークをクリック→IPアドレスをRaspberrypiのプライべートIPアドレスに変更**、これを必要分行う（例では「mqtt inノード」が2個分あります）<br>![手順2](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/005_%E6%89%8B%E9%A0%86.jpg?raw=true)

4.2. 同様の手順で **「influxdb outノード」をダブルクリック→「Server項目」のエンピツマークをクリック→IPアドレスをRaspberrypiのプライべートIPアドレスに変更**、これを必要分行う（例では「influxdb outノード」が2個分あります）<br>![手順3](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/006_%E6%89%8B%E9%A0%86.jpg?raw=true)

4.3. Noderedの変更を保存するために**画面右上の「デプロイ」**を押下し反映させる。<br>![手順4](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/007_%E6%89%8B%E9%A0%86.jpg?raw=true)