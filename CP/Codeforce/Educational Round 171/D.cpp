#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], sm[MAX], sm_2[MAX], sm_c[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, st, en, md, l, r, res = 0, X;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sm[i] = sm[i - 1] + A[i];
    }

    for (int i = 1; i <= N; i++)
        sm_2[i] = sm_2[i - 1] + A[i] * (N - i + 1);

    for (int i = 1; i <= N; i++)
        sm_c[i] = sm_c[i - 1] + sm_2[N] - sm_2[i - 1];

    cin >> Q;
    while (Q--) {
        cin >> L >> R;

        st = 0, en = N;
        while (st <= en) {
            md = st + en >> 1;
            if (N * (N + 1) / 2 - L + 1 > md * (md + 1) / 2)
                st = md + 1;
            else {
                en = md - 1;
                l = md;
            }
        }

        st = 0, en = N;
        while (st <= en) {
            md = st + en >> 1;
            if (N * (N + 1) / 2 - R + 1 > md * (md + 1) / 2)
                st = md + 1;
            else {
                en = md - 1;
                r = md;
            }
        }

        res = sm_c[N - r] - sm_c[N - l];

        X = L - (N * (N + 1) / 2 - l * (l + 1) / 2) - 1;
        res -= sm_2[N - l + X] - sm_2[N - l] - (N - (N - l + X)) * (sm[N - l + X] - sm[N - l]);

        X = R - (N * (N + 1) / 2 - r * (r + 1) / 2);
        res += sm_2[N - r + X] - sm_2[N - r] - (N - (N - r + X)) * (sm[N - r + X] - sm[N - r]);

        cout << res << '\n';
    }

    return 0;
}