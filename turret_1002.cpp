#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int calcDistance(int x1, int x2, int y1, int y2, int r1, int r2);
int countPoint(int x1, int x2, int y1, int y2, int r1, int r2);

int main() {
	int testCase;
	cin >> testCase;

	int x1, x2, y1, y2, r1, r2;
	vector<int> output;
	for (int i = 0; i < testCase; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		output.push_back(countPoint(x1, x2, y1, y2, r1, r2));
	}

	for (int elem : output)
		cout << elem << endl;
}

int calcDistance(int x1, int x2, int y1, int y2, int r1, int r2) {
	int width = x2 - x1;
	int height = y2 - y1;
	int distance = pow(width, 2) + pow(height, 2);
	return distance;
}

int countPoint(int x1, int x2, int y1, int y2, int r1, int r2) {
	if (x1 == x2 && y1 == y2 && r1 == r2)
		return -1;
	int distance = calcDistance(x1, x2, y1, y2, r1, r2);
	int radiusDiff = pow(abs(r2 - r1), 2);
	int radiusSum = pow(abs(r2 + r1), 2);
	if (distance < radiusSum && distance > radiusDiff) return 2;
	if (distance == radiusSum || distance == radiusDiff) return 1;
	return 0;
}
