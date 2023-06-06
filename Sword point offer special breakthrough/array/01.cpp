#include <iostream>

using namespace std;

//正数的取值范围要比负数的取值范围小，因此从负数转到正数可能导致溢出，因此先要将所有的数都转成负数，然后在进行计算。
class Solution {
public:
    int divide(int a, int b) {
        if(b == 0){
            return errno;
        }
        if(a == INT_MIN && b == -1){
            return INT_MAX;
        }
        bool positive = true;
        if(a > 0){
            positive = !positive;
            a = -a;
        }
        if(b > 0){
            positive = !positive;
            b = -b;
        }
        unsigned int res = div(a,b);
        return positive? res : -res;
    }
    //保证传入的数据是负数
    unsigned int div(int a, int b){
        int res = 0;
        while(a <= b){
            int tmp = b;
            unsigned int count = 1;
            while(tmp >= 0xc0000000 && a <= tmp + tmp){// 0xc0000000 * 2 = 0x80000000,即最小int型负数的一半
                count += count;
                tmp += tmp;
            }
            res += count;
            a -= tmp;
        }
        return res;
    }
};

int main(){
    class Solution so;
    cout << so.divide(15,2);
    return 0;
}

