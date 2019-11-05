#include <vector>
#include <iostream>

using namespace std;

vector< vector<bool> > adj;
vector<bool> visited;

void dfs(int here){
  cout << "dfs visits " << here << endl;
  visited[here] = true;
  for(int there = 0; there < adj[here].size(); there++){
    if(here == there) continue;
    if(adj[here][there] &!visited[there] ){
      dfs(there);
    }
  }
}

int solution(int n, vector<vector<int>> edges){
  adj = vector<vector<bool>>(n,vector<bool>(n,false));
  visited = vector<bool>(n,false);
  for(auto edge : edges){
    adj[edge[0]][edge[1]] = true;
    adj[edge[1]][edge[0]] = true;
  }
  dfs(0);
  return 0;
}

int main(){
    cout << solution(4,{{1,2},{1,3},{2,3},{2,4},{3,4}});

    return 0;
}
