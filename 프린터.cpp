#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_last_pnt(vector<int> priorities,int last_point, int number ){
  int next_point = -1;
  int size = priorities.size();
  for (int i = 0 ; i < last_point; i ++){
    if(priorities[last_point - i - 1]  == number)
    {
     next_point = last_point - i - 1;
     return next_point;
    }
  }

  for (int i  = 0; i < size- last_point; i++){
    int index = size - i - 1; //
    if(priorities[index] == number){
      next_point = index;
      return next_point;
    }
  }
  return last_point;
}
int solution(vector<int> priorities, int location) {
    int lp = priorities[location];
    int last_point = 0;
    int same_prior = 0;
    int more_prior = 0;
    int size = priorities.size();
    for(int i = 10; i > lp; i--){
      last_point = get_last_pnt(priorities,last_point,i);
      cout << last_point << i << endl;
    }

    for( int i = 0; i < size; i++){
      if(priorities[i] > lp) more_prior ++;
      else if(priorities[i] == lp) same_prior ++;
    }

    if(last_point <= location){
       same_prior = 0;
       for(int i = last_point; i<=location; i++){
           if(priorities[i] == lp) same_prior ++;
       }
    }
    else{
       for(int i = location + 1; i < last_point; i++){
           if(priorities[i] == lp) same_prior --;
       }
    }
    return same_prior + more_prior;
}

int main(){
  cout << solution({2,1,3,2},2) << endl
  << solution({1,1,9,1,1,1},5) << endl
  <<solution({1,2,3,2,3,2,1,3},6);

}
