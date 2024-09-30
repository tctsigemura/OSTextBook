// メッセージ受信プログラム（ipcUnixMessageReader）：メッセージキューから受信する
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "ipcUnixMessage.h"
int main() {
  struct msgBuf buf;
  int msqid;
  key_t key;
  if ((key=ftok("msgq.dat",'b'))==-1) {       // 送信側と同じキーを作る
    perror("ftok");
    exit(1);
  }
  if ((msqid=msgget(key,0644))==-1) {         // ipcUnixMessageWriter が作った
    perror("msgget");                         //  メッセージキューを取得
    exit(1);
  }
  printf("ready to receive messages.\n");
  for(;;) {
    if (msgrcv(msqid,&buf,MAXMSG,0,0)==-1) {  // 先頭のメッセージを読み出す
      perror("msgrcv");                       // メッセージキューが削除され
      exit(1);                                //   エラーが発生したら終了
    }
    printf("%ld:%s",buf.mtype,buf.mtext);     // 受信したメッセージを表示
  }
  exit(0);
}
