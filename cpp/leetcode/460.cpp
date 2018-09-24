#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
public:
    int cap;
    int size;
    int min;
    unordered_map<int, pair<int, int>> map;
    unordered_map<int, list<int>::iterator> map_ptr;
    unordered_map<int, list<int>> lru;
        
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        min = 0;
    }

    int get(int key) {
        if (map.count(key) == 0) return -1;
        lru[map[key].second].erase(map_ptr[key]);
        map[key].second ++;
        lru[map[key].second].push_back(key);
        map_ptr[key] =  (--lru[map[key].second].end());

        if (lru[min].size() == 0) min++;
        return map[key].first;
    }

    void put(int key, int val) {
        if (cap <= 0) return ;
        int k = get(key);
        if (k != -1) {
            map[key].first = val;
            return ;
        }
        if (size == cap) {
            map.erase(lru[min].front());
            map_ptr.erase(lru[min].front());
            lru[min].pop_front();
            size--;
        }
        map[key] = make_pair(val, 1);
        lru[1].push_back(key);
        map_ptr[key] = (--lru[1].end());
        min = 1;
        size++;
    }
};

int main() {
    LFUCache lfu = LFUCache(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(2) << endl;
    lfu.put(3,3);
    cout << lfu.get(1) << endl;
    cout << lfu.get(3) << endl;
    return 0;
}
