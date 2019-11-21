#include <iostream>
#include <vector>
#include <algorithm>
#include "helper.cpp"

using namespace std;

void dfs(int u, vector<vector<int> > graph, vector<bool> &visited, vector<int> &result) {
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            dfs(v, graph, visited, result);
        }
    }
    result.push_back(u);
}

vector<int> topological_sort(vector<vector<int> > graph, int V) {
    vector<int> result;
    vector<bool> visited;
    visited.assign(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, result);
        }
    }

    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    int V, E;
    vector< vector<int> > graph = read_input(V, E);
    vector<int> result = topological_sort(graph, V);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}