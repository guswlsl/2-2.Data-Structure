#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, k, j = 1;
    stack<int> s; //주어진 수열을 재현하기 위해 사용하는 스택
    vector<char> result; // '+'와 '-' 연산의 결과를 저장하는 벡터

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;

        while (j <= k) { // 작거나 같을 동안 스택에 숫자를 push
            s.push(j++);
            result.push_back('+');
        }

        if (s.top() == k) { //스택의 top이 k와 같다면 스택에서 pop
            s.pop();
            result.push_back('-');
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (char c : result) { //결과 벡터에 저장된 '+'와 '-' 연산 출력
        cout << c << '\n';
    }
    
    return 0;
}
