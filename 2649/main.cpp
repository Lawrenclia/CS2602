#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    if (x == y) {
        cout << x << endl;
        return 0;
    }

    vector<int> parent(n + 1, 0);

    for (int k = 1; k <= n; ++k) {
        int left, right;
        cin >> left >> right;
        if (left != 0) parent[left] = k;
        if (right != 0) parent[right] = k;
    }

    vector<bool> is_ancestor_x(n + 1, false);
    int curr = x;
    while (curr != 0) {
        is_ancestor_x[curr] = true;
        curr = parent[curr];
    }

    curr = y;
    while (curr != 0) {
        if (is_ancestor_x[curr]) {
            cout << curr << endl;
            return 0;
        }
        curr = parent[curr];
    }

    return 0;
}