// C++ implementation
#include <bits/stdc++.h>
using namespace std;

// Return the number is
// Flavious Number or not
bool Survives(int n)
{
	int i;

	// index i starts from 2 because
	// at 1st iteration every 2nd
	// element was remove and keep
	// going for k-th iteration
	for (int i = 2;; i++) {
		if (i > n)
			return true;
		if (n % i == 0)
			return false;

		// removing the elements which are
		// already removed at kth iteration
		n -= n / i;
	}
}

// Driver Code
int main()
{
	int n = 17;
	if (Survives(n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
