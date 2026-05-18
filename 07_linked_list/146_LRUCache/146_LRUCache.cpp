#include <cstddef>
#include <unordered_map>

using std::unordered_map;

class LRUCache {
public:
    LRUCache(int capacity) {
        Node *nPrev = dummy_head, *nAfter = dummy_tail;
        nPrev->after = nAfter;
        nAfter->prev = nPrev;
        
        cur_capacity = 0;
        max_capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            auto cur  = mp.find(key);
            cur->second->after->prev = cur->second->prev;
            cur->second->prev->after = cur->second->after; // 维护了节点

            // 头插法
            cur->second->after = dummy_head->after;
            dummy_head->after->prev = cur->second;
            dummy_head->after = cur->second;
            cur->second->prev = dummy_head;

            return mp[key]->value;
        }
        else 
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // 首先查找，找到key就更新位置和值
        if(mp.find(key) == mp.end())  // 如果没找到
        {
            // 判断是不是要新建节点
            if(cur_capacity < max_capacity)  // 是
            {
                Node *cur = new Node(key,value);

                cur->after = dummy_head->after;
                dummy_head->after = cur;
                cur->after->prev = cur;
                cur->prev = dummy_head;

                mp[key] = cur; // 加入 map

                cur_capacity++;
            }
            // 如果相等
            else if(cur_capacity == max_capacity)
            {
                // 移除 map 中的旧映射
                mp.erase(dummy_tail->prev->key);

                // 首先移除最后一个节点
                dummy_tail->prev = dummy_tail->prev->prev;
                dummy_tail->prev->after = dummy_tail;  // 逻辑移除完毕
                // 新建节点插入队头
                Node *cur = new Node(key,value);

                cur->after = dummy_head->after;
                dummy_head->after = cur;
                cur->after->prev = cur;
                cur->prev = dummy_head;

                // 增加新映射
                mp[key] = cur; // 加入 map
            }
        }
        // 如果找到了 找到了就要先用一个节点接住当前节点 1。维持链表顺序 2。将该节点插入头结点
        else 
        {
            auto cur  = mp.find(key);
            cur->second->value = value;

            cur->second->after->prev = cur->second->prev;
            cur->second->prev->after = cur->second->after; // 维护了节点

            // 头插法
            cur->second->after = dummy_head->after;
            dummy_head->after->prev = cur->second;
            dummy_head->after = cur->second;
            cur->second->prev = dummy_head;
        }

        
    }

    struct Node
    {
        Node *prev, *after;
        int key, value;

        Node(int _key, int _value)
        :key(_key)
        ,value(_value)
        ,prev(nullptr)
        ,after(nullptr)
        {
            
        }
    };

    Node *dummy_head = new Node(0, 0);
    Node *dummy_tail = new Node(0, 0);

    // 声明一个 unordered_map 作为查询 k 及地址的东西
    unordered_map<int, Node*> mp;

    // 是不是需要一个 cur_capacity、一个 max_capacity
    int cur_capacity, max_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//  for(int i = 0; i < capacity; i++)
//         {
//             Node *cur = new Node(0, 0);
//             nPrev->after = cur;
//             cur->prev = nPrev;
//             cur->after = nAfter;
//             nAfter->prev = cur;

//             nPrev = nPrev->after; // 更新指针
//         }  // 初始化完毕