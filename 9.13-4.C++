#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N), result(N, -1); // 입력받을 수열 N 저장, result는 -1로 초기화
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<int> s; // 인덱스를 저장할 스택

    for (int i = 0; i < N; i++) {
        // 스택이 비어있지 않고, 현재 원소가 스택의 top 위치에 있는 원소보다 크다면 오큰수이므로 저장
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = arr[i]; //스택의 top에 있는 원소의 오큰수로 현재 원소를 저장
            s.pop();
        }
        s.push(i); // 현재 인덱스를 스택에 넣기
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
