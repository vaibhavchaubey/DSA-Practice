class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        int maxLen = 0;
        unordered_set<char> set;
        int l = 0;
        for(int r = 0; r < n; r++){  
            if(set.find(s[r]) != set.end()){
                while(l < r && set.find(s[r]) != set.end()){
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

// Time Complexity: O( 2*N ) (sometimes left and right both have to travel complete array)
// Space Complexity: O(N) where N is the size of HashSet taken for storing the elements