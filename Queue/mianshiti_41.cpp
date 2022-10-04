#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */

    MovingAverage(int size) {
        m_size = size;
        Sum = 0;
    }
    
    double next(int val) {
        que.push(val);
        Sum += val;
        if(que.size() > m_size){
            int tmp = 0;
            tmp = que.front();
            que.pop();
            Sum -= tmp;
        }
        return Sum/(que.size());   
    }
private:
    int m_size;
    queue<int> que;
    double Sum ;
};
