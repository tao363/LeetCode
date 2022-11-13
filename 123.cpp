#include <iostream>
#include <cmath>
using namespace std;

#define test(t)(t*t)
int main(){
	
	int a = 3, b,c;
	b = test(a++);
	c = test(++a);
	cout << b << ' ' << c <<endl;
	
}