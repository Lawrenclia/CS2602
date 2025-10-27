#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* build(stringstream& ss) {
	string token;

	if (!(ss >> token) || token == ".") {
		return nullptr;
	}

	int val = stoi(token);

	TreeNode* node = new TreeNode(val);

	node->left = build(ss);
	node->right = build(ss);

	return node;
}


void printInOrder(TreeNode* node) {
	if (node == nullptr) {
		return;
	}
	printInOrder(node->left);
	cout << node->val << " "; 
	printInOrder(node->right);
}


void printPostOrder(TreeNode* node) {
	if (node == nullptr) {
		return;
	}
	printPostOrder(node->left);
	printPostOrder(node->right);
	cout << node->val << " "; 
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

	printInOrder(root);
	cout << endl;
	printPostOrder(root);

	deleteTree(root);
	return 0;
}