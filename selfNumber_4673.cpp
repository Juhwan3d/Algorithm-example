#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> selfNumbers;

	for (int i = 1; i <= 10000; i++) {
		bool isSelf = true;
		for (int j = i - 1; j > 0; j--) {
			int temp = j;
			int sum = temp;
			while (temp) {
				sum += temp % 10;
				temp /= 10;
			}
			if (sum == i) isSelf = false;
		}
		if (isSelf) selfNumbers.push_back(i);
	}

	for (int elem : selfNumbers)
		cout << elem << endl;
}