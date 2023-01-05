#include <iostream>
#include <vector>
using namespace std;

#define MAX_INT 10000000

int main() {
	int target;
	cin >> target;

	int minCon = MAX_INT;  // 가장 작은 생성자
	for (int i = target; i > 0; i--) {
		int tempCon = i;
		int conSum = tempCon;
		while (tempCon) {
			conSum += tempCon % 10;
			tempCon /= 10;
		}
		if (conSum == target) minCon = minCon > i ? i : minCon;
	}
	
	if (minCon == MAX_INT) cout << 0;
	else cout << minCon;
}