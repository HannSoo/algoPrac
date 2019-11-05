#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Custom{
	int prior;
	int index;
	int value;
	Custom(int value) : prior(-1), index(-1), value(value) {
    }
};
// 내름차순 정렬
struct cmp{
    bool operator()(Custom t, Custom u){
        if(t.prior < u.prior){
          return true;
        }
        else if(t.prior == u.prior){
          if(t.index > u.index){
            return true;
          }
          else return false;
        }
        else
          return false;
    }
};
int main(){

  priority_queue<Custom, vector<Custom>, cmp> pq;

  return 0;

}
