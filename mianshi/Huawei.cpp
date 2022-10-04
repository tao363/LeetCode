#include <iostream>
#include<vector>
#include <queue>
using namespace std;
vector<vector<int>> SS = {{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
vector<vector<int> > BB = {{1,0},{0,-1}, {-1,0},{0,1}};
int ans ;
bool flag;
// c b为兵，s为马
queue<vector<int>> que;
int m, n;
bool bfs(vector<string> &v, vector<vector<bool>> visit, int num){
    while(que.empty()){
        int size = que.size();
        ans ++;//每次执行一遍所有的队列，则相当于直接执行了一层
        if(size == 0) return false;
        for(int i = 0; i < size; ++i){
            int r = que.front()[0];
            int c = que.front()[1];
            int f = que.front()[2];
            int num = que.front()[3];
            if(r == m-1 and c == n - 1){//到达终点
                break;
            }
            if(r >= 0 and r < m and c >= 0 and c < n and !visit[r][c] and v[r][c] == '.'){
                if(v[r][c] == '.'){//不需要进行修改
                    visit[r][c] = true;
                    if(f == 0){//兵
                        for(int i = 0; i < 4; ++i){
                            que.push(vector<int>{r + BB[i][0], c + BB[i][1], 0,num+1});
                        }
                    }
                    else{//马
                        for(int i = 0; i < 8; ++i){
                            que.push(vector<int>{r + BB[i][0], c + BB[i][1], 1,num+1});
                        }
                    }
                }
                else{//到达驿站，可以进行修改
                    if(f == 0){//原来是兵
                        
                    }
                    else{//原来是马

                    }
                }
            }
            que.pop();
        }
    }
}



bool dfs(vector<string> &v, int x, int y, vector<vector<bool>>& visit, char c, int num){
    
    
    
    int count = 0;
    bool ff = false;
    if(x >= 0 and x < v.size() and y >= 0 and y < v[0].size() and !visit[x][y] and v[x][y] != 'X' ){//可以跑到
        visit[x][y] = true; //记录已经走过了
        if(x == v.size()-1 and y == v[0].size()-1){
            flag = true;
            ans = min(num, ans);
            return true;
        }
        if(v[x][y] == 'S'){ //可以进行换马
            for(int i = 0; i < SS.size(); ++i){
               ff =  dfs(v,SS[i][0]+x,SS[i][1] + y, visit, 's' ,num + (c == 's'? 1: 2));
            }
            for(int i = 0; i < BB.size(); ++i){
               ff=  dfs(v,BB[i][0]+x,BB[i][1] + y, visit, 'b' ,num + (c=='b' ? 1:2));
            }
        }
        else{
            // count = 2000;
            if(c=='s'){
                for(int i = 0; i < SS.size(); ++i){
                    ff = dfs(v,SS[i][0]+x,SS[i][1] + y, visit, 's' , num+1);
                }
            }
            else{
                for(int i = 0; i < BB.size(); ++i){
                    ff = dfs(v,BB[i][0]+x,BB[i][1] + y, visit, 'b', num + 1);
                }
            }
        }
    }
    return ff;
}


int main(){
    ans = 9000;
    flag = false;
    cin >> m >> n;
    vector<string> v(m);
    string ss;
    for(int i = 0; i < m; ++i){
        cin >> ss;
        v[i] = ss;
    }
    vector<vector<bool>> visit(m, vector<bool>(n,false));
    que.push({0,0,0,0});

    dfs(v, 0, 0, visit, 'b',0);
    if(ans < 2000) cout << ans;
    else cout << -1;
}