#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<bool> removed;
int remove_node, result = 0;

void DFS(int current_node) {
    if (removed[current_node]) return;

    bool isLeaf = true;

    for (int child : tree[current_node]) {
        if (!removed[child]) {
            DFS(child);
            isLeaf = false;
        }
    }

    if (isLeaf) result++;
}

int main() {
    int N;
    cin >> N;

    tree.resize(N);
    removed.resize(N, false);

    int root;
    for (int i = 0; i < N; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) {
            root = i;
        } else {
            tree[parent].push_back(i);
        }
    }

    cin >> remove_node;
    removed[remove_node] = true;

    DFS(root);
    cout << result;

    return 0;
}
