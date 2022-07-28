class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};



//OR

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
        // if(s.size() != t.size()){
        //     return false;
        // }
//         unordered_map<char,int> mp1;
//         for(int i = 0; i < s.size(); i++){
//             mp1[s[i]]++;
//         }
        
//         unordered_map<char,int> mp2;
//         for(int i = 0; i < t.size(); i++){
//             mp2[t[i]]++;
//         }
        
//         if(mp1.size() == mp2.size()){
//             if(mp1 == mp2){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
//         else{
//             return false;
//         }
//     }
// };