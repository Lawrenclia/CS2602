#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T) {
		int N, M;
		int step = 0;
		cin >> N >> M;
		queue<int> q;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			int a;

			cin >> a;
			v.push_back(a);
			q.push(a);
		}
		while (true) {
			while (M) {
				int b = q.front();
				int maxNumber = 0;
				int maxIndex = 0;
				for (int j = 0; j < v.size(); j++) {
					if (v[j] > maxNumber) {
						maxNumber = v[j];
						maxIndex = j;
					}
				}
				if (b < maxNumber) {
					q.pop();
					q.push(b);
					b = q.front();
				}
				else {
					q.pop();
					v[maxIndex] = 0;
					step++;
				}
				M--;

			}
			int b = q.front();
			int maxNumber = 0;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] > maxNumber) {
					maxNumber = v[j];
				}
			}
			if (b < maxNumber) {
				q.pop();
				q.push(b);
				M = q.size() - 1;
			}
			else {
				cout << step + 1 << endl;
				break;
			}

		}
		T--;
	}
}