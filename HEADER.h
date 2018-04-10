#include <string.h>

boolean isDelay(String input){
  if ((input[0]=='d')&&(input[1]=='e')&&(input[2]=='l')&&(input[3]=='a')&&(input[4]=='y')){
    return true;
  } else {
    return false;
  }
}

//mencari nilai delay dari string input delay XXX atau d XXX
int ParseDelay(String input){
  int i,j;
  char c[10];
  if (isDelay(input)){ //input = delay XXX
    i=6;
    j=0;
    while (i<input.length()){
      c[j]=input[i];
      j++;
      i++;
    }
    c[j]='\0';
  } else { //input = d XXX
    i=2;
    j=0;
    while (i<input.length()){
      c[j]=input[i];
      j++;
      i++;
    }
    c[j]='\0';
  }
  return atoi(c);
}
