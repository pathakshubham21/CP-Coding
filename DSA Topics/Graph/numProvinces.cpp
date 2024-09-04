//   Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

// Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// Example 1:

// Input:
// [
//  [1, 0, 1],
//  [0, 1, 0],
//  [1, 0, 1]
// ]

// Output:
// 2
// Explanation:
// The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
// Example 2:
// Input:
// [
//  [1, 1],
//  [1, 1]
// ]

// Output :
// 1

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj(as a 2d vector) as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.


// Expected Time Complexity: O(V2)
// Expected Auxiliary Space: O(V)


// Constraints:
// 1 ≤ V ≤ 500
  
    void solve(int node, vector<int> adj[], vector<int>& visited) {
    visited[node] = 1;
    
    for(int i = 0; i < adj[node].size(); i++) {
        int adjacentNode = adj[node][i];
        if(!visited[adjacentNode]) {
            solve(adjacentNode, adj, visited);
        }
    }
}

int numProvinces(vector<vector<int>> adjMatrix, int V) {
    // Convert adjacency matrix to adjacency list
    vector<int> adj[V];
    
    for(int i = 0; i < V; i++) {  // Fixed loop initialization
        for(int j = 0; j < V; j++) {
            if(adjMatrix[i][j] == 1 && i != j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    vector<int> visited(V, 0);
    int count = 0;
    
    for(int i = 0; i < V; i++) {  // Fixed loop to pass the correct start node
        if(visited[i] == 0) {
            count++;
            solve(i, adj, visited);  // Pass the correct starting node
        }
    }
    
    return count;
}