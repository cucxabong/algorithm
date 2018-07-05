/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool **vis;
bool **bombs;

struct Cell {
	int row, col, cost;
	
	bool operator ==(const Cell c)
	{
		return (row == c.row && col == c.col);
	}

	bool is_visited() {
		return vis[row][col];
	}

	bool is_bomb() {
		return bombs[row][col];
	}

	void set_visit(bool visited) {
		vis[row][col] = visited;
	}
};

bool is_valid_cell(Cell c, int rows, int cols) {
	return (c.row >= 0 && c.row < rows && c.col >= 0 && c.col < cols);
}

void bfs(Cell start, Cell end, int rows, int cols) {
	queue<Cell> q;
	q.push(start);
	start.set_visit(true);

	while (!q.empty()) {
		Cell c = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Cell nb = {c.row + dx[i], c.col + dy[i], c.cost+1};

			if (is_valid_cell(nb, rows, cols) && 
				!nb.is_visited() &&
				!nb.is_bomb()) {
				nb.set_visit(true);

				if (nb == end) {
					cout << nb.cost << endl;
					break;
				}

				q.push(nb);
			}
		}
	}
}

int main() {
	int rows, cols, bomb_rows, bomb_row, bomb_nums;
	int tmp_r, tmp_c;

	do {
		cin >> rows >> cols;
		if (rows == 0 && cols == 0) {
			break;
		}

		bombs = new bool*[rows];
		vis = new bool*[rows];
		for (int i = 0; i < rows; i++) {
			vis[i] = new bool[cols];
			bombs[i] = new bool[cols];
			for (int j = 0; j < cols; j++) {
				vis[i][j] = false;
				bombs[i][j] = false;
			}
		}

		cin >> bomb_rows;

		for (int i = 0; i < bomb_rows; i++) {
			cin >> bomb_row >> bomb_nums;
			int tmp;
			for (int j = 0; j < bomb_nums; j++) {
				cin >> tmp;
				bombs[bomb_row][tmp] = true;
			}
		}

		cin >> tmp_r >> tmp_c;
		Cell start = {tmp_r, tmp_c, 0};
		cin >> tmp_r >> tmp_c;
		Cell end = {tmp_r, tmp_c, 0};

		bfs(start, end, rows, cols);

	} while (true);
}