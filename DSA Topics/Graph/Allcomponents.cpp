// Problem statement
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Sample Input 1:
// 4 2
// 0 1
// 2 3
// Sample Output 1:
// 0 1 
// 2 3 
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// 0 1 3 
// 2



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform DFS and find all vertices in the same connected component
void dfs(int vertex, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& component) {
    visited[vertex] = true;
    component.push_back(vertex);

    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, component);
        }
    }
}

// Function to find all connected components of the graph
vector<vector<int>> findConnectedComponents(int V, vector<vector<int>>& adjList) {
    vector<bool> visited(V, false);
    vector<vector<int>> components;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adjList, visited, component);
            sort(component.begin(), component.end());
            components.push_back(component);
        }
    }

    return components;
}

int main() {
    int V, E;
    cin >> V >> E;

    // Initialize adjacency list for the graph
    vector<vector<int>> adjList(V);

    // Input the edges of the graph
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);  // Since the graph is undirected
    }

    // Find connected components
    vector<vector<int>> components = findConnectedComponents(V, adjList);

    // Print each connected component
    for (const vector<int>& component : components) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
