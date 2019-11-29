#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#include <set>

using namespace std;

unsigned long long axis_to_index_number(unsigned int x, unsigned int y) {
    return pow(10,9)*x + y;
}

pair<unsigned int, unsigned int> index_to_axis(unsigned long long idx) {
    unsigned int x, y;
    x = idx/pow(10,9);
    y = idx%(unsigned long long)pow(10,9);
    return make_pair(x, y);
}

bool find_shortest_path(unsigned long long src, unsigned long long dst, set<unsigned long long> graph, unsigned int &output) {
    set<unsigned long long> visited;
    map<unsigned long long, unsigned int> dist;
    queue<unsigned long long> q;
    
    visited.insert(src);
    dist[src] = 0;
    q.push(src);
    int x_offset[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y_offset[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
    
    while (!q.empty()) {
        unsigned long long u_idx = q.front();
        pair<unsigned int, unsigned int> u = index_to_axis(u_idx);
        q.pop();

        for (int i = 0; i < 8; i++) {
            unsigned long long neighbor_idx = axis_to_index_number(u.first + x_offset[i], u.second + y_offset[i]);
            if (graph.find(neighbor_idx) != graph.end() && visited.find(neighbor_idx) == visited.end()) {
                visited.insert(neighbor_idx);
                dist[neighbor_idx] = dist[u_idx] + 1;
                q.push(neighbor_idx);

                if (neighbor_idx == dst) {
                    output = dist[neighbor_idx];
                    return true;
                }
            }
        }
    }

    return false; 
}

set<unsigned long long> read_input(unsigned long long &src, unsigned long long &dst) {
    unsigned int x0, y0, x1, y1, n, r, a, b;
    set<unsigned long long> graph;

    cin >> x0 >> y0 >> x1 >> y1;
    src = axis_to_index_number(x0-1, y0-1);
    dst = axis_to_index_number(x1-1, y1-1);

    cin >> n;
    while (n) {
        cin >> r >> a >> b;
        for (int i = a; i <=b; i++) {
            graph.insert(axis_to_index_number(r-1, i - 1));
        }
        n--;
    }

    return graph;
}

int main() {
    unsigned long long src, dst;
    set<unsigned long long> graph = read_input(src, dst);
    unsigned int output = 0;
    
    if (find_shortest_path(src, dst, graph, output)) {
        cout << output << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
