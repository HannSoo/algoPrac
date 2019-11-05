#include <string>
#include <vector>
#include <iostream>
using namespace std;
int showVec(vector<int> v);
vector<int> divNum(int ball) {
	int a100 = (int)(ball / 100);
	int a1 = ball % 10;
	int a10 = (int)(ball - a100 * 100)/10;
	return{ a100, a10, a1 };
}
bool chkBall(int ball0, vector<int> baseball) {
	vector<int> ball = divNum(ball0);
    if(ball[0] == ball[1] |
       ball[1] == ball[2]|
      ball[2]== ball[0]) return false;
	vector<int> base = divNum(baseball[0]);
	int s = 0;
	int b = 0;
	for (int i = 0; i <3; i++) {
		if (ball[i] == base[i]) {
            s += 1;
            continue;
        }

		for (int j = 0; j <3; j++) {
			if (j == i) continue;
			if (ball[i] == base[j]) {
				b += 1;
				break;
			}
		}
	}

	if ((baseball[1] == s) & (baseball[2] == b)) return true;
	else return false;
}
int solution(vector<vector<int>> baseball) {
	int answer = 0;
	for (int j0 = 1; j0<10; j0 ++)
	 	for (int j1 = 1; j1< 10; j1++)
			for (int j2= 1; j2<10; j2++ ){
				int i = j0 * 100 + j1 * 10 + j2;
				bool suscs = true;
				for (int j = 0; j < baseball.size(); j++) {
					if (chkBall(i, baseball[j]) == false) {
						suscs = false;
						break;
					}
				}
		if (suscs == true)
			answer += 1;
	}

	return answer;
}

int showVec(vector<int> v){
	for(int i: v){
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}

int main(){
		cout << solution({{123,1,1},{356,1,0},{327,2,0},{489,0,1}});

		return 0;
}
