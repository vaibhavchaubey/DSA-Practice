class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size() < 26){
            return false;
        }
        unordered_map<char,int> mp;
        for(int i = 0; i < sentence.size(); i++){
            mp[sentence[i]] += 1;
        }
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(mp[ch] == 0){
                return false;
            }
        }
        return true;
    }
};