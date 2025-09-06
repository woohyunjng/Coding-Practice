#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M = -1, L, R, ans = INF, C;
    vector<int> st;

    cin >> N >> L >> R, C = -R;
    for (int i = 0; i < N; i++)
        cin >> A[i], B[i] = -1;

    if (2 * R * N < L)
        ans = -1;

    for (int i = 0; i < N; i++) {
        if (C + R >= A[i] - R)
            C = A[i];
        else if (2 * R * i >= A[i] - R)
            M = A[i] - R * 2, C = A[i];
        else {
            M = A[i], C = B[i] = 2 * R * i + R;
            while (!st.empty() && A[st.back()] >= B[i])
                B[i] = min(B[i], B[st.back()]), st.pop_back();
            st.push_back(i);
        }
    }
    if (C + R < L)
        M = L - R;

    if (M == -1)
        ans = min(ans, 0ll);

    if (M != -1) {
        C = M;
        for (int i : st) {
            ans = min(ans, C + M - B[i]);
            C += (A[i] - B[i]) * 2;
        }
        ans = min(ans, C);
    }

    cout << ans << '\n';

    return 0;
}