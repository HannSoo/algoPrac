#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Player{
  int candy;
  vector<bool> fw;
  Player(int n){
    candy = 0;
    fw = vector<bool>(n,false);
  }
};

vector<vector<int>> adj;
vector<Player> players;
vector<string> cardTypes = {"A","J","Q","K"};
vector<bool> visited;

void dfs(int here, int typ){
  cout << "DFS visits " << here << endl;
  visited[here] = true;
  int n =players.size();
  for(int i = 0; i < n; i++){
    if(here == i) continue;
    if((players[here].fw[i] == 1)&&(!visited[i])){
      dfs(i,0);
    }
  }
}

void pickCard(string card,int pInd, int N, int pick){
  int cardType = 0;
  int n = players.size();
  for(int i = 0; i < n; i++){
    if(cardTypes[i] == card){
      cardType = i;
      break;
    }
  }
  if(cardType == 0){// when A
    players[pInd].candy += 1;
    dfs(pInd,0);
  }
  if(cardType == 1){
    dfs(pInd,1);
    if(pInd != 0)
      players[pInd-1].candy += 1;
    else
      players[N - 1].candy += 1;
    if(pInd == N -1)
      players[0].candy += 1;
    else
      players[pInd + 1].candy += 1;
  }
  if(cardType == 2){
    for( auto player : players){
      player.candy += 1;
    }
  }
  else{
    players[pInd].fw[pick] = true;
  }
}
int main() {
  string n;
  cin >> n;
  int num_players = stoi(n);
  for(int i = 0; i < num_players; i++){
    players.push_back(Player(num_players));
  }
  visited = vector<bool>(num_players,false);

	return 0;
}
