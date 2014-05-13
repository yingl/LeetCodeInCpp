class LRUCache{
public:
  LRUCache(int capacity) {
    _capacity = capacity;
  }
    
  int get(int key) {
    if (cache_map.find(key) != cache_map.end()) {
      // 把节点移动到最前，同时更新cache_map[key]的位置。
      cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
      cache_map[key] = cache_list.begin();

      return cache_map[key]->_value;
    }
    else {
      return -1;
    }
  }
    
  void set(int key, int value) {
    if (cache_map.find(key) == cache_map.end()) {
      // 找不到key
      if (cache_list.size() == _capacity) {
        // 客满，删除尾部节点，访问最少。
        cache_map.erase(cache_list.back()._key);
        cache_list.pop_back();
      }

      cache_list.push_front(_Node(key, value));
      cache_map[key] = cache_list.begin();
    }
    else {
      // 更新节点值和map对应位置
      cache_map[key]->_value = value;
      cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
      cache_map[key] = cache_list.begin();
    }
  }

protected:
  struct _Node {
    int _key;
    int _value;
    _Node(int key, int value) : _key(key), _value(value) {}
  };

  int _capacity;
  list<_Node> cache_list;
  map<int, list<_Node>::iterator > cache_map;
};