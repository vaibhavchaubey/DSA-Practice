class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> maxCount(26,0);
        for(auto word : words2){
            vector<int> cur(26,0);
            for(auto c : word){
                cur[c-'a']++;
                maxCount[c-'a'] = max(maxCount[c-'a'],cur[c-'a']);
            }
        }
        
        for(auto word : words1){
            vector<int> cur(26,0);
            for(auto c : word){
                cur[c-'a']++;
            }
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(cur[i] < maxCount[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};





//OR

// class Solution {
// public:
//     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
//         vector<string> ans;
//         vector<int> maxCount(26,0);
//         for(auto word : words2){
//             vector<int> cur(26,0);
//             for(auto c : word){
//                 cur[c-'a']++;
//             }
//             for(int i = 0; i < 26; i++){
//                 maxCount[i] = max(maxCount[i],cur[i]);
//             }
//         }
        
//         for(auto word : words1){
//             vector<int> cur(26,0);
//             for(auto c : word){
//                 cur[c-'a']++;
//             }
//             bool flag = true;
//             for(int i = 0; i < 26; i++){
//                 if(cur[i] < maxCount[i]){
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag){
//                 ans.push_back(word);
//             }
//         }
        
//         return ans;
//     }
// };