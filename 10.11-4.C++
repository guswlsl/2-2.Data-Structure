#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int> pd;

    for (int i = 0; i < N; i++)
    {
        int slime;
        cin >> slime;
        pd.push(slime);
    }

    int score = 0;

    while (pd.size() > 1)
    {
        int firstpd = pd.top();
        pd.pop();

        int secondpd = pd.top();
        pd.pop();

        int Slime = firstpd + secondpd;
        pd.push(Slime);

        score += firstpd * secondpd;
    }

    cout << score << endl;

    return 0;
}
