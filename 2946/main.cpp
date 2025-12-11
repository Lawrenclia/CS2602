#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* buildTree(const vector<int>& tree) {
	if (tree.empty()) return nullptr;
	Node* root = new Node(tree[0]);
	queue<Node*> q;
	q.push(root);
	int i = 1;
	while (i < tree.size()) {
		Node* current = q.front();
		q.pop();
		if (tree[i] != -1) {
			current->left = new Node(tree[i]);
			q.push(current->left);
		}
		++i;
		if (i >= tree.size()) break;
		if (tree[i] != -1) {
			current->right = new Node(tree[i]);
			q.push(current->right);
		}
		++i;
	}
	return root;
}

bool isValidBST(Node* root, int minNum, int maxNum) {
	if (!root) return true;
	if (root->data <= minNum || root->data >= maxNum) return false;
	return isValidBST(root->left, minNum, root->data) && isValidBST(root->right, root->data, maxNum);
}
int main() {
	string line;
	getline(cin, line);
	istringstream iss(line);
	vector<int> tree;
	int val;
	while (iss >> val) {
		tree.push_back(val);
	}

	Node* root = buildTree(tree);
	if (isValidBST(root, -10000, 10000)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}