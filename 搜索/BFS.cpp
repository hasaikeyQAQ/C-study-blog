#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;// 标记起始节点为已访问
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Visiting: " << current << endl;
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // 邻接表表示的图
    vector<vector<int>> graph = {
        {1, 2},     // 节点0
        {0, 3, 4},  // 节点1
        {0, 5},     // 节点2
        {1},        // 节点3
        {1, 5},     // 节点4
        {2, 4}      // 节点5
    };
    
    cout << "BFS traversal starting from node 0:" << endl;
    BFS(graph, 0);
    return 0;
}