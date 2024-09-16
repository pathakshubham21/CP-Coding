// Problem statement
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V-1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 5 8
// 0 1
// 0 4
// 1 2
// 2 0
// 2 4
// 3 0
// 3 2
// 4 3
// Sample Output 1:
// 1 


#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and mark all the islands in the same connected group
void dfs(int island, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[island] = true;

    for (int neighbor : adjList[island]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

// Function to count the number of connected groups of islands
int countConnectedGroups(int V, vector<vector<int>>& adjList) {
    vector<bool> visited(V, false);
    int connectedGroups = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited);  // Perform DFS for each unvisited island
            connectedGroups++;  // Each DFS represents one connected group
        }
    }

    return connectedGroups;
}

int main() {
    int V, E;
    cin >> V >> E;

    // Initialize adjacency list for the graph
    vector<vector<int>> adjList(V);

    // Input the connections (edges) between islands
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);  // Since the graph is undirected
    }

    // Count the number of connected groups of islands
    int result = countConnectedGroups(V, adjList);

    // Output the result
    cout << result << endl;

    return 0;
}
