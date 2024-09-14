// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

// Find the path using BFS and print the shortest path available.

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
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// 3 0 1
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Function to perform BFS and find the shortest path from v1 to v2
vector<int> BFS(int v1, int v2, vector<vector<int>>& adjMatrix, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    unordered_map<int, int> parent;  // To store the parent of each node in the BFS tree

    // Start BFS from v1
    q.push(v1);
    visited[v1] = true;
    parent[v1] = -1;  // Mark v1 as the root

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        // If we reach the target vertex v2, we build the path using parent map
        if (currentVertex == v2) {
            vector<int> path;
            int temp = v2;
            while (temp != -1) {
                path.push_back(temp);  // Add current vertex to the path
                temp = parent[temp];   // Move to its parent
            }
            return path;  // This will be the shortest path due to BFS
        }

        // Explore all neighbors of the current vertex
        for (int i = 0; i < V; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = currentVertex;  // Set the parent of the neighbor
            }
        }
    }

    return {};  // Return empty vector if no path found
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

    // Perform BFS to find the shortest path from v1 to v2
    vector<int> path = BFS(v1, v2, adjMatrix, V);

    // If path exists, print it in reverse order
    if (!path.empty()) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
