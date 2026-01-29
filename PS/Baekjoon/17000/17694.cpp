#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int X[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, T, ans = 0, PL, PR, L, R, LV, RV;
    bool flag, chk;

    cin >> N >> K >> T;
    for (int i = 1; i <= N; i++)
        cin >> X[i];

    for (int st = 1, en = (X[N] + 2 * T - 1) / (2 * T), md; st <= en;) {
        md = st + en >> 1, flag = true;
        for (int i = 1; i <= N; i++)
            A[i] = X[i] - 2 * i * T * md;
        PL = PR = K;

        for (int i = 1; i < K; i++)
            if (A[i] > A[PL])
                PL = i;
        for (int i = K + 1; i <= N; i++)
            if (A[i] < A[PR])
                PR = i;

        L = R = K, LV = RV = A[K];
        while (PL <= L || R <= PR) {
            chk = false;
            while (A[L] >= RV && L >= PL)
                LV = max(LV, A[L--]), chk = true;
            while (A[R] <= LV && R <= PR)
                RV = min(RV, A[R++]), chk = true;
            if (!chk) {
                flag &= chk;
                break;
            }
        }

        L = 1, R = N, LV = A[1], RV = A[N];
        while (L <= PL || PR <= R) {
            chk = false;
            while (A[L] >= RV && L <= PL)
                LV = max(LV, A[L++]), chk = true;
            while (A[R] <= LV && R >= PR)
                RV = min(RV, A[R--]), chk = true;
            if (!chk) {
                flag &= chk;
                break;
            }
        }

        if (flag)
            ans = md, en = md - 1;
        else
            st = md + 1;
    }

    cout << ans << '\n';
}