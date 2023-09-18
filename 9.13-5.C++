#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;			
    queue<int> q;	// 큐 선언

    cin >> N;
    for (int i = 1; i <= N; i++) 	// 큐에 1부터 N까지의 카드를 저장
        q.push(i);

    while (q.size() > 1)	// 카드가 1장 남을 때까지 반복
    {
        cout << q.front() << " ";  // 버릴 카드를 먼저 출력
        q.pop();		// 맨 앞 카드를 버림

        q.push(q.front());		// 그 다음 맨 앞 카드를 맨 뒤로 옮김
        q.pop();		// 그 카드를 큐에서 제거
    }

    cout << q.front();		// 마지막으로 남은 1장의 카드를 출력

    return 0;
}