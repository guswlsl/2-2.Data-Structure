#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class BinaryNode {
    int data;
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int val) : data(val), left(nullptr), right(nullptr) {}
    int getData() { return data; }
    void setLeft(BinaryNode* l) { left = l; }
    void setRight(BinaryNode* r) { right = r; }
    BinaryNode* getLeft() { return left; }
    BinaryNode* getRight() { return right; }
};

class BinaryTree {
    BinaryNode* root;
public:
    BinaryTree() : root(nullptr) {}
    void setRoot(BinaryNode* r) { root = r; }
    BinaryNode* getRoot() { return root; }

    int minValue(BinaryNode* node);
    int maxValue(BinaryNode* node);
    bool isBST(BinaryNode* node);
};

int BinaryTree::minValue(BinaryNode* node) {
    if (node == NULL) return INT_MAX;
    int value = node->getData();
    int leftMin = minValue(node->getLeft());
    int rightMin = minValue(node->getRight());
    return min(value, min(leftMin, rightMin));
}

int BinaryTree::maxValue(BinaryNode* node) {
    if (node == NULL) return INT_MIN;
    int value = node->getData();
    int leftMax = maxValue(node->getLeft());
    int rightMax = maxValue(node->getRight());
    return max(value, max(leftMax, rightMax));
}

bool BinaryTree::isBST(BinaryNode* node) {
    if (node == NULL) return true;
    if (node->getLeft() != NULL && maxValue(node->getLeft()) >= node->getData()) return false;
    if (node->getRight() != NULL && minValue(node->getRight()) < node->getData()) return false;
    if (!isBST(node->getLeft()) || !isBST(node->getRight())) return false;
    return true;
}

int main() {
    BinaryTree bt;
    int N;
    vector<BinaryNode*> v;
    cin >> N;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) v[i] = new BinaryNode(i);
    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        if (left != '.') v[root - '0']->setLeft(v[left - '0']);
        else v[root - '0']->setLeft(NULL);
        if (right != '.') v[root - '0']->setRight(v[right - '0']);
        else v[root - '0']->setRight(NULL);
        if (i == 0) bt.setRoot(v[root - '0']);
    }
    if (bt.isBST(bt.getRoot())) cout << "1" << endl;
    else cout << "0" << endl;
    return 0;
}