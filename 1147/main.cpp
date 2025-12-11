#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    int left, right;
};

vector<Node> tree;
int n, ans = 0;

int check(int a, int b) {
    if (a == -1 && b == -1) return 0;
    if (a == -1 || b == -1) return -1;
    if (tree[a].val != tree[b].val) return -1;
    int l = check(tree[a].left, tree[b].right);
    int r = check(tree[a].right, tree[b].left);
    if (l == -1 || r == -1) return -1;
    return l + r + 2; 
}


int find(int u) {
    if (u == -1) return 0;
    int sz = 1;
    int left = tree[u].left, right = tree[u].right;
    int sym = check(left, right);
    if (sym != -1) ans = max(ans, sym + 1); 
    find(left);
    find(right);
    return sz;
}

int main() {
    cin >> n;
    tree.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> tree[i].val;
    for (int i = 1; i <= n; ++i) cin >> tree[i].left >> tree[i].right;
    ans = 1; 
    find(1);
    cout << ans << endl;
    return 0;
}