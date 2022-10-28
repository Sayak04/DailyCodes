//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    // Memoized Solution 
    int findSum(int index, int *arr, vector<int> &dp) {
        if(index < 0) return 0;

        if(dp[index] != -1) return dp[index];

        // we can either take or not take
        // if we take
        int take = arr[index] + findSum(index - 2, arr, dp);
        // if we dont take
        int notTake = findSum(index-1, arr, dp); 

        // we take the maximum of both the values
        return dp[index] = max(take, notTake);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
        vector<int> dp(n+1, 0);
	    // Tabulation
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i = 1; i < n; i++) {
            int take = dp[i-2] + arr[i];
            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        // Space optimised
        /*
            if(n==1) return arr[0];
            int prev2 = arr[0];
            int prev = max(arr[0], arr[1]);
            for(int i = 2; i < n; i++) {
                int take = prev2 + arr[i];
                int notTake = prev;

                prev2 = prev;
                prev = max(take, notTake);
            }
            return prev;
        */
        return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends