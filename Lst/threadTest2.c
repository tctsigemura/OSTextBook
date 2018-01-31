int main() {                      // mainスレッドの実行はここから始まる
  // 擬似的なデータを生成する
  for (int i=0; i<M*N; i++) {                 // 配列 a　を初期化
    a[i] = i+1;
  }
  // M個のスレッドを起動する
  for (int m=0; m<M; m++) {                   // 各スレッドについて
    Args *p = malloc(sizeof(Args));           //   引数領域を確保
    p->no = m;                                //     m番目のスレッド
    p->min = N*m;                             //     担当範囲下限
    p->max = N*(m+1);                         //     担当範囲上限
    pthread_attr_init(&attr[m]);              //   アトリビュート初期化
    pthread_create(&tid[m],&attr[m],thread,p);//   スレッドを生成しスタート
  }
  // 各スレッドの終了を待ち，求めた小計を合算する
  int sum = 0;
  for (int m=0; m<M; m++) {                   // 各スレッドについて
    pthread_join(tid[m], NULL);               //   終了を待ち
    sum += total[m];                          //   小計を合算する
  }
  printf("1+2+ ... +%d=%d\n", N*M, sum);
  return 0;
}
