# QZSSDCX

このライブラリは日本の衛星測位システム「みちびき（準天頂衛星システム）」から配信される[災害・危機管理通報サービス「災危通報」](https://qzss.go.jp/overview/services/sv08_dc-report.html)の拡張版「災危通報（拡張）」をデコードするライブラリです。

## 使い方

```ino
byte l1s_msgbuf[] = { 0xC6, 0xB0, 0x60, 0x0D, 0xE2, 0xBF, 0x88, 0xE9, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x11, 0xA1, 0xC8, 0x4E, 0xD4 };

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;  //ターミナルを開くまでまつ
  delay(1000);

  // DCXDecoderインスタンスを作成
  DCXDecoder dec;
  // 250ビットのL1Sメッセージが入ったバッファを入力する
  // デコードした結果はDCXDecoderのメンバ変数 DCXMessage r に格納される
  dec.decode(l1s_msgbuf);
  // デコード結果のサマリーをSerialに出力
  dec.printSummary(Serial, dec.r);
  // デコード結果すべてをSerialに出力
  dec.printAll(Serial, dec.r);
}
```

## 出力例

```
## Jアラート(テスト) ###
国/地域名: 日本
情報提供: 消防庁(FDMA)
災害カテゴリ種別: 安全性 - 安全性警告
重大度: 極端 - 生命または財産への非常に重大な脅威
災害発生週: 今週
災害発生日時: 火曜日 14:00 UTC
災害の継続時間: 不明
避難行動: （指示なし）
対象地域: 沖縄県 鹿児島県 宮崎県 大分県 熊本県 長崎県 佐賀県 福岡県 高知県 愛媛県 香川県 徳島県 山口県 広島県 岡山県 島根県 鳥取県 和歌山県 奈良県 兵庫県 大阪府 京都府 滋賀県 三重県 愛知県 静岡県 岐阜県 長野県 山梨県 福井県 石川県 富山県 新潟県 神奈川県 東京都 千葉県 埼玉県 群馬県 栃木県 茨城県 福島県 山形県 秋田県 宮城県 岩手県 青森県 北海道
```
