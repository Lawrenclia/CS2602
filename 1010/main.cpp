#include <iostream>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	int* products = new int[n + 1];
	products[0] = 0;
	cin >> products[1];
	for (int i = 2; i <= n; i++) {
		int val;
		cin >> val;
		products[i] = products[i - 1] + val;
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int left = 1, right = n;
		int pos = n;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (products[mid] >= num) {
				pos = mid;
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		cout << pos << " " << num - products[pos - 1] << endl;
	}

	delete[] products;

	return 0;
}