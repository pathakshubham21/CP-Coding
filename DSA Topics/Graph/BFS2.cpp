// Problem statement
// Given an undirected and disconnected graph G(V, E), print its BFS traversal.

// Note:

// 1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
// 2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 3. E is the number of edges present in graph G.
// 4. Take graph input in the adjacency matrix.
// 5. Handle for Disconnected Graphs as well
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
// 0 1 3 2


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& matrix, vector<int>& isVisited, int n) {
    queue<int> q;
    vector<int> result;

    // Start BFS from the first unvisited node
    for (int startNode = 0; startNode < n; startNode++) {
        if (!isVisited[startNode]) {
            q.push(startNode);
            isVisited[startNode] = 1;

            while (!q.empty()) {
                int front = q.front();
                q.pop();
                result.push_back(front);

                // Iterate over all adjacent vertices of the dequeued vertex
                for (int i = 0; i < n; i++) {
                    if (matrix[front][i] == 1 && !isVisited[i]) {
                        q.push(i);
                        isVisited[i] = 1;
                    }
                }
            }
        }
    }

    // Output the BFS traversal
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 0) return 0;

    // Initialize an n x n adjacency matrix
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    // Read the m edges
    for (int i = 0; i < m; i++) {
        int row, col;
        cin >> row >> col;
        matrix[row][col] = 1;
        matrix[col][row] = 1; // Since it's an undirected graph
    }

    // Visited array to track visited nodes
    vector<int> isVisited(n, 0);

    // Perform BFS traversal
    bfs(matrix, isVisited, n);

    return 0;
}
