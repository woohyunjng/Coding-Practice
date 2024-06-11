#include <bits/stdc++.h>
#define int long long
using namespace std;

int LIS(vector<int> arr)
{
    vector<int> X, Y;

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

    return X.size();
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        arr.push_back(A);
    }

    cout << LIS(arr);

    return 0;
}