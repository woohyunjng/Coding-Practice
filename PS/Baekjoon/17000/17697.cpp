#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
const int MAX_LOG = 20;

int A[MAX], L[MAX][MAX_LOG], R[MAX][MAX_LOG];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, Q, X, Y, ans, V,
        XL, XR, YL, YR;
    vector<int> st;

    cin >> N >> K >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i], L[i][0] = R[i][0] = i;

    for (int i = 1; i <= N; i++) {
        while (!st.empty() && A[st.back()] <= A[i])
            R[st.back()][0] = i, st.pop_back();
        st.push_back(i);
    }

    st.clear();
    for (int i = N; i >= 1; i--) {
        while (!st.empty() && A[st.back()] <= A[i])
            L[st.back()][0] = i, st.pop_back();
        st.push_back(i);
    }

    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 1; j <= N; j++) {
            L[j][i] = min(L[L[j][i - 1]][i - 1], L[R[j][i - 1]][i - 1]);
            R[j][i] = max(R[R[j][i - 1]][i - 1], R[L[j][i - 1]][i - 1]);
        }

    while (Q--) {
        cin >> X >> Y, ans = 0;
        if (X > Y)
            swap(X, Y);
        XL = XR = X, YL = YR = Y;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            V = max(R[XL][i], R[XR][i]);
            if (V < YL)
                XL = min(L[XL][i], L[XR][i]), XR = V, ans += 1 << i;
        }
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            V = min(L[YL][i], L[YR][i]);
            if (V > XR)
                YR = max(R[YL][i], R[YR][i]), YL = V, ans += 1 << i;
        }
        cout << ans << '\n';
    }

    return 0;
}