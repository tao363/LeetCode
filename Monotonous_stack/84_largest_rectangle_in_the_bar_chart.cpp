#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> sta;
        int ans = 0;
        heights.push_back(-1);          //为了计算所有的值，先添加一个-1到里面，然后就可以将所有栈内的位置多计算一次
        for(int i = 0; i < heights.size(); ++i){
            while(!sta.empty() and heights[sta.top()] > heights[i]){
                int indx = sta.top();
                sta.pop();
                int weight = i;         //当只有一个的时候就说明，这个位置是前面的最小值，得到的矩形面积为所有的  宽度*栈中的数值的高度
                if(!sta.empty()){       //当栈里面还有其他的，就说明此时栈顶中的元素值小于heights[indx]的大小
                    weight = i - sta.top() - 1;
                }
                ans = max(ans, heights[indx] * weight);
            }
            sta.push(i);
        }
        return ans;
    }
};


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        unsigned long size = heights.size(); 
        stack<int> sta;
        int ans = 0;
        for(int i = 0; i < heights.size(); ++i){
            while(!sta.empty() and heights[sta.top()] > heights[i]){
                int indx = sta.top();
                sta.pop();
                int weight = i;         //当只有一个的时候就说明，这个位置是前面的最小值，得到的矩形面积为所有的  宽度*栈中的数值的高度
                if(!sta.empty()){       //当栈里面还有其他的，就说明此时栈顶中的元素值小于heights[indx]的大小
                    weight = i - sta.top() - 1;
                }
                ans = max(ans, heights[indx] * weight);
            }
            sta.push(i);
        }
        //栈内还有数据
        while(!sta.empty()){
            int length = heights[sta.top()];
            sta.pop();
            int weight = size;
            if(!sta.empty ()){          //判断栈中是否为最后一个元素
                weight = size - sta.top() - 1;
            }
            ans = max(ans, length*weight);
        }
        return ans;
    }
};

int main(){
    vector<int> v{2,4};
    Solution solution;
    cout <<  solution.largestRectangleArea(v) ;

}