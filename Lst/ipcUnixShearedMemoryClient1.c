// 共有メモリクライアント（ipcUnixShearedMemoryClient.c）：共有メモリにデータを書き込む
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMSZ     512                     // メモリのサイズ
int main() {
  int     shmid;
  key_t   key;
  char   *data, *s;
  if ((key=ftok("shm.dat",'R')) == -1) {  // サーバ側と同じキーを作る
    perror("shm.dat");
    exit(1);
  }
