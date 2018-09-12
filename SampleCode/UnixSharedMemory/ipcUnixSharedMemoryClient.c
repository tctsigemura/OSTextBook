// 共有メモリクライアント（ipcUnixSharedMemoryClient.c）：共有メモリにデータを書き込む
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
  if ((shmid=shmget(key,SHMSZ,0666))<0) { // 共有メモリを取得する
    perror("shmget");
    exit(1);
  }
  data=shmat(shmid,NULL,0);               // 共有メモリを貼り付ける
  if (data == (char *)-1) {               // エラーチェック
    perror("shmat");
    exit(1);
  }
  printf("Enter a string: ");
  fgets(data,SHMSZ,stdin);                // 共有メモリに直接入力する
  if (shmdt(data)==-1){                   // 共有メモリをメモリ空間と
    perror("shmdt");                      //   切り離す
    exit(1);
  }
  return 0;
}
