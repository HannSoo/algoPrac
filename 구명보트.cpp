#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer= 0;
    int size=  people.size();
    int end = size - 1;
    int begin= 0;
    int minW,maxW;
    sort(people.begin(),people.end());
    while(begin < end){
      minW = people[begin];
      maxW = people[end];
      if(minW + maxW < limit){
        answer += 1;
        begin += 1;
        end -=1;
      }
      else{
        answer += 1;
        end -= 1;
      }
    }
    if(begin == end){
      answer += 1;
    }
    return answer;
}

int main(){
  int answer = solution({70,80,50,50},100);
  cout << answer;
}
