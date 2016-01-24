class LRUCache {
public:
    struct Entry {
        int key;
        int value;
        Entry(int x, int y) : key(x), value(y) {}
    };
    
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (m_map.find(key) == m_map.end()) return -1;
        moveToHead(key);
        return m_map[key] -> value;
    }
    
    void set(int key, int value) {
        if (m_map.find(key) == m_map.end()) {
            Entry newItem(key, value);
            if (m_cache.size() >= m_capacity) {
                m_map.erase(m_cache.back().key);
                m_cache.pop_back();
            }
            m_cache.push_front(newItem);
            m_map[key] = m_cache.begin();
        } else {
            m_map[key] -> value = value;
            moveToHead(key);
        }
    }
private:
    int m_capacity;
    list<Entry> m_cache;
    unordered_map<int, list<Entry>::iterator> m_map;
    void moveToHead(int key) {
        Entry cur = *m_map[key];
        m_cache.erase(m_map[key]);
        m_cache.push_front(cur);
        m_map[key] = m_cache.begin();
    }
};
