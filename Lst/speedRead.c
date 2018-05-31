#include <stdio.h>

volatile char c;

int main() {
  FILE *fp = fopen("a.dat", "r");
  if (fp==NULL) {
    perror("fopen");
    return 1;
  }
  for(int i=0; i<4096*4096; i++) {
    c = fgetc(fp);
  }
  fclose(fp);
  return 0;
}
