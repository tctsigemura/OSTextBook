void V(Semaphore S) {
  if (S の待ち行列は空) {
    S++;
  } else {
    一つのプロセスを待ち行列から取り出す;
    そのプロセスを実行可能(Ready)状態にする;
  }
}
