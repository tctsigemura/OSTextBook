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
