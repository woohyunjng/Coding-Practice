#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];

void solve() {
    int N, res = INF;
    vector<int> arr;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A + 1, A + N + 1);

    for (int i = 1; i <= N - 1; i++)
        arr.push_back(A[i] + A[i + 1]);

    for (int i = N; i >= 1; i--) {
        arr.pop_back();
        res = min(res, N - i + upper_bound(arr.begin(), arr.end(), A[i]) - arr.begin());
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}