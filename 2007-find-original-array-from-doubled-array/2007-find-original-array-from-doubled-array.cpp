class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        int n = changed.size();
        multiset<int> s;
        vector<int> v;
        for(int i=0;i<n;i++){
            int num = changed[i];
            if(num%2==0 && s.find(num/2)!=s.end()){
                s.erase(s.find(num/2));   
            }
            else{
                s.insert(num);
                v.push_back(num);
            }
        }
        if(v.size()*2==changed.size())
        return v;
        else return {};
    }
};