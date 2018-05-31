#include <stdio.h>                // perrorのために必要
#include <fcntl.h>                // open のために必要
#include <unistd.h>               // close のために必要
#include <sys/mman.h>             // mmap のために必要
int main() {
  int fd;
  volatile char *p, x;
  char *fname="a.dat";
  fd = open(fname, O_RDONLY);      // 予め作成してある4KiBのファイルを開く
  if (fd<0) {
    perror(fname);
    return 1;
  }
  p = mmap(NULL,4096*4096,PROT_READ,MAP_FILE|MAP_SHARED,fd,0);
  if (p==MAP_FAILED) {
    perror("mmap");
    return 1;
  }
  close(fd);                      // マップしたらクローズして良い
  for (int i=0; i<4096*4096; i++) {
    x = p[i];
  }
  return 0;
}
