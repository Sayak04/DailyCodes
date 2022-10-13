//{ Driver Code Starts
    import java.util.*;
    import java.lang.*;
    import java.io.*;
    class GFG
    {
        public static void main(String[] args) throws IOException
        {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int T = Integer.parseInt(br.readLine().trim());
            while(T-->0)
            {
                String[] s = br.readLine().trim().split(" ");
                int V = Integer.parseInt(s[0]);
                int E = Integer.parseInt(s[1]);
                ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
                for(int i = 0; i < V; i++)
                    adj.add(i, new ArrayList<Integer>());
                for(int i = 0; i < E; i++){
                    String[] S = br.readLine().trim().split(" ");
                    int u = Integer.parseInt(S[0]);
                    int v = Integer.parseInt(S[1]);
                    adj.get(u).add(v);
                }
                Solution obj = new Solution();
                int ans = obj.findMotherVertex(V, adj);
                System.out.println(ans);
           }
        }
    }
    // } Driver Code Ends

    // Question:- Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
    // A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

    /* Solution:-
     *  We loop through the adjacency list and check if we can traverse all the nodes, if yes we return else go on to the starting of the next node.
     */
    
    
    
    
    class Solution
    {
        private void dfs(int[] vis, ArrayList<ArrayList<Integer>> adj, int node) {
            vis[node] = 1;
            for(Integer it : adj.get(node)) {
                if(vis[it] != 1)
                    dfs(vis, adj, it);
            }
        }
        //Function to find a Mother Vertex in the Graph.
        public int findMotherVertex(int V, ArrayList<ArrayList<Integer>>adj)
        {
            for(int i = 0; i < adj.size(); i++) {
                int[] vis = new int[V];
                dfs(vis, adj, i);
                boolean found = true;
                for(int j = 0; j < V; j++) {
                    if(vis[j] == 0) {
                        found = false;
                        break;
                    }
                }
                if(found == true) return i;
            }
            return -1;
        }
    }