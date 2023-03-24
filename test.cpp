#include<iostream>
#include<vector>
#include<string>
#include <string.h>
#include <list>

using namespace std;
/* 基于数组实现的栈 */
class ArrayStack {
private:
    vector<int> stack;

public:
    /* 获取栈的长度 */
    int size() {
        return stack.size();
    }
    /* 判断栈是否为空 */
    bool empty() {
        return stack.empty();
    }
    /* 入栈 */
    void push(int num) {
        stack.push_back(num);
    }
    /* 出栈 */
    int pop() {
        if(stack.empty()){
            throw out_of_range("栈为空,不能执行: pop()函数");
        }
        int oldTop = stack.back();
        stack.pop_back();
        return oldTop;
    }
    /* 访问栈顶元素 */
    int top() {
        if(stack.empty()){
            throw out_of_range("栈为空,不能执行: top()函数");
        }
        return stack.back();
    }
    /* 访问索引 index 处元素 */
    int get(int index) {
        if(stack.size() < index){
            throw out_of_range("超出栈空间大小");
        }
        return stack[index];
    }
};
int main(){
    ArrayStack sta;
    cout << sta.empty() << endl;
   // cout << sta.pop() << endl;
   // cout << sta.top() << endl;
   cout << sta.get(2) << endl;
}
