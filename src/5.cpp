#include <iostream>

using namespace std;

string longestPalindrome(string s);

int main5() {
	string x = "bb";

	cout << longestPalindrome(x);

	return 0;
}

//time complexity 0(n^2)
//for every character expand around its center
//save longest palindrome

string expand(int right, int left, string s) {
	while (left > 0 && right < s.length() - 1) {
		if (s[left - 1] != s[right + 1]) break;
		left--;
		right++;
	}
	return s.substr(left, right - left + 1);
}

string longestPalindrome(string s) {
	int right, left;
	string longestPalindrome = string(1, s[0]);
	string odd, even;

	for (int i = 0; i < s.length(); i++) {
		odd = expand(i, i, s);
		even = expand(i, i + 1, s);

		if (odd.length() > longestPalindrome.length()) longestPalindrome = odd;
		if (even.length() > longestPalindrome.length()) longestPalindrome = even;
	} 

	return longestPalindrome;
}