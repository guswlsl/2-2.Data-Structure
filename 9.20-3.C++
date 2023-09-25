#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<bool> visited;
vector<vector<int>> tree;

void DFS(int current_node) {
    visited[current_node] = true;
    
    for (int child : tree[current_node]) {
        if (!visited[child]) {
            parent[child] = current_node;
            DFS(child);
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    visited.resize(N + 1);
    tree.resize(N + 1);
    parent.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);    
        tree[n2].push_back(n1);
    }

    DFS(1);  

    for (int i = 2; i <= N; i++)     
        cout << parent[i] << '\n';

    return 0;
}
