//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        pq.push({0,{src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        int mini = INT_MAX;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int k = it.first;
            int node = it.second.first;
            int val = it.second.second;
            if(k > K) {
                continue;
            }

            for(auto a: adj[node]) {
                int adjNode = a.first;
                int adjDist = a.second;
                if(adjDist + val < dist[adjNode]) {
                    if(k <= K) {
                        pq.push({k + 1, {adjNode, adjDist + val}});
                        dist[adjNode] = adjDist + val;
                    }
                } 
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends