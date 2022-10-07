#include <iostream>
using namespace std;
int main() {
   #ifdef _WIN64
      cout << "This is 64 bit system" << endl;
   #elif _WIN32
      cout << "This is 32 bit system" << endl;
   #endif
}