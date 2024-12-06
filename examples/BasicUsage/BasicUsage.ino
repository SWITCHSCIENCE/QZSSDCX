#include "QZSSDCX.h"

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

void loop() {
  // put your main code here, to run repeatedly:
}
