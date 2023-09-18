#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    queue<int> q;

    // 1부터 N까지의 사람을 큐에 넣음
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    cout << "<";

    // 큐의 사이즈가 1보다 큰 동안 반복
    while (q.size() > 1) {
        // M-1명의 사람은 큐의 앞에서 빼서 큐의 뒤로 보냄
        for (int i = 0; i < M - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        // M번째 사람은 큐에서 제거하고 출력
        cout << q.front() << ", ";
        q.pop();
    }

    // 마지막 사람 출력
    cout << q.front() << ">";

    return 0;
}