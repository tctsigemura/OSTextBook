// 共有メモリサーバ（ipcUnixSharedMemoryServer.c）：共有メモリからデータを読みだし表示する
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
  char *data=shmat(shmid,NULL,0);              // 共有メモリを貼り付ける
  if (data==(char *)-1) {                      // エラーチェック
    perror("shmat");
    exit(1);
  }
  strcpy(data, "initialization...\n");         // 共有メモリに書き込む
  while(1) {                                   // 共有メモリの内容を
    printf("sheared memory:%s",data);          //   5秒に1度メモリを表示
    if (strcmp(data, "end\n") == 0) break;     //   "end"なら終了
    sleep(5);
  }
  if (shmdt(data) == -1){                      // 共有メモリをアドレス空間
    perror("shmdt");                           //   と切り離す
    exit(1);
  }
  if (shmctl(shmid, IPC_RMID, 0) == -1){       // 共有メモリを廃棄する
    perror("shmctl");
    exit(1);
  }
  return 0;
}
