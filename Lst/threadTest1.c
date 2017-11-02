#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 1000                                // １スレッドの担当データ数
#define M 10                                  // スレッド数
pthread_t tid[M];                             // M個のスレッドのスレッドID
pthread_attr_t attr[M];                       // M個のスレッドの属性
int a[M*N];                                   // このデータの合計を求める
int total[M];                                 // 各スレッドの求めた部分和
typedef struct { int no, min, max; } Args;    // スレッドに渡す引数の型定義

void *thread(void *arg) {     // 自スレッドの担当部分のデータの合計を求める
  Args *args = arg;                           // m番目のスレッド
  int sum = 0;                                // 合計を求める変数
  for (int i=args->min; i<args->max; i++) {   // a[N*m ... (N+1)*m] の
    sum += a[i];                              //   合計を sum に求める．
  }
  total[args->no]=sum;                        // 担当部分の合計を記録
  return NULL;                                // スレッドを正常終了する
}
