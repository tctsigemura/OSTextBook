#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 1000                                    // １スレッドの担当データ数
#define M 10                                      // スレッド数
pthread_t tid[M];                                 // M個のスレッドのスレッドID
pthread_attr_t attr[M];                           // M個のスレッドの属性
int a[M*N];                                       // このデータの合計を求める
int total[M];                                     // 各スレッドの求めた部分和
typedef struct { int no, min, max; } Args;        // スレッドに渡す引数の型定義

// 自スレッドの担当部分のデータの合計を求める
void *thread(void *arg) {
  Args *args = arg;                               // m番目のスレッド
  int sum = 0;                                    // 合計を求める変数
  for (int i=args->min; i<args->max; i++) {       // a[N*m ... (N+1)*m] の
    sum += a[i];                                  //   合計を sum に求める．
  }
  total[args->no]=sum;                            // 担当部分の合計を記録
  return NULL;                                    // スレッドを正常終了する
}

int main() {
  // 擬似的なデータを生成する
  for (int i=0; i<M*N; i++) {                     // 配列 a　を初期化
    a[i] = i+1;
  }
  // M個のスレッドを起動する
  for (int m=0; m<M; m++) {                       // 各スレッドについて
    Args *p = malloc(sizeof(Args));               //   引数領域を確保
    p->no = m;                                    //     m番目のスレッド
    p->min = N*m;                                 //     担当範囲下限
    p->max = N*(m+1);                             //     担当範囲上限
    pthread_attr_init(&attr[m]);                  //   アトリビュート初期化
    pthread_create(&tid[m], &attr[m], thread, p); //   スレッドを生成しスタート
  }
  // 各スレッドの求めた小計を合算する
  int sum = 0;
  for (int m=0; m<M; m++) {                       // 各スレッドについて
    pthread_join(tid[m], NULL);                   //   終了を待ち
    sum += total[m];                              //   小計を合算する
  }
  printf("1+2+ ... +%d=%d\n", N*M, sum);
  return 0;
}
