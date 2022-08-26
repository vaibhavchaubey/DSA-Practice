class Solution {
public:
    string sortStr(int n){
        string t = to_string(n);
        sort(t.begin(), t.end());
        return t;
    }
    // the idea is to sort `n` and compare all sorted power of two
    // if they are matched, then it means they can be reordered to each other
    bool reorderedPowerOf2(int n) {
        string s = sortStr(n);
        for(int i = 0; i < 30; i++){
            // power of 2 = 1 << i
            // we sort each power of 2 string
            string t = sortStr(pow(2,i));         //OR string t = sortStr(1 << i);  
            
            if(s == t){
                return true;
            }
        }
        
        return false;
    }
};