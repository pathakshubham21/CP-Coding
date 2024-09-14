#include <iostream>
#include <vector>
// Problem statement
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

// Find the path using DFS and print the first path that you encountered.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= 2^31 - 1
// 0 <= v2 <= 2^31 - 1
// Time Limit: 1 second
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1:
// 3 0 1
// Sample Input 2:
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2:
using namespace std;



// Function to perform DFS and find path from v1 to v2
bool DFS(int currentVertex, int v2, vector<vector<int>>& adjMatrix, vector<bool>& visited, vector<int>& path) {
    visited[currentVertex] = true;
    
    // If we reach the target vertex
    if (currentVertex == v2) {
        path.push_back(v2);
        return true;
    }

    // Explore all neighbors of the current vertex
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
            if (DFS(i, v2, adjMatrix, visited, path)) {
                path.push_back(currentVertex); // Push the vertex to the path when returning back
                return true;
            }
        }
    }
    
    return false; // No path found from currentVertex to v2
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

    int v1, v2;
    cin >> v1 >> v2;

    // Vector to keep track of visited nodes
    vector<bool> visited(V, false);

    // Vector to store the path
    vector<int> path;

    // Perform DFS to find the path from v1 to v2
    if (DFS(v1, v2, adjMatrix, visited, path)) {
        // Print the path in reverse order
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
