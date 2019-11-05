#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

vector<int> solution(int size, vector<string> insects){
  vector<int> answer = {0, 0, 0};
  unordered_map<string,int> insect;
  for(int i = 0; i < size; i++){
    insect[insects[i]] += 1;
  }

  int num_types = 0;
  bool lessOne = false;
  // 곤충 카드 종류 세기
  for(auto type_insect : insect){
    num_types += 1;
  }
  // 그냥 카드 장수만 봐도 안될것 같을때
  if( ((size + 1) % num_types) != 0){
    answer = {0, size, num_types};
    return answer;
  }

  else{
    int n = (size + 1) / num_types;
    for(auto type_insect : insect){
      if(type_insect.second != n){
        if((type_insect.second == n-1) & (lessOne == false))
          lessOne = true;
        else{
          answer = {0, size, num_types};
          return answer;
        }
      }
    }
    if(lessOne){
      answer = {1, size + 1, num_types};
      return answer;
    }
    else
      return {0, size, num_types};
  }
}
int main() {

  int N;
  string n;
  getline(cin,n);
  vector<string> insects(1000);
  N = stoi(n);

  for(int i = 0; i < N; i++){
    cin >> insects[i];
  }



  vector<int> answer = solution(N,insects);
  string b;
  if(answer[0])
    b = "Y";
  else b = "N";

  cout << b << endl
      << answer[1] << endl
      << answer[2] << endl;


	return 0;
}
