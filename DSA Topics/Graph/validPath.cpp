// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// You want to determine if there is a valid path that exists from vertex source to vertex destination.

// Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

// Example 1:


// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2
// Example 2:


// Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
// Output: false
// Explanation: There is no path from vertex 0 to vertex 5.
 

// Constraints:

// 1 <= n <= 2 * 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 0 <= ui, vi <= n - 1
// ui != vi
// 0 <= source, destination <= n - 1
// There are no duplicate edges.
// There are no self edges.

bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    // If the graph has only one vertex, return true if the source is the same as destination
    if (source == destination) {
        return true;
    }
    
    // Create an adjacency list to represent the graph
    std::vector<int> Adj_list[n];
    for (int i = 0; i < edges.size(); i++) {
        Adj_list[edges[i][0]].push_back(edges[i][1]);
        Adj_list[edges[i][1]].push_back(edges[i][0]);
    }

    // Perform BFS starting from the source
    std::queue<int> q;
    std::vector<bool> visited(n, false);
    
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // If we reach the destination, return true
        if (current == destination) {
            return true;
        }

        // Explore all the neighbors of the current node
        for (int neighbor : Adj_list[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    // If no path was found, return false
    return false;
}