#include <iostream>
#include <vector>
using namespace std;

void countPairing(vector<vector<bool>>& pairTable, vector<int>& students, int& ret, bool isPair=true);

int main() {
	int testCase;
	cin >> testCase;
	
	int studentCount, pairCount;
	vector<int> output;
	for (int i = 0; i < testCase; i++) {
		cin >> studentCount >> pairCount;
		vector<vector<bool>> pairTable(studentCount, vector<bool>(studentCount));
		for (int i = 0; i < pairCount; i++) {
			int x, y; cin >> x >> y;
			pairTable[x][y] = true;
		}
		vector<int> students; for (int i = 0; i < studentCount; i++) students.push_back(i);
		int ret = 0;
		countPairing(pairTable, students, ret);
		output.push_back(ret);
	}

	for (int elem : output) cout << elem << endl;
}

void countPairing(vector<vector<bool>>& pairTable, vector<int>& students, int& ret, bool isPair) {
	if (!isPair) return;
	if (students.empty()) { ret++; return; }
	
	for (int i = 1; i < students.size(); i++) {
		int s1 = students[0]; int s2 = students[i];
		isPair = pairTable[s1][s2] + pairTable[s2][s1];
		students.erase(students.begin() + i); students.erase(students.begin());
		countPairing(pairTable, students, ret, isPair);
		students.insert(students.begin(), s1), students.insert(students.begin() + i, s2);
	}
}
