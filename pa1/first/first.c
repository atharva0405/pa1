#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fptr;
  char *filename = argv[1];
  fptr = fopen(filename, "r");

  int numArg; //number of values in array
  fscanf(fptr, "%d", &numArg);
  int arr[numArg];
  //printf("%d\n", numArg );

  int i = 0;
  while(!feof(fptr)) {
    fscanf(fptr, "%d", &arr[i]);
    i++;
  }
  fclose(fptr);
  int a = 0; //for even array
  int b = 0; //for odd array
  i = 0;
  //printf("%d\n", arr[1]);
  for (i = 0; i < numArg; i++) {
    if ((arr[i]%2) == 0) {
      a++;
    }
    else {
      b++;
      //printf("%d\n", odd[i] );
    }
  }
  //printf("%d %d\n",a, b );
  int even[a];
  int odd[b];
  int e = 0;
  int f = 0;
  for (i = 0; i < numArg; i++) {
    if ((arr[i]%2) == 0) {
      even[e] = arr[i];
      //printf("%d\n", even[e]);
      e++;
    }
    else {
      odd[f] = arr[i];
      //printf("%d\n", odd[f]);
      f++;
    }
  }
  //printf("%d\n", even[1]);
  //printf("%d\n", odd[2]);
  //Sort even array
  i = 1;
  int j;
  for(i = 1; i < e; i++){
    for(j = i; j > 0; j--){
      if(even[j] < even[j-1]){
	       int temp = even[j];
	       even[j] = even[j-1];
	       even[j-1] = temp;
      }
    }
  }

  //Sort odd array
  for (i = 1; i < f; i++) {
    for(j = i; j > 0; j--){
      if (odd[j] > odd[j-1]) {
        int temp = odd[j];
        odd[j] = odd[j-1];
        odd[j-1] = temp;
        //i++;
      }
    }
  }

  int x = 0;
  for(x = 0; x < e; x++){
    //if(even[x] != 0) {
      printf("%d\t", even[x]);
    //}
  }

  x = 0;
  for(x = 0; x < f; x++){
    //if(odd[x] != 0) {
      printf("%d\t", odd[x]);
    //}
  }

return 0;
}
