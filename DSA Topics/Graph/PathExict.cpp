// Problem statement
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= 1000
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= V - 1
// 0 <= v2 <= V - 1
// Time Limit: 1 second
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// true
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :
// false



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>>&matrix, vector<int>&visited, int source) {
    queue<int>q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()) {
        int f = q.front();
        q.pop();

        for(int i = 0; i < matrix[f].size(); i++) {
            if(matrix[f][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>>matrix(v, vector<int>(v, 0));
    vector<int>visited(v, 0);

    // Reading `e` edges
    for(int i = 0; i < e; i++) {
        int row, col;
        cin >> row >> col;
        matrix[row][col] = 1;  // Add edge row -> col
        matrix[col][row] = 1;  // Since it's an undirected graph, add col -> row
    }

    int source, destination;
    cin >> source >> destination;

    bfs(matrix, visited, source);

    // Check if destination is visited
    if(visited[destination]) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
