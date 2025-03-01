int       account;                  // スレッド間の共有変数（残高）
Semaphore accSem = 1;               // 初期値1のセマフォaccSem（accountのロック用）
void receiveThread() {              // 入金管理スレッド
  for ( ; ; ) {                     // 入金管理スレッドは以下を繰り返す
    int receipt = receiveMoney();   // ネットワークから入金を受信する
    P( &accSem );                   // account変数をロックするための P 操作
    account = account + receipt;    // account変数を変更する(クリティカルセクション)
    V( &accSem );                   // account変数をロック解除するための V 操作
  }
}
void payThread() {                  // 引落し管理スレッド
  for ( ; ; ) {                     // 引落し管理スレッドは以下を繰り返す
    int payment	= payMoney();       // ネットワークから支払い額を受信する
    P( &accSem );                   // account変数をロックするための P 操作
    account = account - payment;    // account変数を変更する(クリティカルセクション)
    V( &accSem );                   // account変数をロック解除するための V 操作
  }
}
