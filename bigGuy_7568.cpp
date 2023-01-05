#include <iostream>
#include <vector>
using namespace std;


int main() {
	int manCount;
	cin >> manCount;

	vector<int> weights;
	vector<int> heights;
	vector<int> ranks(manCount);
	for (int i = 0; i < manCount; i++) {
		int w, h;
		cin >> w >> h;
		weights.push_back(w); heights.push_back(h);
	}

	for (int i = 0; i < manCount; i++) {
		for (int j = i+1; j < manCount; j++) {
			if (weights[i] > weights[j] && heights[i] > heights[j]) ranks[j] += 1;
			else if (weights[i] < weights[j] && heights[i] < heights[j]) ranks[i] += 1;
		}
	}
	
	for (int elem : ranks)
		cout << elem + 1 << ' ';
}