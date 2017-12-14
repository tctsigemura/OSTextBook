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
