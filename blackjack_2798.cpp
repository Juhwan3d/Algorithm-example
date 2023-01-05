#include <iostream>
#include <vector>
using namespace std;

int calcMaxSum(int limit, vector<int>& cards, int toPick=3, int sum=0, int next=0, int maxSum=-1);

int main() {
	int cardCount, limit;
	cin >> cardCount >> limit;
	vector<int> cards;
	for (int i = 0; i < cardCount; i++) {
		int temp;
		cin >> temp;
		cards.push_back(temp);
	}
	cout << calcMaxSum(limit, cards);
}

int calcMaxSum(int limit, vector<int>& cards, int toPick, int sum, int next, int maxSum) {
	if (toPick == 0) {
		if (sum > limit) return maxSum;
		if (sum <= limit) {
			maxSum = maxSum < sum ? sum : maxSum;
			return maxSum;
		}
	}
	for (int i = next; i < cards.size(); i++) {
		sum += cards[i];
		maxSum = calcMaxSum(limit, cards, toPick - 1, sum, i + 1, maxSum);
		sum -= cards[i];
	}
	return maxSum;
}
