class LFUCache {
    unordered_map<int,list<pair<int,int>>> freq_map;
    //It stores every key and value pair having same frequency together.
    // For example:- Frequency | Key and Value
                        // 1           {(10,100),(40,400)}
                        // 2           {(20,200)}
                        // 3           {(50,500),(60,600)}

    unordered_map<int,pair<int, list<pair<int, int>> :: iterator>> cache;
    // Will have iterator, as we have to traverse in the cache or we can say doubly linked list.
    // We use list(doubly linked list), because deletion is easy as we have access to previous and next node.
    // We do not have to travel the whole list to find the previous node, which would take upto to O(n) T.C.
    // It stores {key,(Frequency,(Key,Value))}
    // For example:- {20,(2,(20,200))}

    int minf;
    int cap;

    void insert(int key, int frequency, int value)
    {
        freq_map[frequency].push_back({key,value});
        cache[key]= {frequency, --freq_map[frequency].end()};
    }

public:
    LFUCache(int capacity) 
    {
        cap = capacity;
        minf = 0;    
    }

    int get(int key) 
    {
        auto it = cache.find(key);
        if(it != cache.end())
        {
            // This means the Key exists in the cache.
            int f = it->second.first;//We store the frequency of that Key in 'f'.
            auto iter = it->second.second;//We get the Key and Value pair address through this iterator.
            pair<int,int>kv = *iter;//In 'kv' we store the Key and Value pair through the iterator.
            freq_map[f].erase(iter);
            //Now we erase the Key and Value pair from the freq_map, to insert it into another freq_map, as its frequency will be +1 now because of the get().
            //For example:- from the above example if get(10),now moving (1,100) from 1st frequency map to 2nd frequency map, because its frequency is now '2'.

            if(freq_map[f].empty() && minf == f)
            {
                ++minf;
                // We do this because we set the minimun frequency, which helps further while removing any element.
                // Because now we directly jump to the minimum frequency map and not start from "ZERO".
                // For example:- from above example if we consider that {(10,100),(40,400)} both have been moved to higher frequency maps and now there are no      elements in the Frequency 1 map. So the minimum Frequency will be 2, so now if we want to remove any element the first criteria is to remove the minimum frequency elements, so will not go to Frequency 1 and now go directly to Frequency 2 map for deletion.
                // The " minf == f " criteria is to check if the minimum frequency matches the current frequency of the element or not.
                // For example:- from the above example if {(20,200)} moves to 3rd frequency map, then 2nd frequency map is empty but minf is still '1' and 'f' is 3, therefore the minf will not be changed.
            }

            insert(key,f+1,kv.second);//'f+1' because due to the get(), frequency increases by 1, as it is called by the get().
            return kv.second;//Returning the value.

        }    
        else return -1;
    }

    void put(int key, int value) 
    {
        if(cap <= 0)return;//Capacity of the Cache is '0', so cannot insert any element.

        auto it = cache.find(key);
        //Checking if the element already exits.
        if(it != cache.end())
        {
            //Element already exists.
            it->second.second->second = value;//Getting the value from the cache(hashmap).
            get(key);//Calling the get().
            return;
        }

        if(cap == cache.size())
        {
            //The current size of cache(hashmap) is equal to the given capacity of cache.
            //Therefore we have to remove the element with minimum frequency.
            //If there is a tie, then will remove the least recently used element(LRU).
            //That will be the first element in the minimum freq_map.
            //First will remove element from cache(hashmap) and then from the freq_map. 
            cache.erase(freq_map[minf].front().first);
            freq_map[minf].pop_front();
        }

        //Now will insert the element, minf will be 1 because by inserting an element its individual frequency will be one. So, the minimum frequency changes to 1.
        // As there is addition of a new element.  
        minf = 1;
        insert(key,1,value);//Key, Frequency, Value.
    }
};