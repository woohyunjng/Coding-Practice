#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int res = 0, a, b, c, def = 1;
    int k[10001] = {}, fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
    vector<int> arr(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
        k[arr[i]]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        def *= fac[k[i]];
    }

    sort(arr.begin(), arr.end());
    do
    {
        bool val = true;
        for (int i = 1; i <= 8; i++)
        {
            a = arr[(i - 1) % 8], b = arr[i % 8], c = arr[(i + 1) % 8];
            val = val && (2 * a * a * c * c < (a * b + b * c) * (a * b + b * c));
        }
        if (val)
            res++;
    } while (next_permutation(arr.begin(), arr.end()));

    cout << res * def;

    return 0;
}