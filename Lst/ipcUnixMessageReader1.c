// queue_r.c : メッセージキュー(リンク)からメッセージを受信するプログラム
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
  if ((msqid=msgget(key,0644))==-1) {         // queue_w が作った
    perror("msgget");                         //  メッセージキューを取得
    exit(1);
  }
