#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq(numbers.begin(), numbers.end());

    for (int i = 0; i < K-1; i++) {
        pq.pop();
    }

    cout << pq.top() << endl;

    return 0;
}
