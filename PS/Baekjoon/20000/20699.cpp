#include <bits/stdc++.h>
using namespace std;

const int MAX = 250001;

typedef array<int, 3> tp;

int ans[MAX][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B;
    cin >> A >> B;
    int N = A + B, cnt = 2, X, L, R;
    bool chk = true;
    tp K;

    vector<tp> st;

    st.push_back({1, A, B});
    while (!st.empty()) {
        K = st.back(), st.pop_back();
        X = K[0], A = K[1], B = K[2];

        if (A + B == 1)
            ans[X][2] = A == 1 ? 1 : 2;
        else if (A + B == 2) {
            if (B == 2)
                chk = false;
            else if (B == 1)
                ans[X][2] = 2, ans[X][0] = cnt, ans[cnt++][2] = 1;
            else
                ans[X][2] = 1, ans[X][0] = cnt, ans[cnt++][2] = 1;
        } else if (B & 1) {
            L = cnt++, R = cnt++;
            ans[X][2] = 2, ans[X][0] = L, ans[X][1] = R;
            st.push_back({L, A / 2, B / 2}), st.push_back({R, A - A / 2, B / 2});
        } else if (A == 0)
            chk = false;
        else if (B > 0) {
            L = cnt++, R = cnt++;
            ans[X][0] = L, ans[X][1] = R;
            if (A & 1) {
                ans[X][2] = 2;
                st.push_back({L, A - A / 2, (B - 1) / 2}), st.push_back({R, A / 2, (B - 1) - (B - 1) / 2});
            } else {
                ans[X][2] = 1;
                st.push_back({L, (A - 1) - (A - 1) / 2, B / 2}), st.push_back({R, (A - 1) / 2, B / 2});
            }
        } else {
            L = cnt++, R = cnt++;
            ans[X][2] = 1, ans[X][0] = L, ans[X][1] = R;
            st.push_back({L, (A - 1) - (A - 1) / 2, 0}), st.push_back({R, (A - 1) / 2, 0});
        }
    }

    if (chk) {
        for (int i = 1; i <= N; i++)
            cout << ans[i][2] << ' ' << ans[i][0] << ' ' << ans[i][1] << '\n';
    } else
        cout << -1 << '\n';

    return 0;
}