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
