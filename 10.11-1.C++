#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int N, num;
  priority_queue<int, vector<int>, greater<int>>   
  pq;
  vector<int> v;

  cin >> N;
  for (int I = 0; I < N; I++)
  {
	cin >> num;
	if (num == 0)
	{ 
	  if (pq.empty()) v.push_back(0); //비어있으면 0츌력
	  else
	  {
	    v.push_back(pq.top());
	    pq.pop();
	  }
	} 
   	else pq.push(num);
  }
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
}