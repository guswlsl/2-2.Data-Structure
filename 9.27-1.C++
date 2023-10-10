#include <iostream>
#include <set>
using namespace std;

class BinaryNode {
    int data;
    BinaryNode* left;
    BinaryNode* right;

public:
    BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
    : data(val), left(l), right(r) { }
    void setData(int val) { data = val; }
    void setLeft(BinaryNode* l) { left = l; }
    void setRight(BinaryNode* r) { right = r; }
    int getData() { return data; }
    BinaryNode* getLeft() { return left; }
    BinaryNode* getRight() { return right; }
};

class BinaryTree {
    protected:
        BinaryNode* root;

public:
    BinaryTree() : root(NULL) { }
    void setRoot(BinaryNode* node) { root = node; }
    BinaryNode* getRoot() { return root; }
    bool isEmpty() { return root == NULL; }
};

class BinSrchTree : public BinaryTree
{
public:
BinSrchTree(void) { }
~BinSrchTree(void) { }

BinaryNode* search(int key);
BinaryNode* search(BinaryNode* n, int key);

void insert(BinaryNode* n);
void insert(BinaryNode* r, BinaryNode* n);
};

BinaryNode* BinSrchTree::search(int key) {
    return search(root, key);
}

BinaryNode* BinSrchTree::search(BinaryNode* n, int key) {
    if (n == NULL) return NULL;
    if (key == n->getData()) return n;
    else if (key < n->getData()) return search(n->getLeft(), key);
    else return search(n->getRight(), key);
}

void BinSrchTree::insert(BinaryNode* n) {
    if (n == NULL) return;
    if (isEmpty()) root = n;
    else insert(root, n);
}

void BinSrchTree::insert(BinaryNode* r, BinaryNode* n) {
    if (n->getData() == r->getData()) return;
    else if (n->getData() < r->getData()) {
        if (r->getLeft() == NULL) r->setLeft(n);
        else insert(r->getLeft(), n);
    }
    else {
        if (r->getRight() == NULL) r->setRight(n);
        else insert(r->getRight(), n);
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);              

    int N, M, temp;
    set<int> tree;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        tree.insert(temp);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (tree.find(temp) == tree.end()) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
