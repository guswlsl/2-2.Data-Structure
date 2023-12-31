#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N * N; i++)
    {
        int num;
        cin >> num;

        pq.push(num);
        
        if (pq.size() > N)
        {
            pq.pop();
        }
    }

    cout << pq.top() << endl;

    return 0;
}
