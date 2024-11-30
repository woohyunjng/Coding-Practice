#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, st, en, mid, res;
    cin >> N >> M;

    C[0] = INF;
    for (int i = 1; i <= N; i++)
        cin >> A[i], C[i] = min(C[i - 1], A[i]);
    for (int i = 1; i <= M; i++) {
        cin >> X;
        st = 1, en = N, res = -1;

        while (st <= en) {
            mid = st + en >> 1;
            if (C[mid] <= X)
                en = mid - 1, res = mid;
            else
                st = mid + 1;
        }

        cout << res << '\n';
    }

    return 0;
}