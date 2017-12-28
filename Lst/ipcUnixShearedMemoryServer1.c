// 共有メモリサーバ（ipcUnixShearedMemoryServer.c）：共有メモリからデータを読みだし表示
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMSZ     512                          // 共有メモリのサイズ
int main() {
  key_t key=ftok("shm.dat",'R');               // キーを作る
  if (key==-1) {                               // エラーチェック
    perror("shm.dat");
    exit(1);
  }
  int shmid=shmget(key,SHMSZ,IPC_CREAT|0666);  // 共有メモリを作る
  if (shmid<0) {                               // エラーチェック
    perror("shmget");
    exit(1);
  }
