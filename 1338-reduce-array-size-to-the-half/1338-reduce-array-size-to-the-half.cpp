class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;           //element,freq
        priority_queue<int> pq;
        int cnt = 0, removed = 0;
        
        for(auto i : arr){
            mp[i]++;
        }
            
        for(auto j : mp){
            pq.push(j.second);
        }
            
        while(removed < arr.size()/2){
            removed += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};

/*
Count the frequency of each number in arr.
Use a priority queue to store the frequencies sorted.
Add the largest frequency to "removed" until we removed at least half of the elements in arr.
*/