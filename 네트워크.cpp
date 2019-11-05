#include <string>
#include <vector>
#include <iostream>

using namespace std;
// never_visited : 방문하지 않은 곳들
//computers : 주어진네트워크
vector<bool> visited;

void dfs(int here,int n,vector<vector<int>> computers){
  cout << "DFS visits " << here << endl;
  visited[here] = true;
  for(int i = 0; i < n; i++){
    if(here == i) continue;
    if((computers[here][i] == 1)&&(visited[i] == false)){
      dfs(i,n,computers);
    }
  }
}
int solution(int n, vector<vector<int>> computers) {
    visited = vector<bool>(n,false);
    int num_networks = 0; // 네트워크의 숫자
    int index = 0;
    while(index < n){
      if(visited[index] == false) {
        dfs(index,n,computers);
        num_networks += 1;
      }
      index += 1;
    }
    return num_networks;
}

int main(){
  cout << solution(3,{{1,1,0},{1,1,0},{0,0,1}}) << endl;
  cout << solution(3,{{1,1,0},{1,1,1},{0,1,1}}) << endl;

  return 0;
}
