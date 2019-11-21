
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > read_input(int &V, int &E) {
    vector< vector<int> > graph;
    int u, v;

    cin >> V >> E;
    graph.resize(V);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    return graph;
}