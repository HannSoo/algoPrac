#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int size;
bool H_point_bigger_than(int n, vector<int> citations){
  return (citations[size - n] >= n);
}
int find_mid(int low, int hi, vector<int> l){
  if(low + 1 == hi) return low;
  int mid = (hi + low) / 2;
  if(H_point_bigger_than(mid,l))
    return find_mid(mid,hi,l);
  else
    return find_mid(low,mid,l);
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    size = citations.size();

    int answer = find_mid(-1,size+1,citations);
    return answer;
}
int main(){
  cout << solution({3,0,6,1,5}) << endl;
  cout << solution({8,8,8,2}) << endl;
  cout << solution({0,0,0,0}) << endl;
  return 0;
}
