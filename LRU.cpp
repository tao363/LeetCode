#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node{
public:
    int key, val;
    Node* next, * prev;
    Node(int a, int b):key(a),val(b){
        next = nullptr;
        prev = nullptr;
    }
};

class doubleList{
private:
    Node* head, *tail;
    int size;
public:
    doubleList(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addLast(Node* x){
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }
    void remove(Node* x){
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    Node* removeFirst(){
        if(head->next == tail){
            return nullptr;
        }
        Node* first = head->next;
        remove(first);
        return first;
    }
    int Size(){
        return size;
    }
};
class LRUCache {
    int cap;
    unordered_map<int, Node*> map;
    doubleList* cache;
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache = new doubleList();
    }
    void makeRecently(int key){
        Node* x = map[key];
        cache->remove(x);
        cache->addLast(x);
    }
    void addRecently(int key, int val){
        Node* x = new Node(key, val);
        cache->addLast(x);
        map[key] = x;
    }
    void deleteKey(int key){
        Node* x = map[key];
        cache->remove(x);
        map.erase(key);
    }
    void removeLastRecently(){
        Node* deleteNode = cache->removeFirst();
        int deletedKey = deleteNode->key;
        map.erase(deletedKey);
    }
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }
        makeRecently(key);
        return map[key]->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            deleteKey(key);
            addRecently(key,value);
            return ;
        }
        if(cap == cache->Size()){
            removeLastRecently();
        }
        addRecently(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */