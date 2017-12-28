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
