#include <iostream>
#include <string>
using namespace std;

bool isDevil(int target);

int main() {
	int n;
	cin >> n;

	bool isFinished = false;
	int target = 666;
	int count = 0;
	while (!isFinished) {
		if (isDevil(target++)) count++;
		if (count == n) isFinished = true;
	}
	cout << target-1;
}

bool isDevil(int target) {
	string sTarget = to_string(target);
	if (sTarget.find("666") != string::npos) return true;
	return false;
}
