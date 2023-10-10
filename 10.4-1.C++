#include <iostream>

using namespace std;

class BinaryNode {
    int data;
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int val = 0, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
        : data(val), left(l), right(r) {}
    void setData(int val) { data = val; }
    void setLeft(BinaryNode* l) { left = l; }
    void setRight(BinaryNode* r) { right = r; }
    int getData() { return data; }
    BinaryNode* getLeft() { return left; }
    BinaryNode* getRight() { return right; }
    bool isLeaf() { return left == nullptr && right == nullptr; }
};

class BinaryTree {
protected:
    BinaryNode* root;
public:
    BinaryTree() : root(nullptr) {}
    void inorder() { inorder(root); }
    void inorder(BinaryNode* node) {
        if (node != nullptr) {
            inorder(node->getLeft());
            cout << node->getData() << " ";
            inorder(node->getRight());
        }
    }
};

class BinSrchTree : public BinaryTree {
public:
    BinSrchTree(void) { }
    ~BinSrchTree(void) { }

    BinaryNode* search(int key) {
        return search(root, key);
    }
    BinaryNode* search(BinaryNode* n, int key) {
        if (n == nullptr) return nullptr;
        if (key == n->getData()) return n;
        if (key < n->getData()) return search(n->getLeft(), key);
        else return search(n->getRight(), key);
    }

    void insert(BinaryNode* n) {
        if (root == nullptr) root = n;
        else insert(root, n);
    }
    void insert(BinaryNode* r, BinaryNode* n) {
        if (n->getData() < r->getData()) {
            if (r->getLeft() == nullptr) r->setLeft(n);
            else insert(r->getLeft(), n);
        }
        else {
            if (r->getRight() == nullptr) r->setRight(n);
            else insert(r->getRight(), n);
        }
    }

    void remove(int key) {
        BinaryNode* parent = nullptr;
        BinaryNode* node = root;
        while (node != nullptr && node->getData() != key) {
            parent = node;
            node = (key < node->getData()) ? node->getLeft() : node->getRight();
        }
        if (node == nullptr) {
            cout << "Key not found\n";
            return;
        }
        remove(parent, node);
    }
    void remove(BinaryNode* parent, BinaryNode* node);
};

void BinSrchTree::remove(BinaryNode* parent, BinaryNode* node) {
    // case 1: 제거 노드가 단말인 경우
    if (node->isLeaf()) { 
        if (parent == NULL) root = NULL;
        else {
            if (parent->getLeft() == node) 
                parent->setLeft(NULL);
            else
                parent->setRight(NULL);
        }
    }
    // case 2: 삭제하려는 노드가 서브트리 중 하나만 가지고 있는 경우
    else if (node->getLeft() == NULL || node->getRight() == NULL) {
        BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();
        if (node == root) 
            root = child;
        else {
            if (parent->getLeft() == node) 
                parent->setLeft(child);
            else
                parent->setRight(child);
        }
    }
    // case 3: 삭제하려는 노드가 두 개의 서브트리 모두 가지고 있는 경우
    else {
        BinaryNode* succp = node;
        BinaryNode* succ = node->getRight();
        while (succ->getLeft() != NULL) {
            succp = succ;
            succ = succ->getLeft();
        }
        if (succp->getLeft() == succ) 
            succp->setLeft(succ->getRight());
        else 
            succp->setRight(succ->getRight());
        node->setData(succ->getData());
        node = succ;
    }
    delete node;
}

int main() {
    BinSrchTree bst;
    int N, key;
    char cmd;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cmd >> key;
        switch (cmd) {
        case 'I':
            bst.insert(new BinaryNode(key));
            break;
        case 'D':
            bst.remove(key);
            break;
        }
    }

    bst.inorder();

    return 0;
}