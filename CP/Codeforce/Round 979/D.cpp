#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], S[MAX], sm[MAX];

void solve() {
    int N, Q, X, cnt = 0;
    string s;

    cin >> N >> Q;

    fill(sm, sm + N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> X;
        sm[min(i, X)]++;
        sm[max(i, X)]--;
    }

    cin >> s;
    S[0] = -1, S[N + 1] = -1;
    for (int i = 1; i <= N; i++) {
        S[i] = s[i - 1] == 'R';
        sm[i] += sm[i - 1];
    }

    for (int i = 1; i < N; i++)
        cnt += (sm[i] == 0 || (S[i] == 1 || S[i + 1] == 0));

    while (Q--) {
        cin >> X;

        cnt -= (sm[X - 1] == 0 || (S[X - 1] == 1 || S[X] == 0));
        cnt -= (sm[X] == 0 || (S[X] == 1 || S[X + 1] == 0));
        S[X] ^= 1;

        cnt += (sm[X - 1] == 0 || (S[X - 1] == 1 || S[X] == 0));
        cnt += (sm[X] == 0 || (S[X] == 1 || S[X + 1] == 0));

        cout << (cnt == N - 1 ? "YES" : "NO") << '\n';
    }
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