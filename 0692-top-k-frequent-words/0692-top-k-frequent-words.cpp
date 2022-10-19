class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> v;
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>> pq;
        for(auto s : words){
            mp[s]++;
        }
        for(auto i : mp){
            pq.push({-i.second,i.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<string> ans(pq.size());
        for(int i = pq.size()-1; i >= 0; i--){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};