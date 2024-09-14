// Problem statement
// Given an undirected graph G(V,E), check if the graph G is connected graph or not.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// Sample Output 1:
// true
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// false 
// Sample Output 2 Explanation
// The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 



#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal from a given vertex
void DFS(int currentVertex, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[currentVertex] = true;

    // Explore all neighbors of the current vertex
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
            DFS(i, adjMatrix, visited);
        }
    }
}

// Function to check if the graph is connected
bool isConnectedGraph(int V, vector<vector<int>>& adjMatrix) {
    vector<bool> visited(V, false);

    // Start DFS from vertex 0 (or any vertex)
    DFS(0, adjMatrix, visited);

    // Check if all vertices were visited
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false;  // If any vertex is not visited, the graph is not connected
        }
    }

    return true;  // All vertices were visited, the graph is connected
}

int main() {
    int V, E;
    cin >> V >> E;

    // Create adjacency matrix and initialize with 0
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    // Input edges and create adjacency matrix
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
    }

    // If the graph has no vertices, it is considered connected by definition
    if (V == 0) {
        cout << "true" << endl;
    } else {
        // Check if the graph is connected
        if (isConnectedGraph(V, adjMatrix)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}
