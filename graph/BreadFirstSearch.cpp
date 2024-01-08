#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

vector<bool> visited;
deque<int> q;
unordered_map<int, vector<int>> graph;

void bfs(int start) {
    q.push_back(start);
    visited[start] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(int v: graph[u]) {
            if (!visited[v]) {
                cout << u << " -> " << v << endl;
                q.push_back(v);
                visited[v] = true;
            }
        }
    }
}

void addLine(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int main() {
    addLine(1, 2);
    addLine(2, 5);
    addLine(1, 3);
    addLine(3, 7);
    addLine(2, 6);
    addLine(1, 4);
    for(int i = 1; i <= 7; i++) {
        visited.push_back(false);
    }
    bfs(1);
    return 0;
}