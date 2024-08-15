#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1234567891
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 1;
    cin >> N;

    vector<pr> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), [&](pr a, pr b) {
        return (a.first - 1) * b.second <= (b.first - 1) * a.second;
    });

    for (pr i : arr)
        res = (res * i.first % MOD + i.second) % MOD;
    cout << res;

    return 0;
}