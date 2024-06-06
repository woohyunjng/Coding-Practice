#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> arr;
    vector<pr> val;
    int N, A, B, C, D;
    string res = "";

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        arr.push_back(A);

        if (!A)
        {
            val.push_back({0, i});
            continue;
        }

        B = 0;
        while (A)
        {
            A /= 10;
            B++;
        }

        A = arr[i], C = 0, D = 0;
        while (C < 10)
        {
            if (B + C > 10)
            {
                int j = B + C - 10;
                while (j--)
                {
                    A /= 10;
                }
                j = 10 - C;
                while (j--)
                    D *= 10;
                D += A;
            }
            else
            {
                int j = B;
                while (j--)
                    D *= 10;
                D += A;
            }
            C += B;
        }
        val.push_back({-D, i});
    }

    sort(val.begin(), val.end());

    bool j = true;
    for (pr i : val)
    {
        if (j && !arr[i.second])
        {
            cout << 0;
            return 0;
        }

        j = false;
        res += to_string(arr[i.second]);
    }
    cout << res;

    return 0;
}