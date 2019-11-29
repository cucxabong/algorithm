#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;
map<string, int> beverages_order;

struct CompareOrder { 
    bool operator()(string const& s1, string const& s2) 
    { 
        return beverages_order[s1] > beverages_order[s2]; 
    } 
}; 

map<string, vector<string> > read_input(int V) {
    int E;
    string beverage_name, u, v;
    map<string, vector<string> > graph;

    //cin >> V;
    for (int i = 0; i < V; i++) {
        cin >> beverage_name;
        beverages_order[beverage_name] = i;
        graph[beverage_name] = vector<string>();
    }

    cin >> E;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    return graph;
}

bool beverages_sort(map<string, vector<string> > graph, vector<string> &result) {
    priority_queue<string, vector<string>, CompareOrder > zero_in_degree;
    map<string, int> in_degree;

    for (auto it = graph.begin(); it != graph.end(); it++) {
        in_degree[it->first] = 0;
    }

    for (auto it = graph.begin(); it != graph.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            in_degree[it->second[i]]++;
        }
    }

    for (auto it = in_degree.begin(); it != in_degree.end(); it++) {        
        if (in_degree[it->first] == 0) {
            zero_in_degree.push(it->first);
        }
    }

    while (!zero_in_degree.empty()) {
        string beverage = zero_in_degree.top(); //zero_in_degree.front();
        zero_in_degree.pop();
        //zero_in_degree.erase(zero_in_degree.begin());
        result.push_back(beverage);
        for (int i = 0; i < graph[beverage].size(); i++) {
            in_degree[graph[beverage][i]]--;
            if (in_degree[graph[beverage][i]] == 0) {
                zero_in_degree.push(graph[beverage][i]);
            }
        }
    }

    for (auto it = in_degree.begin(); it != in_degree.end(); it++) {
        if (it->second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int V, case_number;
    string u, v;
    case_number = 0;

    while (cin >> V) {
        case_number++;
        map<string, vector<string> > graph = read_input(V);
        vector<string> result;
        beverages_sort(graph, result);
        cout << "Case #" << case_number << ": Dilbert should drink beverages in this order: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i == result.size() - 1) {
                cout << "." << endl;
            } else {
                cout << " ";
            }
        }        
        //cout << endl;
    }
    
    return 0;
}