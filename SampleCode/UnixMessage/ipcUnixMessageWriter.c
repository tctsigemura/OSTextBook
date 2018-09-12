// メッセージ送信プログラム（ipcUnixMessageWriter.c）：メッセージキューを作成し送信する
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "ipcUnixMessage.h"                     // msgBuf 構造体の宣言
int main() {
  struct msgBuf buf;                            // メッセージ領域
  int msqid;                                    // メッセージキュー ID
  key_t key;                                    // メッセージキューの名前
  if ((key=ftok("msgq.dat",'b'))==-1) {         // ftok はファイル名から 
    perror("ftok");                             //  重複のない名前(キー)を
    exit(1);                                    //   生成する
  }
  if ((msqid=msgget(key,0644|IPC_CREAT))==-1) { // メッセージキューを作る
    perror("msgget");
    exit(1);
  }
  printf("Enter lines of text, ^D to quit:\n");
  buf.mtype = 1;                                // メッセージの型
  while (fgets(buf.mtext,MAXMSG,stdin)!=NULL) { // キーボードから１行入力
    if (msgsnd(msqid,&buf,MAXMSG,0)==-1) {      // メッセージを送信
      perror("msgsnd");
      break;
    }
  }
  if (msgctl(msqid,IPC_RMID,NULL) == -1) {      // メッセージキューを削除
    perror("msgctl");
    exit(1);
  }
  exit(0);
}
