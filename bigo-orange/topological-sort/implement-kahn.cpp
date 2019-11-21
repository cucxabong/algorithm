#include <iostream>
#include <vector>
#include "helper.cpp"

using namespace std;

vector<int> calculate_in_degree(vector<vector<int> > graph, int V) {
    vector<int> in_degree;
    int u;
    in_degree.assign(V, 0);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            u = graph[i][j];
            in_degree[u]++;
        }
    }

    return in_degree;
}

bool topological_sort(vector<vector<int> > graph, vector<int> in_degree, vector<int> &result, int V) {
    vector<int> zero_degree;
    for (int i = 0; i < in_degree.size(); i++) {
        if (in_degree[i] == 0) {
            zero_degree.push_back(i);
        }
    }

    while (zero_degree.size() > 0) {
        int u = zero_degree.back();
        zero_degree.pop_back();
        result.push_back(u);

        // Decrease in_degree
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            in_degree[v]--;
            if (in_degree[v] == 0) {
                zero_degree.push_back(v);
            }
        }
    }

    for (int i = 0; i < in_degree.size(); i++) {
        if (in_degree[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int V, E;
    vector<vector<int> > graph = read_input(V, E);
    vector<int> in_degree = calculate_in_degree(graph, V);


    vector<int> result;
    bool ret = topological_sort(graph, in_degree, result, V);

    if (ret) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    } else {
        cout << "Unable to do topological sorting!" << endl;
    }

    return 0;
}