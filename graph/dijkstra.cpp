#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#define INF 10000

using namespace std;

// Single Source All shortest path

vector<bool> visited;
vector<int> cost;
map<int, vector<pair<int, int>>> graph;

// pair.first  = cost
// pair.second = node

void addLine(int u, int v, int c) {
    graph[u].push_back({c, v});
    graph[v].push_back({c, u});
}

void dijkstra(int start) {
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    pq.push({0, start});
    cost[start] = 0;

    while(!pq.empty()) {
        pair<int, int> u = pq.top();
        pq.pop();
        visited[u.second] = true;

        for(pair<int, int> v:  graph[u.second]) {
            int c = cost[u.second] + v.first;
            if (!visited[v.second] && c < cost[v.second]) {
                cost[v.second] = c;
                pq.push({c, v.second});
            }
        }
    }
}

int main() {
    addLine('A', 'B', 1);
    addLine('A', 'C', 3);
    addLine('B', 'C', 1);
    addLine('B', 'D', 3);
    addLine('B', 'E', 1);
    addLine('C', 'D', 1);
    addLine('C', 'E', 2);
    addLine('D', 'E', 4);
    visited.resize(257, false);
    visited.resize(257, INF);
    dijkstra('A');
    for(int i = 2; i <= 5; i++) {
        cout << (char)(i + 64) << "=" << cost[i + 64] << ", ";
    }
}
