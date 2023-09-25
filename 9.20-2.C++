#include <iostream>
#include <vector>
using namespace std;

class BinaryNode
{
    int data;
    BinaryNode* left;
    BinaryNode* right;

public:
    BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
    : data(val), left(l), right(r) { }
    ~BinaryNode() { }
    void setData(int val) { data = val; }
    void setLeft(BinaryNode* l) { left = l; }
    void setRight(BinaryNode* r) { right = rusage_info_v; }
    int getData() { return data; }
    BinaryNode* getLeft() { return left; }
    BinaryNode* getRight() { return right; }
    bool isOperator() { 
        return data == '+' || data == '-'; 
    }
};

int evaluate(BinaryNode* node) { 
    if (node == NULL) return 0;
    if (!node->isOperator()) return node->getData();
    
    int op1 = evaluate(node->getLeft());
    int op2 = evaluate(node->getRight());
    
    switch (node->getData()) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        default: return 0;
    }
}

int main() {
    int N;
    cin >> N;

    vector<BinaryNode*> nodes(2*N - 1);  

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nodes[i] = new BinaryNode(num);
    }

    for (int i = N; i < 2*N - 1; i++) {
        nodes[i] = new BinaryNode();
    }

    for (int i = N; i < 2*N - 1; i++) {
        char op;
        int left, right;
        cin >> op >> left >> right;
        nodes[i]->setData(op);
        nodes[i]->setLeft(nodes[left - 1]);
        nodes[i]->setRight(nodes[right - 1]);
    }

    cout << evaluate(nodes[2*N - 2]) << endl; 

    for (BinaryNode* node : nodes) {
        delete node;
    }

    return 0;
}
