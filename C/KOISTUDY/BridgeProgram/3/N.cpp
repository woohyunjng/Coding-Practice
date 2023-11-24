#include <iostream>
using namespace std;

int main()
{
    int N, A, B, C;
    bool able = false;
    cin >> N;
    cin >> A >> B;

    for (int i = 0; i < N - 2; i++)
    {
        cin >> C;
        if (A + B > C)
            able = true;
        A = B, B = C;
    }

    cout << (able ? "No" : "Yes");
}