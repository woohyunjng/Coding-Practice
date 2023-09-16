#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A[10001], B[10001][3] = {0}, res = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (i == 0)
        {
            B[i][0] = A[i];
        }
        else
        {
            if (B[i - 1][0] < A[i])
            {
                B[i][1] = B[i - 1][0];
                A[i] -= B[i - 1][0];
                B[i - 1][0] = 0;

                if (B[i - 1][1] < A[i])
                {
                    B[i][2] = B[i - 1][1];
                    B[i][0] = A[i] - B[i - 1][1];
                    B[i - 1][1] = 0;
                }
                else
                {
                    B[i][2] = A[i];
                    B[i - 1][1] -= A[i];
                }
            }
            else
            {
                B[i][1] = A[i];
                B[i - 1][0] -= A[i];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        res += B[i][0] * 3 + B[i][1] * 5 + B[i][2] * 7;
    }

    cout << res;
}
