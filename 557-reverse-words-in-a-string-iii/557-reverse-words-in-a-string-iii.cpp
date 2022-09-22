class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        string str = "";
        for(int i = 0; i < n ; i++){
            if(s[i] == ' '){
                reverse(str.begin(), str.end());
                ans += str;
                ans += " ";
                str = "";
            }
            else{
                str += s[i];
            }
        }
        reverse(str.begin(), str.end());
        ans += str;
        
        return ans;
    }
};