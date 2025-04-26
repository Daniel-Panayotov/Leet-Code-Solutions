#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	double expectedOffset = (static_cast<double>(nums1.size()) + nums2.size() - 1) / 2;
	bool isSingleMedian = trunc(expectedOffset) == expectedOffset;

	vector<int> array1 = nums1;
	vector<int> array2 = nums2;

	int array2I;
	double number;
	int mid;

	int left;
	int right;

	int offsetDiff;
	double calculatedOffset = -1;

	for (int i = 0; i < 2; i++) {
		//swaps arrays for 2nd iteration
		if (i == 1) { array1 = nums2; array2 = nums1; }
		//if array is empty, continue 
		if (array1.size() == 0) continue;

		left = 0;
		right = array1.size();

		while (expectedOffset != calculatedOffset) {
			mid = left + (right - left) / 2;
			number = array1[mid];

			//binary search in array2 if it has size, otherwise 0
			array2I = array2.size() > 0 ? binarySearch(number, array2, 0, array2.size() - 1) : 0;

			calculatedOffset = (array1.size() - mid - 1) + (array2.size() - array2I);

			offsetDiff = ceil(expectedOffset) - calculatedOffset;
			//if 2 medians AND we get EITHER of them
			if (!isSingleMedian && (offsetDiff == 0 || offsetDiff == 1)) break;

			//if we cant or have found the number, then the ranges will be next to each other 
			if (right - left == 1 || right == left) break;

			//if calculatedOffset higher than expected, then the number is too low
			//if calculatedOffset lower than expected, then the number is too higher
			if (calculatedOffset > expectedOffset) left = mid;
			else if (calculatedOffset < expectedOffset) right = mid;
		}

		//difference in offsets
		offsetDiff = ceil(expectedOffset) - calculatedOffset;

		//if we didnt find the median, continue with 2nd array
		if (!isSingleMedian && offsetDiff != 0 && offsetDiff != 1) continue;
		if (isSingleMedian && expectedOffset != calculatedOffset) continue;

		//if we found the one single median
		if (isSingleMedian) return number;

		//index for arr1 median, if it is there
		//median found could be either the upper or lower median, therefore the index should be adjusted
		int arr1MedianIndex = offsetDiff == 0 ? mid + 1 : mid - 1;
		//index for arr2 median, if it is there
		int arr2MedianIndex = trunc(expectedOffset) - mid;
		//if median isnt in array1, shown by index out of bounds, then assign it to array2
		if (arr1MedianIndex < 0 || arr1MedianIndex >= array1.size()) return (number + array2[arr2MedianIndex]) / 2;
		if (arr2MedianIndex < 0 || arr2MedianIndex >= array2.size()) return (number + array1[arr1MedianIndex]) / 2;

		//should contain 2nd median
		double num1 = array1[arr1MedianIndex];
		double num2 = array2[arr2MedianIndex];
		//depending on which of either medians we get, we would want the bigger or smaller number to determine the other median
		if (offsetDiff == 0 && num1 > num2) num1 = num2;
		if (offsetDiff == 1 && num1 < num2) num1 = num2;

		return (number + num1) / 2;
	}
	return -1;
}

int binarySearch(int num, vector<int>& nums, int startI, int endI) {
	if (startI == endI) {
		if (num > nums[startI]) return startI + 1;
		return startI;
	}

	int mid = (startI + endI) / 2;

	if (num > nums[mid] || num == nums[mid]) return binarySearch(num, nums, mid + 1, endI);

	return binarySearch(num, nums, startI, mid);
}