#include <stdio.h>


int 숙제하기(){
  return 40;
}
int main(){
  int menu = 1;
  int stress = 1000;

  if(menu==1) stress =- 숙제하기();
  printf("%d,\n",stress);
}
