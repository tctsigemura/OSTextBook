void P(Semaphore S) {
  if (S > 0) {
    S--;
  } else {
    プロセスを待ち(Waiting)状態にする;
    プロセスを S の待ち行列に追加する;
  }
}
