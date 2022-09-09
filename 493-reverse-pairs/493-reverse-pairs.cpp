class Solution {
public:
    int merge(vector<int>& nums, int l, int mid, int r){
        int pairs = 0;
        int j = mid + 1;
        for(int i = l; i <= mid; i++){
            while(j <= r && nums[i] > 2LL * nums[j]){
                j++;
            }
            pairs += (j - (mid + 1));
        }
        int n1 = mid - l + 1;
        int n2 = r - mid;
        int a[n1];
        int b[n2];
        for(int i = 0; i < n1; i++){
            a[i] = nums[l+i];
        }
        for(int i = 0; i < n2; i++){
            b[i] = nums[mid+1+i];
        }
        int i = 0, k = l;
        j = 0;
        while(i < n1 && j < n2){
            if(a[i] <= b[j]){
                nums[k] = a[i];
                k++; i++;
            }
            else{
                nums[k] = b[j];
                k++; j++;
            }
        }
        while(i < n1){
            nums[k] = a[i];
            k++; i++;
        }
        while(i < n2){
            nums[k] = b[j];
            k++; j++;
        }
        
        return pairs;        
    }
    int mergeSort(vector<int>& nums, int l, int r){
        int pairs = 0;
        if(l < r){
            int mid = (l+r)/2;
            pairs += mergeSort(nums,l,mid);
            pairs += mergeSort(nums,mid+1,r);
            
            pairs += merge(nums,l,mid,r);
        }
        return pairs;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};


// Time Complexity : O( N log N ) + O (N) + O (N)   
// Reason : O(N) – Merge operation , O(N) – counting operation ( at each iteration of i , j doesn’t start from 0 . Both of them move linearly ) 

// Space Complexity : O(N) 
// Reason : O(N) – Temporary vector