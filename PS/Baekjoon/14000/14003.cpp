#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> LIS(vector<int> arr)
{
    vector<int> X, Y, res;

    for (int i : arr)
    {
        if (X.empty() || X.back() < i)
        {
            X.push_back(i);
            Y.push_back(X.size() - 1);
        }
        else
        {
            Y.push_back(lower_bound(X.begin(), X.end(), i) - X.begin());
            X[Y.back()] = i;
        }
    }

    int K = X.size() - 1;
    for (int i = Y.size() - 1; i >= 0; i--)
    {
        if (Y[i] == K)
        {
            K--;
            res.push_back(arr[i]);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A;
    vector<int> arr, res;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        arr.push_back(A);
    }

    res = LIS(arr);
    cout << res.size() << '\n';
    for (int i : res)
        cout << i << ' ';

    return 0;
}