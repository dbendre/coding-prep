#include <iostream>
using namespace std;

/*
comparing ordered triplets:
- if ai > bi -> A++
- if bi> ai -> B++
- if ai == bi -> no points

comparison is the total points a person earned. 

output is A's score then B's score separated by commas
*/

vector<int> solve(int a0, int a1, int a2, int b0, int b1, int b2) {
	int A = 0, B = 0;
	vector<int> res; 
	if (a0 > b0) {
		++A;
	} else if (b0 > a0) {
		++B;
	}

	if (a1 > b1) {
		++A;
	} else if (b1 > a1) {
		++B;
	}

	if (a2 > b2) {
		++A;
	} else if (b2 > a2) {
		++B;
	}

	res.push_back(A);
	res.push_back(B);

	return res;
} // need to extend in multiple tuples case


// other method that does everything in main and extends number of tuples: 
int main() {
	int n;
	cout << "Enter number of values to compare: ";
	cin >> n;
	vector<int> A(n);
	vector<int> B(n);
	int pointA = 0, pointB = 0;

	for (int i = 0; i < n; i++) {
		cin >> A[i]; // fill in vector A
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i]; // fill in vector B
	}

	for (int i = 0; i < n; i++) {
		if (A[i] > B[i])
			++pointA;
		else if (A[i] < B[i])
			++pointB;
	}

	cout << pointA << " " << pointB << endl;

	return 0;
}


/*
int main() {
	int a0, a1, a2;
	cin >> a0 >> a1 >> a2;
	int b0, b1, b2;
	cin >> b0 >> b1 >> b2;

	vector<int> result = solve(a0, a1, a2, b0, b1, b2);
	for (size_t i = 0; i < result.size(); i++) {
		cout << result[i] << (i != result.size() - 1 ? " " : "");
	}
	cout << endl;

	return 0;
} */