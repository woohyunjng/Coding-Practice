#include <bits/stdc++.h>
#define int long long
#define ll __int128_t

using namespace std;

const int MAX = 500001;
const int INF = 2'000'000'000'000'000'000;

int P[MAX];
ll V[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, ans;
    ll L, R, X;
    bool flag, chk;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> P[i];

        if (*max_element(P, P + N) == 0) {
            cout << 0 << '\n';
            continue;
        }

        for (ll st = 1, en = INF, md; st <= en;) {
            md = st + en >> 1;
            L = R = X = 0, flag = true, chk = false;

            fill(S, S + N + 1, 0);
            for (int i = 0; i < N; i++)
                V[i] = P[i] - (md - 1) * min(i, N - 1 - i);
            for (int i = 0; i < N / 2; i++)
                R = max(R, (V[i] - (N - 1 - i) + N - 1 - i * 2 - 1) / (N - 1 - i * 2));
            for (int i = (N + 1) / 2; i < N; i++)
                L = max(L, (V[i] - i + N - 1 - (N - 1 - i) * 2 - 1) / (N - 1 - (N - 1 - i) * 2));

            flag &= L + R <= md, L = max(L, md - 1 - R);
            for (int i = 0; i < N; i++) {
                V[i] = P[i] - (L * i + R * (N - 1 - i)), X = max(V[i], X), S[0]++;
                if (V[i] > 0)
                    S[max((ll)0, i - V[i] + 1)]--, S[min((ll)N, i + V[i])]++;
            }
            flag &= L + R < md || X == 0;

            for (int i = 0; i < N; i++)
                S[i + 1] += S[i], chk |= S[i] == N;
            flag &= chk;

            if (flag)
                ans = (int)md, en = md - 1;
            else
                st = md + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}