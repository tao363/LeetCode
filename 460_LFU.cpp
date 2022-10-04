#include<iostream>
#include <vector>
#include<string>
#include<list>
#include <unordered_map>
using namespace std;
/*
    为了实现从key到value和freq的查找速度为O(1)，使用hash_table进行存储
    同时为了快速找到使用频率最小的，将使用hash_table和list进行结合（键值为key， value为存储键值的value组成的链表）
*/
class LFUCache {
private:
	//key  到 val  的映射，
	unordered_map<int, int> keyToVal;
	//key  到  freq  的映射
	unordered_map<int, int> keyToFreq;
	// freq 到 key 的映射
	unordered_map<int, list<int>> freToKeys;
	int minFreq;            //当添加或者获取的时候可能会进行修改
	int cap;                //包含的数据的总量
public:
	LFUCache(int capacity):cap(capacity) {
		minFreq = 0;
	}

	int get(int key);

	void put(int key, int value);

	void increaseFreq(int key);
	void removeMinFreq();
};
void LFUCache::increaseFreq(int key) {
	//  key-> freq增加频率
	int freq = keyToFreq[key];
	keyToFreq[key] += 1;
	//将频率对应的键值进行修改
	freToKeys[freq].remove(key);
	if (freToKeys[freq].empty()) {
		freToKeys.erase(freq);
		if (freq == minFreq) minFreq++;
	}
	freToKeys[freq + 1].push_back(key);
}
void LFUCache::removeMinFreq() {
	list<int> List = freToKeys[minFreq];
	int deletedKey = List.front();
	List.pop_front();
	freToKeys[minFreq] = List;
	if (List.empty()) {
		freToKeys.erase(minFreq);
	}
	keyToVal.erase(deletedKey);
	keyToFreq.erase(deletedKey);
}
int LFUCache::get(int key) {
	if (keyToVal.count(key)) {
		increaseFreq(key);
		return keyToVal[key];
	}
	return -1;
}
void LFUCache::put(int key, int value) {
	if (cap <= 0) return;
	//存在key
	if (keyToVal.count(key)) {
		keyToVal[key] = value;
		increaseFreq(key);
		return;
	}
	//不存在key
	if (cap <= keyToVal.size()) {//已满
		removeMinFreq();
	}
    //进行存储当前的值
	keyToVal[key] = value;
	keyToFreq[key] = 1;
	freToKeys[1].emplace_back(key);
	minFreq = 1;//最小出现的频率为当前放进去的值，并为1
}
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



int main() {
	LFUCache lfu(2);
	lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
	lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
	lfu.get(1);      // 返回 1
					 // cache=[1,2], cnt(2)=1, cnt(1)=2
	lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
					 // cache=[3,1], cnt(3)=1, cnt(1)=2
	lfu.get(2);      // 返回 -1（未找到）
	lfu.get(3);      // 返回 3
					 // cache=[3,1], cnt(3)=2, cnt(1)=2
	lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
					 // cache=[4,3], cnt(4)=1, cnt(3)=2
	lfu.get(1);      // 返回 -1（未找到）
	lfu.get(3);      // 返回 3
					 // cache=[3,4], cnt(4)=1, cnt(3)=3
	lfu.get(4);      // 返回 4
					 // cache=[3,4], cnt(4)=2, cnt(3)=3
}