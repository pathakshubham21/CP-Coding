// Problem statement
// You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

// Your task is to find if the graph contains a cycle or not.

// A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

// Example :

// In the below graph, there exists a cycle between vertex 1, 2 and 3. 
// Example

// Note:

// 1. There are no parallel edges between two vertices.

// 2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

// 3. The graph can be disconnected.
// For Example :

// Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
// Output: Yes

// Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 5000
// 0 <= M <= min(5000, (N * (N - 1)) / 2)
// 1 <= edges[i][0] <= N 
// 1 <= edges[i][1] <= N 

// Time Limit: 1 sec 
// Sample Input 1:
// 1
// 3 2
// 1 2
// 2 3
// Sample output 1:
// No




#include <iostream>
#include <vector>

using namespace std;

// Union-Find data structure
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

        // Union by rank
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

// Function to check if the graph contains a cycle
string containsCycle(int n, vector<pair<int, int>>& edges) {
    UnionFind uf(n + 1); // Creating a Union-Find instance

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (!uf.unionSets(u, v)) {
            return "Yes"; // Cycle detected
        }
    }

    return "No"; // No cycle detected
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<pair<int, int>> edges(M);
        for (int i = 0; i < M; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }

        cout << containsCycle(N, edges) << endl;
    }

    return 0;
}
