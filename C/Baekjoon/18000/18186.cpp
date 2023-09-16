#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    long A[10001], X[10001][3] = {0}, B, C;
    long res = 0;

    cin >> N;
    cin >> B >> C;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (i == 0)
        {
            X[i][0] = A[i];
        }
        else
        {
            if (B > C)
            {
                if (X[i - 1][0] < A[i])
                {
                    X[i][1] = X[i - 1][0];
                    A[i] -= X[i - 1][0];
                    X[i - 1][0] = 0;

                    if (X[i - 1][1] < A[i])
                    {
                        X[i][2] = X[i - 1][1];
                        X[i][0] = A[i] - X[i - 1][1];
                        X[i - 1][1] = 0;
                    }
                    else
                    {
                        X[i][2] = A[i];
                        X[i - 1][1] -= A[i];
                    }
                }
                else
                {
                    X[i][1] = A[i];
                    X[i - 1][0] -= A[i];
                }
            }
            else
            {
                X[i][0] = A[i];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        res += X[i][0] * B + X[i][1] * (B + C) + X[i][2] * (B + 2 * C);
    }

    cout << res;
}
