#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> A, B, C, D, AB, CD;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, a, b, c, d, lw, up, res = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    for (int i : CD)
    {
        lw = lower_bound(AB.begin(), AB.end(), -i) - AB.begin();
        up = upper_bound(AB.begin(), AB.end(), -i) - AB.begin();
        if (AB[lw] != -i)
            continue;
        res += up - lw;
    }

    cout << res;

    return 0;
}