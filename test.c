#include <stdio.h>
#define MAX 100
#define MIN -1


int homework(int num){
 printf("해야 할 숙제가 %d 개 있어요 \n", num)
 return num*30;
}

int eat(int num){
 return 10 * num;
}

int sleep(int hour){
 int i;
 for(i=0; i<hour; i++){
  printf("쿨쿨쿨");
  }
  return hour*20;
}

int movie(int hour){
 return 20 * hour;
}

int game(int hour){
  return 10 * hour;
}

void status(){
   printf("==현재 나의 상태== \n");
   printf("stress: %5d \n", stress);
   printf("fullness: %5d \n", fullness);
   printf("happy: %5d \n", happy);
}
int main(){

 int menu;
 int homeworks;
 int hour;
 int stress = 0;
 int fullness = 0;
 int happy= 0;
 printf("==현재 나의 상태== \n");
 printf("stress: %5d \n", stress);
 printf("fullness: %5d \n", fullness);
 printf("happy: %5d \n", happy);
 whlie((stress > MIN) & (stress< MAX)){

      printf("======메뉴======");
      printf("1.homework")
      printf("2.먹기")
      printf("3.잠자기")
      printf("4.영화보기")
      printf("5.게임하기")
      printf("0.그만하기")
      scanf("%d",&menu);
       if(menu==1){
        printf("숙제가 몇개인가요?"); scanf("%d", &숙제num);
        stress+=homework()
      }
       else if(menu==2){
         printf("몇 hour을 잘까요?"); scanf("%d", = &잠잔hour);
         stress-=sleep()
       }
       else if(menu==3){
         printf("몇 hour을 잘까요?"); scanf("%d", = &음식수);
         fullness+=eat()
       }
       else if(menu==4){
         printf("몇 hour을 잘까요?"); scanf("%d", = &num);
         happy+=movie()
       }
       else if(menu==5){
         printf("몇 hour을 잘까요?"); scanf("%d", = &hour);
         happy+= game();
       }
       else if(menu == 0){
         break;
       }
       상태보기();
    }
}
