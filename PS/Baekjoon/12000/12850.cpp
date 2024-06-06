#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

int K[8][8] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}},
    first[8][8], second[8][8], res_matrix[8][8], res[8][8];

void mul()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int val = 0;
            for (int k = 0; k < 8; k++)
            {
                val += (first[i][k] * second[k][j]);
                val %= MOD;
            }
            res_matrix[i][j] = val;
        }
    }
}

void fpow(int N)
{
    bool is_first = true;

    while (N)
    {
        if (N & 1)
        {
            if (is_first)
            {
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        res[i][j] = K[i][j];
                    }
                }
                is_first = false;
            }
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        first[i][j] = K[i][j];
                        second[i][j] = res[i][j];
                    }
                }
                mul();
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                        res[i][j] = res_matrix[i][j];
                }
            }
        }

        N >>= 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                first[i][j] = K[i][j];
                second[i][j] = K[i][j];
            }
        }
        mul();
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                K[i][j] = res_matrix[i][j];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int D;
    cin >> D;
    fpow(D);
    cout << res[0][0];

    return 0;
}