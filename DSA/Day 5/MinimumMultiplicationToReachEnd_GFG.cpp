//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> que;
        que.push({0, start});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        while(!que.empty()) {
            int node = que.front().second;
            int val = que.front().first;
            que.pop();
            if(node == end) return val;

            for(int i = 0; i < arr.size(); i++) {
                int newNode = (node * arr[i]) % 100000; 
                if(dist[newNode] > val + 1) {
                    dist[newNode] = val + 1;
                    que.push({val + 1, newNode});
                }
            }
        }

        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends