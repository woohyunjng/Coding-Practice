#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int get_res(int N)
{
    int M = 0, K = 0, res = 0;
    while (N)
    {
        res += (N >> 1) * (1LL << K);
        if (N & 1)
        {
            res += M + 1;
            M += (1LL << K);
        }
        N >>= 1;
        K++;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B;
    cin >> A >> B;

    cout << get_res(B) - get_res(A - 1);

    return 0;
}