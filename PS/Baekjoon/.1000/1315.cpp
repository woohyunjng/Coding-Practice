#include <bits/stdc++.h>
#define int long long

#define MAX 51
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, STR[MAX], INT[MAX], PNT[MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, res = 0, cur = 0;

    cin >> N;

    vector<int> st, in;

    for (int i = 1; i <= N; i++) {
        cin >> STR[i] >> INT[i] >> PNT[i];
        st.push_back(STR[i]);
        in.push_back(INT[i]);
    }

    sort(st.begin(), st.end());
    sort(in.begin(), in.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    in.erase(unique(in.begin(), in.end()), in.end());

    A = st.size(), B = in.size();

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            cur = 0;
            if (i == 0 && j == 0) {
                for (int k = 1; k <= N; k++) {
                    if (STR[k] <= 1 || INT[k] <= 1) {
                        cur++;
                        dp[i][j] += PNT[k];
                    }
                }
            } else {
                if ((i != 0 && st[i] - st[i - 1] <= dp[i - 1][j]) || (j != 0 && in[j] - in[j - 1] <= dp[i][j - 1])) {
                    cur = 0;
                    for (int k = 1; k <= N; k++) {
                        if (STR[k] <= st[i] || INT[k] <= in[j]) {
                            cur++;
                            dp[i][j] += PNT[k];
                        }
                    }
                    dp[i][j] -= st[i] + in[j] - 2;
                }
            }
            res = max(res, cur);
        }
    }

    cout << res;

    return 0;
}