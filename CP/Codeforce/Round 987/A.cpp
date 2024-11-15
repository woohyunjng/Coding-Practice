#include <bits/stdc++.h>
#define int long long

#define MAX 101
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int H[MAX], cnt[MAX];

void solve() {
    int N;
    cin >> N;

    fill(cnt, cnt + N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> H[i];
        cnt[H[i]]++;
    }

    cout << N - *max_element(cnt, cnt + N + 1) << '\n';
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