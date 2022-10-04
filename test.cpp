#include <iostream>
#include <vector>


using namespace std;

int main(){
    int i = 42;
    int j = std::move(i);
    std::cout << i << endl;
    std::string s = "hello";
    std::string t = std::move(s);
    std::cout << s << endl;
}