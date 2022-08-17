class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_set<string> set;
        for(auto i : words){
            string s = "";
            for(auto it : i){
                s += arr[it-'a'];
            }
            set.insert(s);
        }
        
        return set.size();
    }
};