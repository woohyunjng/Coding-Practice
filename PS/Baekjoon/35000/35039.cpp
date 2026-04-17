#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MAX_C = 27;

int C[MAX][MAX_C], V[MAX_C];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans;
    bool flag;
    string S;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < S.size(); j++)
            C[i][S[j] - 'A']++, V[S[j] - 'A']++;
    }

    for (int i = 0; i < N; i++) {
        flag = true, ans = 10000000000;
        for (int j = 0; j < MAX_C; j++)
            V[j] -= C[i][j];
        for (int j = 0; j < MAX_C; j++) {
            flag &= V[j] * M >= C[i][j];
            if (V[j] != 0)
                ans = min(ans, (V[j] * M - C[i][j]) / V[j]);
        }
        for (int j = 0; j < MAX_C; j++)
            V[j] += C[i][j];
        cout << (!flag ? -1 : ans) << ' ';
    }
    cout << '\n';

    return 0;
}