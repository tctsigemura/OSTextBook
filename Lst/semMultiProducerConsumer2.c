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
