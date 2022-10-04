#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        m_max = 3000;
    }
    
    int ping(int t) {
        que.push(t);
        while(t - 3000 > que.front()){
            que.pop();
        }
        return que.size();
    }
private:
    queue<int> que;
    int m_max;
};