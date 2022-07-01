class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){  
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units = 0;
        //Sorting given array in descending order of numberOfUnitsPerBoxi
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        for(int i = 0; i < boxTypes.size(); i++){
            if(truckSize >= boxTypes[i][0]){
                units += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            //take the boxes equal to remaining size and add the units
            else{
                units += truckSize * boxTypes[i][1];
                break;
            }
        }
        return units;
    }
};