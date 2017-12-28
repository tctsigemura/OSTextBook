// メッセージキュー(リンク)を作成しメッセージを送信するプログラム
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
