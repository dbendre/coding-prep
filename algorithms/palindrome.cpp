#include <iostream>
#include <string>

using namespace std;

/*

ex) anna 
2 cases, either odd or even length string
if even, check front and reverse index
if odd, check front and reverse index until midpoint is reached
anina
*/

bool checkPalindrome(string str) {
	int i, j;
	// check length first: 
	if (str.length() % 2 == 0) { // even string
		int midIndex = (str.length() /2) - 1;
		for (i = 0, j = str.length() - 1; i <= midIndex && j > midIndex; ++i, --j) {
			if (str[i] != str[j])
				return false;
		}
		return true;

	} else { // odd string
		for (i = 0, j = str.length() - 1; i < str.length() && j >= 0; ++i, --j) {
			if (str[i] != str[j])
				return false;
			if (i == j) // same index
				return true;
		}
	} // note you should be able to merge this for a single function
}

// geeks for geeks solution: 
/*
find length of str. intialize low and high indexes as 0 and n-1
while low is smaller than high, if str[l] != str[h], return false
increment l and decrement h
if end of loop return true
note this is same logic as above but more brief
*/

void isPalindrome(string str) {
	// cout << "in here: ";
	int l = 0, h = str.length() - 1;
	while (h > l) {
		if (str[h--] != str[l++]) {
			cout << "string is not a palindrome" << endl;
			return;
			// return false;
		}
	}
	cout << "string is palindrome" << endl;
	// return true;
}

int main() {
	string str;
	cout << "enter a string to checK: ";
	cin >> str;
	isPalindrome(str);

	return 0;
}