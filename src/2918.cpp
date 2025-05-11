#include <iostream>
#include <vector>

using namespace std;

long long minSum(vector<int>& nums1, vector<int>& nums2);

int main() {
	vector<int> nums1 = { 3,2,0,1,0 };
	vector<int> nums2 = { 6,5,0 };

	cout << minSum(nums1, nums2) << endl;

	return 0;
}

long long minSum(vector<int>& nums1, vector<int>& nums2) {
	long arr1Count0 = 0, arr2Count0 = 0;
	unsigned long arr1Sum = 0, arr2Sum = 0;	

	for (int i = 0; i < nums1.size(); i++) {
		arr1Sum += nums1[i];
		if (nums1[i] == 0) arr1Count0++;
	}
	for (int i = 0; i < nums2.size(); i++) {
		arr2Sum += nums2[i];
		if (nums2[i] == 0) arr2Count0++;
	}

	unsigned long x = arr1Sum + arr1Count0;
	unsigned long y = arr2Sum + arr2Count0;

	if (y == x) return x;
	if (x > y) {
		if (arr2Count0 > 0) return x;
		return -1;
	}

	if (arr1Count0 > 0) return y;
	return -1;
}
