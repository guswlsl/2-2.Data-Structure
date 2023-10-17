#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int N, K;
  vector<int> scoville;
  int answer = 0;

  cin >> N;

  for (int i=0; i<N; i++)
  {
    int num;
    cin >> num;
    scoville.push_back(num);
  }

  cin >> K;

  priority_queue<int, vector<int>, greater<int>> 
  pq(scoville.begin(), scoville.end());

  while (pq.top() < K && pq.size() >=2)
  { 
    answer++;
    int first = pq.top(); pq.pop();
    int second = pq.top(); pq.pop();
    pq.push(first + second * 2);
  }

  if (pq.top() < K) answer = -1;

  cout << answer;

  return 0;
}