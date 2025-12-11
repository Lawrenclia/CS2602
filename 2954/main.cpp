#include <iostream>

using namespace std;


int main() {
	int numNode;
	cin >> numNode;
	int T = numNode;
	int parent = numNode / 2;
	bool flag = true;
	while (T) {
		int x, y, z;
		cin >> x >> y >>z;
		
		if (x < parent) {
			if (y == -1 || z == -1) {
				flag = false;
				break;
			}
		}else if (x == parent) {
			if (numNode % 2 == 0) {
				if (y == -1) {
					flag = false;
					break;
				}
				if (z != -1) {
					flag = false;
					break;
				}
			}
			else {
				if (y == -1) {
					flag = false;
					break;
				}
				if (z == -1) {
					flag = false;
					break;
				}
			}
		}
		else {
			if (y != -1 || z != -1) {
				flag = false;
				break;
			}
		}
		
		T--;
	}
	if (flag) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;
}