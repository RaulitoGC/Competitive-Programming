class RandomizedSet {
public:
    /** Initialize your data structure here. */
    list<int> l;
    unordered_map<int, list<int>::iterator> um;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        unordered_map<int,  list<int>::iterator>::iterator it = um.find(val);
        bool res = (it != um.end());
        if(!res){
            l.push_back(val);
            um[val] = --l.end();
        }
        return !res;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int,  list<int>::iterator>::iterator it = um.find(val);
        bool res = (it != um.end());
        if(res){
            l.erase(um[val]);
            um.erase(val);
        }
        return res;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(!um.empty()){
            //cout << um.size() <<" - " << rand()<< endl;
            int random = rand() % um.size() ; 
            list<int>::iterator it = l.begin();
            advance(it, random);
            return *it;
            // double target = um.size()*random;
            // cout << target << endl;    
        }
        
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
