#include <iostream>
#include <vector>

using namespace std;

int idleEnergy = 1;  
int singleTaskEnergy = 3; 
int multiTaskEnergy = 4;  

int calculateEnergy(vector<vector<int>> tasks) {
    int energy = 0;
    int currentTask = 0;
    
    int time = 0;  // 当前时间片
    while (time < tasks.size()) {
        if (currentTask == 0) energy += idleEnergy;   
        else energy += singleTaskEnergy;   
        
        if (tasks[time][0] == time) {  // 有新任务启动
            if (currentTask == 0) currentTask++;   
            else energy += multiTaskEnergy; // 状态切换消耗
            
            if (tasks[time][1] > time) {  // 任务还未结束
                energy += (tasks[time][1] - time) * multiTaskEnergy; 
                time = tasks[time][1];
            } 
        } else if (currentTask > 0 && tasks[time][1] == time) { // 有任务结束
            energy += (currentTask - 1) * singleTaskEnergy;  
            currentTask--;
        } 
        time++;
    }
    return energy;
}

int main() {
    // 任务列表,每个任务由起始时间片和结束时间片定义
    vector<vector<int>> tasks = { {2,5}, {8, 9} }; 
    int energy = calculateEnergy(tasks);
    cout << energy << endl;  // 输出总能耗:197
}