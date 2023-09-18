#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <iomanip> 
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<int> values(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    stack<float> st;
    for (char ch : s) {
        if ('A' <= ch && ch <= 'Z') {
            st.push((float)values[ch - 'A']);
        } else { 
            float op2 = st.top(); st.pop();
            float op1 = st.top(); st.pop();

            switch (ch) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
                case '/':
                    st.push(op1 / op2);
                    break;
            }
        }
    }
    cout << fixed << setprecision(2) << st.top() << "\n";
    return 0;
}
