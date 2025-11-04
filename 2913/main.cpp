#include <iostream>
#include <string>

using namespace std;


string build(const string& preOrder, const string& inOrder) {
	if (preOrder.empty()) {
		return "";
	}
	char root = preOrder[0];
	size_t rootIndex = inOrder.find(root);
	string leftInOrder = inOrder.substr(0, rootIndex);
	string rightInOrder = inOrder.substr(rootIndex + 1);
	string leftPreOrder = preOrder.substr(1, leftInOrder.size());
	string rightPreOrder = preOrder.substr(1 + leftInOrder.size());
	string leftPostOrder = build(leftPreOrder, leftInOrder);
	string rightPostOrder = build(rightPreOrder, rightInOrder);
	return leftPostOrder + rightPostOrder + root;
}

int main() {
	string preOrder;
	string inOrder;
	string postOrder;

	cin >> preOrder >> inOrder;

	postOrder = build(preOrder, inOrder);
	cout << postOrder << endl;

	return 0;
}