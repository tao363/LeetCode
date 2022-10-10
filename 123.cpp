#include <iostream>
#include <string>

using namespace std;

class A{
public: 
    //static int a;

    A() = default;
    virtual void fun(){
        cout << "hello world" << endl;
    }
    int m_a;
    int m_b;

    
};
//int A::a = 19;

int main(){
    A a;
    cout<< sizeof(A) << endl;
    cout << sizeof(int*) << endl;
    cout<< sizeof(a) << endl;
}