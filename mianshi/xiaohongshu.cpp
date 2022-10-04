#include<iostream>
#include <vector>

using namespace std;

int fun(int num){
    int ans = 0;
    while(num){
        ans++;
        num >>= 1;
    }
}

int main(){
    cout << fun(9) << endl;
}



#if 0
bool fun(const string& s1, const string& s2){
    int l1 = 0, l2 = 0;
    while(l2 < s2.size() && l1 < s1.size()){
        if(s1[l1] == s2[l2]){
            l2++;
        }
        l1++;
    }
    if(l2 == s2.size()) return true;
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<vector<string>> v(n,vector<string>(2));
    string s;
    for(int i = 0; i < n; i++){
        cin >>s;
        v[i][0] = s;
        cin >> s;
        v[i][1] = s;
    }
    for(auto& ss : v){
        bool flag = fun(ss[0], ss[1]);
        if(flag){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}
#endif