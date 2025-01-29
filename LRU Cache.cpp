class LRUCache
{
    private:
        list <int> nodes;
        unordered_map <int, int> lookup;
        unordered_map <int, list<int>::iterator> link;
        int cap;
    
        void balance(int key) 
        {
            auto it = link[key];
            nodes.erase(it);
            nodes.push_front(key);
            link[key] = nodes.begin();
        }
    
        void removeOverCapacity() 
        {
            if (nodes.size() <= cap) return;
            int rm = nodes.back();
            nodes.pop_back();
            lookup.erase(rm);
            link.erase(rm);
        }

        public:
            LRUCache(int cap) : cap(cap) {}

            int get(int key)
            {
                if(!lookup.count(key)) 
                {
                    return -1;
                }
              
                balance(key);
                return lookup[key];
            }

            void put(int key, int value)
            {
                if(lookup.count(key)) 
                {
                    balance(key);
                } 
                
                else 
                {
                    nodes.push_front(key);
                    link[key] = nodes.begin();
                    removeOverCapacity();
                }
                
                lookup[key] = value;
            }
};

// Link to the problem: https://www.geeksforgeeks.org/problems/lru-cache/1/
