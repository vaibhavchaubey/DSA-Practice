class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            nums1 = nums2;
        }
        else if(m != 0 && n != 0){
            int k;
            for(int i = 0; i < m; i++){
                // take first element from arr1 
                // compare it with first element of second array
                // if condition match, then swap
                if(nums1[i] > nums2[0]){
                    swap(nums1[i], nums2[0]);              
                }
            
                // then sort the second array
                // put the element in its correct position
                // so that next cycle can swap elements correctly
                int first = nums2[0];
                // insertion sort is used here
                for(k = 1; k < n && nums2[k] < first; k++){
                    nums2[k - 1] = nums2[k];
                }
                nums2[k - 1] = first;
            }
        
            for(int i = 0; i < nums2.size(); i++){
                nums1[m + i] = nums2[i];
            }
        } 
    }
};

//Time complexity: O(n*m)
//Space Complexity: O(1) 



//OR
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for(int i = 0; i < nums2.size(); i++){
//             nums1[m + i] = nums2[i];
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };

//Time complexity: O(n*log(n))+O(n)
//Space Complexity: O(1) 


