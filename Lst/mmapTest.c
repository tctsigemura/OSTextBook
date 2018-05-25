#include <stdio.h>                // perrorのために必要
#include <fcntl.h>                // open のために必要
#include <unistd.h>               // close のために必要
#include <sys/mman.h>             // mmap のために必要
int main() {
  int fd;
  char *p, *fname="a.txt";
  fd = open(fname, O_RDWR);       // 予め作成してある4KiBのファイルを開く
  if (fd<0) {
    perror(fname);
    return 1;
  }
  p = mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);  // マップする
  if (p==MAP_FAILED) {
    perror("mmap");
    return 1;
  }
  close(fd);                      // マップしたらクローズして良い
  for (int i=0; i<4096; i++) {    // ファイルにA〜Zを繰り返し書き込む
    p[i] = 'A' + (i % 26);
  }
  return 0;
}
