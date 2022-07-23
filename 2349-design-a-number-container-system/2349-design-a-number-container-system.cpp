class NumberContainers {
public:
    unordered_map<int,int> mp1;
    unordered_map<int,set<int>> mp2;       //here we are storing indexes of number in sorted order to get the smallest index at top
    NumberContainers() {
    }
    
    void change(int index, int number) {
        mp1[index] = number;
        mp2[number].insert(index);
    }
    
    int find(int number) {
        if (mp2.find(number) == mp2.end())
        {
            return -1;
        }
        for(auto &it : mp2[number]){
            if(mp1[it] == number){
                return it;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */