Data      records;                  // 共有するデータ
Semaphore rwSem = 1;                // リーダとライタの排他用セマフォ

void writerThread() {               // ライタスレッド（複数のスレッドで並列実行する）
  for ( ; ; ) {                     // ライタスレッドは以下を繰り返す
    Data d = produce();             // 新しいデータを作る
    P( &rwSem );                    // 共有データにロックを掛ける
    writeRecores( d );              // データを書換える
    V( &rwSem );                    // 共有データのロックを外す
  }
}
