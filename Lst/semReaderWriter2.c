int       cnt = 0;                  // リーダ間の共有変数（読出し中のリーダ数）
Semaphore cntSem = 1;               // cnt の排他制御用セマフォ

void readerThread() {               // リータスレッド（複数のスレッドで並列実行する）
  for ( ; ; ) {                     // リーダスレッドは以下を繰り返す
    P( &cntSem );                   // cnt にロックを掛ける
    if ( cnt == 0 ) P( &rwSem );    // 自分が最初のリーダなら，代表してロックする
    cnt = cnt + 1;                  // cnt をインクリメント
    V( &cntSem );                   // cnt のロックを外す
    Data d = readRecords();         // データを読みだす
    P( &cntSem );                   // cnt にロックを掛ける
    cnt = cnt - 1;                  // cnt をデクリメント
    if ( cnt == 0 ) V( &rwSem );    // 自分が最後のリーダなら，代表してロックを外す
    V( &cntSem );                   // cnt のロックを外す
    consume( d );                   // データを使用する
  }
}
