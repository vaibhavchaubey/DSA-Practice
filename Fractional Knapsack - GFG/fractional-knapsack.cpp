//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    bool static comp(Item a, Item b){
        double v1 = (double)a.value/(double)a.weight;
        double v2 = (double)b.value/(double)b.weight;
        
        return v1 > v2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comp);
        
        double maxValue = 0;
        for(int i = 0; i < n; i++){
            if(W >= arr[i].weight){
                maxValue += arr[i].value;
                W -= arr[i].weight;
            }
            else{
                double vw = arr[i].value/(double)arr[i].weight;
                maxValue += vw * W;
                W = 0;
                break;
            }
        }
        return maxValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends