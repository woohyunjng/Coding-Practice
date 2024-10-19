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
    int N;
    bool check = false;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] - '0';

    check = check || A[1] || A[N];

    for (int i = 1; i < N; i++)
        check = check || (A[i] && A[i + 1]);

    cout << (check ? "YES" : "NO") << '\n';
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