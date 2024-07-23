# ラズベリーパイIOTstack構築方法
## Raspberrypiの構築は[https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server](https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server)をベースにしています。

# 準備するもの
<dl>
    <dt><strong>各ソフト</strong></dt>
    <dd>
    <table>
    <thead>
        <tr>
        <th>ソフト名</th> <th>リンク先</th>
        </tr>
    </thead>
    <tr>
        <td> Teraterm </td> <td><a href="https://github.com/TeraTermProject/teraterm/releases/download/v5.2/teraterm-5.2.exe">https://github.com/TeraTermProject/teraterm/releases/download/v5.2/teraterm-5.2.exe</a></td>
    </tr>
    <tr>
        <td> Raspberry Pi Imager </td> <td><a href="https://downloads.raspberrypi.org/imager/imager_latest.exe">https://downloads.raspberrypi.org/imager/imager_latest.exe</a></td>
    </tr>
    <tr>
        <td> Arduino IDE </td> <td><a href="https://www.arduino.cc/en/software">https://www.arduino.cc/en/software</a></td>
    </tr>
    </table>
    </dd>
    <dt><strong>開発PC</strong></dt>
    <dd>Windowsマシンで行いました。</dd>
    <dt><strong>Raspberry Pi</strong></dt>
    <dd>microSDカードライタとmicroSDが必要です、書き込みソフトはRaspberry Pi Imagerを使ってください。</dd>
    <dt><strong>WIONODE ESP8266</strong></dt>
    <dd><img width=350 src="https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/003_%E8%B3%87%E6%96%99.jpg?raw=true"><br>WIONODEのプログラムコードは下記Githubのリンクからダウンロードしてください。<a href="https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/WIONODE_%E9%9B%BB%E5%9C%A7%E6%B8%AC%E5%AE%9A%E7%94%A8.ino">https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/WIONODE_%E9%9B%BB%E5%9C%A7%E6%B8%AC%E5%AE%9A%E7%94%A8.ino</a></dd>
    <dt><strong>WIONODEシリアル変換アダプタ</strong></dt>
    <dd>書き込みには下の画像のアダプタが必要です。取扱方法に関しては<a href="https://dev-moyashi.hatenablog.com/entry/2016/09/08/185933">もやし丸様の「Wio NodeをArduinoとして動作させる」</a>を参照してください。<br><img width=350 src="https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/002_%E8%B3%87%E6%96%99.jpg?raw=true"></dd>
    <dt><strong>5VのACアダプタx必要分</strong></dt>
    <dd>※Raspberryの推奨電源は5V3Aです、もし途中でハングアップ・フリーズする場合は電源を確認してください。</dd>
</dl>

# 手順

1. [https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server](https://learnembeddedsystems.co.uk/easy-raspberry-pi-iot-server)でraspberrypiの構築を全て完了させてください。

2. [プログラムをダウンロード](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/WIONODE_%E9%9B%BB%E5%9C%A7%E6%B8%AC%E5%AE%9A%E7%94%A8.ino)し、６・７行目を現場のSSIDとパスを、１０行目に任意のIPアドレスを保存しArduinoIDEでWIONODEに書き込みをしてください。<br>![手順2](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/004_%E6%89%8B%E9%A0%86.jpg?raw=true)

3. [https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/NODERED_flows_FOR_WIONODE.json](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/NODERED_flows_FOR_WIONODE.json)をダウンロード、ブラウザから\<RaspberryのIPアドレス\>:1880にアクセスし、**Ctrl+i→読み込むファイルを選択**でjsonファイルをインポートしてください。<br>![手順1](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/001_%E6%89%8B%E9%A0%86.jpg?raw=true)

4. **「mqtt inノード」を押下→「サーバ項目」のエンピツマークを押下→IPアドレスをRaspberrypiのIPアドレスに変更**、これを必要分行います（例では「mqtt inノード」が2個分あります）<br>![手順2](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/005_%E6%89%8B%E9%A0%86.jpg?raw=true)

5. 同様の手順で **「influxdb outノード」を押下→「Server項目」のエンピツマークを押下→IPアドレスをRaspberrypiのIPアドレスに変更**、これを必要分行います（例では「influxdb outノード」が2個分あります）<br>![手順3](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/006_%E6%89%8B%E9%A0%86.jpg?raw=true)

6. Noderedの変更を保存しますために**画面右上の「デプロイ」**を押下し反映させます。<br>![手順4](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/007_%E6%89%8B%E9%A0%86.jpg?raw=true)

7. WebブラウザのURLバーから\<RaspberryのIPアドレス\>:3000にアクセス、**左のメニューからData sources→influxdbを押下→4つの項目を下の画像の通りに変更し「Save&Test」を押下します。** なお、「URLの項目」は**http://\<RaspberrypiのIPアドレス\>:8086**とします。<br>![手順5](https://github.com/himawari1020/WIONODE-IOTstack-raspberrypi/blob/main/src/img/010_%E6%89%8B%E9%A0%86.jpg?raw=true)

8. **左のメニューからDashboards→New→New Dashboard→+Add visualization→influxdbの順に押下**し、