#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int X[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 0, last;

    vector<pr> arr;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
        cin >> X[i];
    for (int i = 1; i <= M; i++)
        cin >> A[i];

    for (int i = 1; i <= M; i++)
        arr.push_back({X[i], A[i]});
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    last = N;

    for (pr i : arr) {
        if (i.first + i.second - 1 > last) {
            cout << -1 << '\n';
            return 0;
        }

        res += (last * 2 - i.first * 2 - i.second + 1) * i.second / 2;
        last = last - i.second;
    }

    res = last == 0 ? res : -1;
    cout << res << '\n';

    return 0;
}