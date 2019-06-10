#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int x = 1;
  int z = 0;
  char *str = (char*)malloc(sizeof(argv[1])*argc);
  //printf("%d\n", argc);
  //char *result = (char*)malloc(sizeof(argv[1])*argc);
  while (x < argc) {
    int i;
    str = argv[x];
    //printf("%s\n", str);
    //printf("%c\n", str[x]);
    for(i = 0; i < strlen(str); i++) {
      int y = (strlen(str) - (strlen(str)-z));
      //printf("%d\n", y);
      //printf("%c\n", str[y]);
      if (str[y] == 'a' || str[y] == 'e' || str[y] == 'i' || str[y] == 'o' || str[y] == 'u' || str[y] == 'A' || str[y] == 'E' || str[y] == 'I' || str[y] == 'O' || str[y] == 'U') {
        printf("%c", str[y]);
      }
      z++;
    }
    z = 0;
    x++;
  }
  printf("\n");
  return 0;
}
