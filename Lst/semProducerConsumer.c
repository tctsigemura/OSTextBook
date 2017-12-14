Data      buffer[N];                // スレッド間で共有するリングバッファ
Semaphore emptySem = N;             // リングバッファの空きスロット数を表すセマフォ
Semaphore fullSem  = 0;             // リングバッファの使用中スロット数を表すセマフォ
void producerThread() {             // 生産者スレッド
  int in = 0;                       // リングバッファの次回格納位置
  for ( ; ; ) {                     // 生産者スレッドは以下を繰り返す
    Data d = produce();             // 新しいデータを作る
    P( &emptySem );                 // リングバッファの空き数をデクリメント
    buffer[ in ] = d;               // リングバッファにデータを格納
    in = (in + 1) % N;              // 次回格納位置を更新
    V( &fullSem );                  // リングバッファのデータ数をインクリメント
  }
}
void consumerThread() {             // 消費者スレッド
  int out = 0;                      // リングバッファの次回取り出し位置
  for ( ; ; ) {                     // 消費者スレッドは以下を繰り返す
    P( &fullSem );                  // リングバッファのデータ数をデクリメント
    Data d = buffer[ out ];         // リングバッファからデータを取り出す
    out = (out + 1) % N;            // 次回取出し位置を更新
    V( &emptySem );                 // リングバッファの空き数をインクリメント
    consume( d );                   // データを使用する
  }
}
