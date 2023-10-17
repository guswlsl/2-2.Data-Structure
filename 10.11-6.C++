#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<bool> visited(N, false);
    int id = 0;

    while (N--) {
        char ch;
        int num;
        cin >> ch >> num;

        if (ch == 'I') {
            maxHeap.emplace(num, id);
            minHeap.emplace(num, id);
            visited[id] = true;
            id++;
        } 
        else if (ch == 'D' && num == 1 && !maxHeap.empty()) {
            // 최대값 삭제
            while (!maxHeap.empty() && !visited[maxHeap.top().second]) {
                maxHeap.pop();
            }
            if (!maxHeap.empty()) {
                visited[maxHeap.top().second] = false;
                maxHeap.pop();
            }
        } 
        else if (ch == 'D' && num == -1 && !minHeap.empty()) {
            // 최소값 삭제
            while (!minHeap.empty() && !visited[minHeap.top().second]) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                visited[minHeap.top().second] = false;
                minHeap.pop();
            }
        }
    }

    // 큐 동기화
    while (!maxHeap.empty() && !visited[maxHeap.top().second]) {
        maxHeap.pop();
    }
    while (!minHeap.empty() && !visited[minHeap.top().second]) {
        minHeap.pop();
    }

    if (minHeap.empty() || maxHeap.empty()) {
        cout << "0,0" << endl;
    } else {
        cout << maxHeap.top().first << " " << minHeap.top().first << endl;
    }

    return 0;
}
