#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    stack<int> stk;
    stk.push(start);
    
    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();
        
        if (!visited[current]) {
            cout << "Visiting: " << current << endl;
            visited[current] = true;
            
            // 将邻接点逆序压栈（保持原始顺序）
            for (int i = graph[current].size() - 1; i >= 0; i--) {
                int neighbor = graph[current][i];
                if (!visited[neighbor]) {
                    stk.push(neighbor);
                }
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
    
    cout << "DFS traversal starting from node 0:" << endl;
    DFS(graph, 0);
    return 0;
}