Data      buffer[N];                // スレッド間で共有するリングバッファ
Semaphore emptySem = N;             // リングバッファの空きスロット数を表すセマフォ
Semaphore fullSem  = 0;             // リングバッファの使用中スロット数を表すセマフォ
int       in = 0;                   // リングバッファの次回格納位置
Semaphore inSem = 1;                // in の排他制御用セマフォ
void producerThread() {             // 生産者スレッド（複数のスレッドで並列実行する）
  for ( ; ; ) {                     // 生産者スレッドは以下を繰り返す
    Data d = produce();             // 新しいデータを作る
    P( &emptySem );                 // リングバッファの空き数をデクリメント
    P( &inSem );                    // in にロックを掛ける
    buffer[ in ] = d;               // リングバッファにデータを格納
    in = (in + 1) % N;              // 次回格納位置を更新
    V( &inSem );                    // in のロックを外す
    V( &fullSem );                  // リングバッファのデータ数をインクリメント
  }
}
int out = 0;                        // リングバッファの次回取り出し位置
Semaphore outSem = 1;               // out の排他制御用セマフォ
void consumerThread() {             // 消費者スレッド（複数のスレッドで並列実行する）
  for ( ; ; ) {                     // 消費者スレッドは以下を繰り返す
    P( &fullSem );                  // リングバッファのデータ数をデクリメント
    P( &outSem );                   // out にロックを掛ける
    Data d = buffer[ out ];         // リングバッファからデータを取り出す
    out = (out + 1) % N;            // 次回取出し位置を更新
    V( &outSem );                   // out のロックを外す
    V( &emptySem );                 // リングバッファの空き数をインクリメント
    consume( d );                   // データを使用する
  }
}
