#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M ;
    cin >> N >> M;
    vector<vector<int>> nodes;
    int a, b, c;
    for(int i = 0; i < M; ++i){
        cin >> a >> b >> c;
        if (a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        nodes.push_back({a,b,c});
    }
    int begin, end;
    cin >> begin >> end;
    if(begin > N or end > N){
        return -1;
    }
    if(begin == end) return 0;
    if(begin > end){
        int tmp = begin;
        begin = end;
        end = tmp;
    }
    
    sort(nodes.begin(), nodes.end(),[](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });
    vector<int> ss(N,INT_MAX);
    int local = 0;
    for(int i = 0; i < M; ++i){
        if(begin == nodes[i][0]){
            local = i;
            break;
        }
    }
    ss[0] = 0;
    for(int i = local; i < M; ++i){
        if(ss[nodes[i][0]] < INT_MAX ){
            ss[nodes[i][1]] = nodes[i][2] + ss[nodes[i][0]];
        }
    }
    return 0;
}

int fun(){
    string s;
    cin >>s;
    //还原
    int num = 0;
    for(int i = 1; i< s.size(); ++i){
        if(s[i] == ':' and s[i-1] == ':'){
            num++
        }
    }
}
