#include <vector>

using namespace std;

bool threeConsecutiveOdds(vector<int>& arr);

int main() {

	return 0;
}

bool threeConsecutiveOdds(vector<int>& arr) {
	int count = 0;

	int i = 0;
	while (count != 3 && i < arr.size()) {
		if (arr[i] % 2 == 1) count++;
		else count = 0;
		i++;
	}
	if (count == 3) return true;
	return false;
}
