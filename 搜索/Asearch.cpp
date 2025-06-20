#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Node {
    int x, y;       // 坐标
    double g, h;    // g=实际代价, h=启发式估值
    Node* parent;   // 路径回溯
    
    Node(int x, int y, double g=0, double h=0, Node* parent=nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}
    
    double f() const { return g + h; }  // 总估值
};

// 比较函数（优先队列使用）
struct CompareNode {
    bool operator()(const Node* a, const Node* b) {
        return a->f() > b->f();
    }
};

// 欧几里得距离启发式函数
double heuristic(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

vector<Node*> aStarSearch(vector<vector<int>>& grid, Node* start, Node* goal) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    
    // 方向向量：上、右、下、左
    vector<pair<int, int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    // 开放列表（优先队列）
    priority_queue<Node*, vector<Node*>, CompareNode> openSet;
    // 关闭列表（二维数组）
    vector<vector<bool>> closedSet(rows, vector<bool>(cols, false));
    
    start->h = heuristic(start->x, start->y, goal->x, goal->y);
    openSet.push(start);
    
    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();
        
        // 到达目标
        if (current->x == goal->x && current->y == goal->y) {
            // 回溯路径
            vector<Node*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }
        
        closedSet[current->x][current->y] = true;
        
        // 检查所有方向
        for (auto& dir : directions) {
            int nx = current->x + dir.first;
            int ny = current->y + dir.second;
            
            // 边界检查
            if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
            // 障碍物检查（0表示障碍）
            if (grid[nx][ny] == 0) continue;
            // 已在关闭列表中
            if (closedSet[nx][ny]) continue;
            
            double new_g = current->g + 1;  // 假设每步代价为1
            double new_h = heuristic(nx, ny, goal->x, goal->y);
            Node* neighbor = new Node(nx, ny, new_g, new_h, current);
            openSet.push(neighbor);
        }
    }
    
    return {};  // 未找到路径
}

int main() {
    // 0=障碍, 1=可通过
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    
    Node* start = new Node(0, 0);
    Node* goal = new Node(4, 4);
    
    vector<Node*> path = aStarSearch(grid, start, goal);
    
    cout << "A* Path: ";
    for (Node* node : path) {
        cout << "(" << node->x << "," << node->y << ") ";
    }
    cout << endl;
    
    // 清理内存
    for (Node* node : path) delete node;
    delete start;
    delete goal;
    
    return 0;
}