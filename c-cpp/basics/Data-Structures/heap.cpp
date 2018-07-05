/*
Simple Heap implementation using C++
Supported Operations:
	- Insert
	- Remove
	- Find
	- Build
*/
#include <iostream>
#include <vector>
using namespace std;

class Heap {

private:
	vector<int> data;
	void swap(int i, int j);
	bool down(int i);
	void up(int i);
	void fix(int i);


public:
	Heap(vector<int> d);
	Heap();
	int top();
	void push(int v);
	void pop();
	void show();
	void remove(int v);
};

Heap::Heap() {

}

void Heap::fix(int i) {
	if (!down(i))
		up(i);
}

void Heap::swap(int i, int j) {
	int tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

Heap::Heap(vector<int> d) {
	data = vector<int>(d);
	for (int i = data.size()/2 - 1; i >= 0; i--)
		down(i);
}

bool Heap::down(int i0) {
	int i, j;
	i = i0;

	while(true) {
		j = 2*i + 1;
		if (j >= data.size())
			break;
		if ((j+1) < data.size() && data[j+1] < data[j])
			j++;
		if (data[j] < data[i])
			swap(i, j);

		i = j;
	}

	return (i > i0);
}

void Heap::remove(int v) {
	int idx = -1;
	for (int i = 0; i < data.size(); i++)
		if (data[i] == v) {
			idx = i;
			break;
		}

	swap(idx, data.size()-1);
	data.pop_back();
	fix(idx);
}

void Heap::up(int i) {
	int j;
	while (true) {
		j = (i - 1)/2;
		if (i == j || data[i] > data[j])
			break;
		if (data[i] < data[j])
			swap(i,j);
		i = j;
	}
}

void Heap::show() {
	for (int i = 0; i < data.size(); i++)
		cout << data[i] << " ";
	cout << endl;
}

int Heap::top() {
	return data[0]; 
}

void Heap::push(int v) {
	data.push_back(v);
	up(data.size()-1);
}

void Heap::pop() {
	if (data.size() == 0)
		return;

	int n = data.size() - 1;
	swap(n, 0);
	data.pop_back();
	down(0);
}