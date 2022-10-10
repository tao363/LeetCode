#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int> > Pque;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(Pque.size() < k){
            Pque.push(val);
        }
        else{
            if(Pque.top() < val){
                Pque.pop();
                Pque.push(val);
            }
        }
        return Pque.top();
    }
};


