class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        vector<long long> ways(n, 0);
        vector<long long> dist(n, 1e18);
        ways[0] = 1;
        dist[0] = 0;
        int MOD = (int)(1e9 + 7);
        
        while(!pq.empty())  {
            long long node = pq.top().second;
            long long val = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]) {
                long long adjNode = it.first;
                long long adjVal = it.second;
                if(adjVal + val < dist[adjNode]) {
                    pq.push({adjVal + val, adjNode});
                    dist[adjNode] = adjVal + val;
                    ways[adjNode] = ways[node];
                } else if(adjVal + val == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        
        return ways[n-1] % MOD;
    }
};