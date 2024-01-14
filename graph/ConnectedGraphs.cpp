#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int>> graph;

void addLine(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void connectedComponents(vector<bool> &visited, int u) {
    for(int v: graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            connectedComponents(visited, v);
        }
    }
}

int main() {
    int V = 5, count = 0;
    vector<bool> visited(V, false);

    addLine(1, 2);
    addLine(2, 3);
    addLine(4, 5);

    vector<int> counter(V, 0);
    for(int u = 1; u <= V; u++) {
        if (!visited[u]) {
            connectedComponents(visited, u);
            counter[u]++;
        }
    }

    for(int c: counter) {
        cout << c << " ";
    }
}