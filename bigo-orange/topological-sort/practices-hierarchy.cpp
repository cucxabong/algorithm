#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > read_input() {
    int n,k;
    vector<vector<int> > graph;
    cin >> n >> k;
    graph.assign(n+1, vector<int>());
    for (int i = 1; i <= k; i++) {
        int w;
        cin >> w;
        while (w > 0) {
            int tmp;
            cin >> tmp;
            graph[i].push_back(tmp);
            w--;
        }
    }

    return graph;
}

vector<int> create_hierarchy(vector<vector<int> > graph) {
    vector<int> result, in_degree, zero_in_degree;
    result.assign(graph.size(), -1);
    in_degree.assign(graph.size(), 0);

    for (int i = 1; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            in_degree[graph[i][j]]++;
        }
    }

    for (int i = 1; i < graph.size(); i++) {
        if (in_degree[i] == 0) {
            zero_in_degree.push_back(i);
        }
    }

    int boss_id = 0;
    while (!zero_in_degree.empty()) {
        int student = zero_in_degree.back();
        zero_in_degree.pop_back();
        result[student] = boss_id;
        boss_id = student;

        for (int i = 0; i < graph[student].size(); i++) {
            in_degree[graph[student][i]]--;
            if (in_degree[graph[student][i]] == 0) {
                zero_in_degree.push_back(graph[student][i]);
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int> > graph = read_input();
    vector<int> result = create_hierarchy(graph);
    for (int i = 1; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}