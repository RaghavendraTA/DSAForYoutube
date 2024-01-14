#include <iostream>
#include <vector>

using namespace std;

vector<int> nodeRank, parent;

void init(int V) {
    nodeRank.resize(V+1, 0);
    parent.resize(V+1);
    for(int i = 0; i <= V; i++)
        parent[i] = i;
}

int findParent(int u) {
    if (u == parent[u])
        return u;
    int p = findParent(parent[u]);
    parent[u] = p;
    return p;
}

void unionByRank(int u, int v) {
    int up = findParent(u), vp = findParent(v);
    if (up == vp)
        return;
    if (nodeRank[u] < nodeRank[v]) {
        parent[u] = v;
    } 
    else if (nodeRank[u] > nodeRank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        nodeRank[u]++;
    }
}

int main() {
    int n = 10;
    init(n);
    // Call unionByRank
    return 0;
}