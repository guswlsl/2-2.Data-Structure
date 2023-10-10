#include <iostream>
#include <sstream> 
using namespace std;

class BinaryNode {
    int data;
    BinaryNode* left;
    BinaryNode* right;

public:
    BinaryNode(int val) : data(val), left(NULL), right(NULL) {}
    int getData() { return data; }
    BinaryNode* getLeft() { return left; }
    BinaryNode* getRight() { return right; }
    void setLeft(BinaryNode* l) { left = l; }
    void setRight(BinaryNode* r) { right = r; }
};

class BinSrchTree {
    BinaryNode* root;

public:
    BinSrchTree() : root(NULL) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

private:
    BinaryNode* insert(BinaryNode* r, int key) {
        if (!r) return new BinaryNode(key);

        if (key < r->getData()) {
            r->setLeft(insert(r->getLeft(), key));
        } else if (key > r->getData()) {
            r->setRight(insert(r->getRight(), key));
        }
        return r;
    }

    void postorder(BinaryNode* r) {
        if (r) {
            postorder(r->getLeft());
            postorder(r->getRight());
            cout << r->getData() << '\n';
        }
    }
};

int main() {
    BinSrchTree tree;
    int num;
    string line;

    while (getline(cin, line)) {
        stringstream ss(line);
        if (ss >> num) {
            tree.insert(num);
        } else {
            break;
        }
    }

    tree.postorder();

    return 0;
}
