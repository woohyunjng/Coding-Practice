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

    int N, A;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        arr.push_back(A);
    }

    vector<int> copied(arr);
    sort(copied.begin(), copied.end());
    copied.erase(unique(copied.begin(), copied.end()), copied.end());

    for (int i = 0; i < N; i++)
        cout << lower_bound(copied.begin(), copied.end(), arr[i]) - copied.begin() + 1 << ' ';

    return 0;
}