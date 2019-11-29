/*
Sandro is a well organised person. Every day he makes a list of things which need to be done and enumerates them from 11 to nn. 
However, some things need to be done before others. In this task you have to find out whether Sandro can solve all his duties and if so, 
print the correct order.

Input
In the first line you are given an integer nn and mm (1 \le n \le 100001≤n≤10000, 1 \le m \le 10000001≤m≤1000000). On the next mm lines there are two distinct integers xx and yy, (1 \le x, y \le n1≤x,y≤n) describing that job xx needs to be done before job yy.

Output
Print Sandro fails. if Sandro cannot complete all his duties on the list. If there is a solution print the correct ordering, the jobs to be done separated by a whitespace. If there are multiple solutions print the one, whose first number is smallest, if there are still multiple solutions, print the one whose second number is smallest, and so on.


EXAMPLE
Input 1
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6

Output 1
1 4 3 5 7 8 2 6 

Input 2
2 2
1 2
2 1

Output 2
Sandro fails.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > read_input(int &V, int &E) {
	vector<vector<int> > graph;  
	int u, v;  
	cin >> V >> E;
	graph.resize(V+1);

	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		graph[u].push_back(v);    
  }

	return graph;  
}

bool topological_sort(vector<vector<int> > graph, vector<int> &result, int V) {
	// calculate in_degree
	vector<int> in_degree;
	in_degree.assign(V+1,0);
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int u = graph[i][j];      
			in_degree[u]++;      
    }    
  }  

	
	priority_queue<int, vector<int>, greater<int> > zero_in_degree;
  
	for (int i = 1; i <= V; i++) {
		if (in_degree[i] == 0) {
      zero_in_degree.push(i);
    }    
  }

	while (!zero_in_degree.empty()) {
		int u = zero_in_degree.top();
		zero_in_degree.pop();
		result.push_back(u);

		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i];
			in_degree[v]--;
			if (in_degree[v] == 0) {
				zero_in_degree.push(v);        
            }   
        } 
    }

	for (int i = 1; i <= V; i++) {
		if (in_degree[i] != 0) {
			return false;      
    }    
  }  
  
	return true;  
}

int main() {
	int V, E;
	vector<vector<int> > graph = read_input(V, E);

	vector<int> result;  
  bool ret = topological_sort(graph, result, V);
  if (ret) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";      
    }    
  } else {
		cout << "Sandro fails.";
  }
	return 0;  
}