#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N, res = 0;
    cin >> N;

    string A, B;
    cin >> A;
    cin >> B;

    for (int i = 0; i < N; i++)
    {
        int X = max(A[i] - '0', B[i] - '0'), Y = min(A[i] - '0', B[i] - '0');
        res += min(X - Y, 10 + Y - X);
    }

    cout << res;
}