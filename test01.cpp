#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        nums[i] = tmp;
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(nums[i]) == mp.end()) {
            mp[nums[i]] = 1;
        } else {/*  */
            mp[nums[i]]++;
        }
    }
    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans ++;
    }
    cout << ans-1 << endl;
    return 0;
}