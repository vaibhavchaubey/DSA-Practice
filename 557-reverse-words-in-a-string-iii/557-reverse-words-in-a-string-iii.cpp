class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int lastSpaceIndex = -1;
        for(int i = 0; i <= n ; i++){
            if(i == n || s[i] == ' '){
                int startIndex = lastSpaceIndex + 1;
                int endIndex = i - 1;
                while(startIndex < endIndex){
                    swap(s[startIndex], s[endIndex]);
                    startIndex++;
                    endIndex--;
                }
                lastSpaceIndex = i;
            }
        }
        
        return s;
    }
};





//OR

// class Solution {
// public:
//     string reverseWords(string s) {
//         string ans = "";
//         int n = s.size();
//         string str = "";
//         for(int i = 0; i < n ; i++){
//             if(s[i] == ' '){
//                 reverse(str.begin(), str.end());
//                 ans += str;
//                 ans += " ";
//                 str = "";
//             }
//             else{
//                 str += s[i];
//             }
//         }
//         reverse(str.begin(), str.end());
//         ans += str;
        
//         return ans;
//     }
// };