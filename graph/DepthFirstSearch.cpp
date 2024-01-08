#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<bool> visited;
unordered_map<int, vector<int>> graph;

void dfs(int u) {
    if (visited[u])
        return;
    visited[u] = true;
    for(int v: graph[u]) {
        if (!visited[v]) {
            cout << u << " -> " << v << endl;
            dfs(v);
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
    dfs(1);
    return 0;
}