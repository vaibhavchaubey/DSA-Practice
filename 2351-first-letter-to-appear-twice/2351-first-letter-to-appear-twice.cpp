class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26);
        for(char c : s){
            v[c - 'a']++;
            if(v[c - 'a'] > 1){
                return c;
            }
        }
        return 'a';
    }
};




//OR

// class Solution {
// public:
//     char repeatedCharacter(string s) {
//         unordered_set<char> st;
        
//         for(int i = 0; i < s.length(); i++){
//             char c = s[i];
//             if(st.find(c) != st.end()){
//                 return c;
//             }
//             else{
//                 st.insert(c);
//             }
//         }
        
//         return '\0';
//     }
// };