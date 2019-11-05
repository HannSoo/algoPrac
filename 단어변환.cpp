#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> words;
bool isAdj(string a, string b);
int targetLvl;

vector<string> bfs(string start,string target){
  int size = words.size();
  vector<bool> discovered(size, false);

  queue<string> q;
  queue<int> lvl;

  vector<string> order;
  cout << "The order is empty" << order.empty() << endl;
  q.push(start);
  lvl.push(0);
  while(!q.empty()){
    string here = q.front();
    int thisLvl = lvl.front();
    cout << "bfs visits " << here
    << "on level" << thisLvl << endl;

    if(here == target){
      targetLvl = thisLvl;
      break;
    }

    q.pop();
    lvl.pop();
    order.push_back(here);
    for(int i = 0; i< size; i++){
      if(isAdj(words[i],here))
        if(!discovered[i]){
          q.push(words[i]);
          lvl.push(thisLvl + 1);
          discovered[i] = true;
        }
      }
  }
  return order;
}

bool isAdj(string a, string b){
    int status = 0;
    int size =a.size();
    if(size!= b.size()) return false;
    for(int i = 0 ; i < size; i++){
        if(a[i] != b[i])
          status += 1;
        if(status > 1) break;
    }
    return (status == 1)? true : false;
}

int solution(string begin, string target, vector<string> words) {
    vector<string> answer;
    answer = bfs(begin,target);
    for(auto stage : answer){
      cout << stage << ' ';
    }
    cout << endl;
    return targetLvl;
}

int main(){

  cout << solution("hit","cog",{"hot","dot","dog", "lot", "log", "cog"}) << endl;
  return 0;
}
