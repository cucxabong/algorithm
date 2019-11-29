#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > read_input(int &V) {
    int E;
    vector<vector<int> > graph;
    cin >> V >> E;
    graph.assign(V, vector<int>());
    while (E > 0) {
        int u, v;
        cin >> v >> u;
        graph[u].push_back(v);
        E--;
    }

    return graph;
}

void answer_the_boss(vector<vector<int> > graph, vector<vector<int> > &result, int &V) {
    priority_queue<int, vector<int>, greater<int> > zero_in_degree;
    vector<int> in_degree;
    in_degree.assign(V, 0);
    int u,v,rank;

    for (int i = 0; i < V; i++) {
        u = i;
        for (int j = 0; j < graph[i].size(); j++) {
            v = graph[u][j];
            in_degree[v]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            zero_in_degree.push(i);
        }
    }

    rank = 0;
    while (true) {
        result.push_back(vector<int>());
        priority_queue<int, vector<int>, greater<int> > next_zero_in_degree;

        while (!zero_in_degree.empty()) {
            u = zero_in_degree.top();
            zero_in_degree.pop();
            result[rank].push_back(u);
        
            for (int i = 0; i < graph[u].size(); i++) {
                in_degree[graph[u][i]]--;
                if (in_degree[graph[u][i]] == 0) {
                    next_zero_in_degree.push(graph[u][i]);
                }
            }
        }

        if (!next_zero_in_degree.empty()) {
            zero_in_degree.swap(next_zero_in_degree);
            rank++;
        } else {
            break;
        }
    }
}

int main() {
    int test_case;
    cin >> test_case;

    for (int i = 1; i <= test_case; i++) {
        int V;
        vector<vector<int> > result;
        vector<vector<int> > graph = read_input(V);
        answer_the_boss(graph, result, V);
        cout << "Scenario #" << i << ":" << endl;
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << i+1 << " " << result[i][j] << endl;
            }
        }
    }

    return 0;
}