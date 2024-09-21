// Problem statement
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

// For printing MST follow the steps -

// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 2 <= V, E <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Input Graph

// Sample Output 1 :
// 1 2 1
// 0 1 3
// 0 3 5





#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge with source, destination, and weight
struct Edge {
    int src, dest, weight;
    
    // Comparator function to sort edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Union-Find (Disjoint Set) data structure
class UnionFind {
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    // Find function with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // Union function with union by rank
    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return false; // Cycle detected
        }
        
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

// Function to find and print MST using Kruskal's algorithm
void kruskalMST(int V, vector<Edge>& edges) {
    // Sort edges based on their weights
    sort(edges.begin(), edges.end());
    
    // Create an instance of Union-Find
    UnionFind uf(V);
    
    vector<Edge> mst;
    
    // Iterate through sorted edges and add them to MST if they don't form a cycle
    for (auto& edge : edges) {
        if (uf.unionSets(edge.src, edge.dest)) {
            mst.push_back(edge);
            if (mst.size() == V - 1) break;  // MST will have V-1 edges
        }
    }
    
    // Print the MST edges
    for (auto& edge : mst) {
        // Ensure the smaller vertex comes first
        if (edge.src > edge.dest) {
            swap(edge.src, edge.dest);
        }
        cout << edge.src << " " << edge.dest << " " << edge.weight << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    vector<Edge> edges(E);
    
    // Read all edges
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    
    // Find and print the MST using Kruskal's algorithm
    kruskalMST(V, edges);
    
    return 0;
}
