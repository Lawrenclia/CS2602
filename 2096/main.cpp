#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* build(stringstream& ss) {
	int val;

	if (!(ss >> val) || val == -1) {
		return nullptr;
	}

	TreeNode* node = new TreeNode(val);

	node->left = build(ss);
	node->right = build(ss);

	return node;

}


int getHeight(TreeNode* node, int& maxDiameter) {
	if (node == nullptr) {
		return 0;
	}

	int leftHeight = getHeight(node->left, maxDiameter);
	int rightHeight = getHeight(node->right, maxDiameter);

	int currentDiameter = leftHeight + rightHeight;

	if (currentDiameter > maxDiameter) {
		maxDiameter = currentDiameter;
	}

	if (leftHeight > rightHeight) {
		return leftHeight + 1;
	} else {
		return rightHeight + 1;
	}

}


void deleteTree(TreeNode* node) {
	if (node == nullptr) {
		return;
	}
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}


int main() {
	string line;
	getline(cin, line);

	stringstream ss(line);

	TreeNode* root = build(ss);

	int maxDiameter = 0;

	getHeight(root, maxDiameter);

	cout << maxDiameter << endl;

	deleteTree(root);
	return 0;
}