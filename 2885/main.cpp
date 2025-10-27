#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
using namespace std;


bool isSameTree(const vector<int>& pTree, int pIdx, const vector<int>& qTree, int qIdx);


bool isSubtreeHelper(const vector<int>& rootTree, int rootIdx, const vector<int>& subTree) {

    bool rootIsNull = (rootIdx >= rootTree.size() || rootTree[rootIdx] == -1);

    if (rootIsNull) {
        return false;
    }

    if (isSameTree(rootTree, rootIdx, subTree, 0)) {
        return true;
    }

    return isSubtreeHelper(rootTree, 2 * rootIdx + 1, subTree) || isSubtreeHelper(rootTree, 2 * rootIdx + 2, subTree);
}


bool isSameTree(const vector<int>& pTree, int pIdx, const vector<int>& qTree, int qIdx) {

    bool pIsNull = (pIdx >= pTree.size() || pTree[pIdx] == -1);

    bool qIsNull = (qIdx >= qTree.size() || qTree[qIdx] == -1);

    if (pIsNull && qIsNull) {
        return true;
    }

    if (pIsNull || qIsNull || pTree[pIdx] != qTree[qIdx]) {
        return false;
    }

    return isSameTree(pTree, 2 * pIdx + 1, qTree, 2 * qIdx + 1) && isSameTree(pTree, 2 * pIdx + 2, qTree, 2 * qIdx + 2);
}


bool isSubtree(const vector<int>& rootTree, const vector<int>& subTree) {

    bool subIsEmpty = subTree.empty() || (subTree.size() == 1 && subTree[0] == -1);
    if (subIsEmpty) {
        return true; 
    }

    bool rootIsEmpty = rootTree.empty() || (rootTree.size() == 1 && rootTree[0] == -1);
    if (rootIsEmpty) {
        return false; 
    }

    return isSubtreeHelper(rootTree, 0, subTree);
}


void readTree(vector<int>& tree) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string valStr;
    while (ss >> valStr) {
        tree.push_back(stoi(valStr));
    }
}


int main() {
    vector<int> rootTree;
    vector<int> subTree;

    readTree(rootTree);
    readTree(subTree);

    bool result = isSubtree(rootTree, subTree);

    cout << (result ? "true" : "false") << endl;

    return 0;
}