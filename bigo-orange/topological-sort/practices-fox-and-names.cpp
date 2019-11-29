#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string> read_input() {
    int n;
    vector<string> author_names;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        author_names.push_back(name);
    }

    return author_names;
}

bool build_lexicographical(vector<vector<int> > graph, string &result) {
    vector<int> in_degree, zero_in_degree;
    in_degree.assign(graph.size(), 0);

    for (int i = 0; i < in_degree.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            in_degree[graph[i][j]]++;
        }
    };

    for (int i = 0; i < in_degree.size(); i++) {
        if (in_degree[i] == 0) {
            zero_in_degree.push_back(i);
        }
    }

    while (!zero_in_degree.empty()) {
        int tmp = zero_in_degree.front();
        zero_in_degree.erase(zero_in_degree.begin());
        result += tmp + 'a';

        for (int i = 0; i < graph[tmp].size(); i++) {
            in_degree[graph[tmp][i]]--;
            if (in_degree[graph[tmp][i]] == 0) {
                zero_in_degree.push_back(graph[tmp][i]);
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

vector<vector<int> > build_graph(vector<string> author_names, bool &is_impossible) {
    vector<vector<int> > graph;
    graph.assign('z'-'a'+1, vector<int>());

    for (int i = 0; i < author_names.size()-1; i++) {
        int idx = 0;
        while (author_names[i][idx] == author_names[i+1][idx]) {
            idx++;
            if (idx == author_names[i].length()) {
                break;
            } else if (idx == author_names[i+1].length()) {
                is_impossible = true;
                break; 
            }
        }

        if (idx < author_names[i].length()) {
            graph[author_names[i][idx] - 'a'].push_back(author_names[i+1][idx] - 'a');
        }
        
    }

    return graph;
}

int main() {
    vector<string> author_names = read_input();
    bool is_impossible = false;
    vector<vector<int> > graph = build_graph(author_names, is_impossible);
    if (is_impossible) {
        cout << "Impossible";
        return 0;
    }

    string result = "";
    bool ret = build_lexicographical(graph, result);
    if (!ret) {
        cout << "Impossible";
        return 0;
    }

    cout << result;
    return 0;
}