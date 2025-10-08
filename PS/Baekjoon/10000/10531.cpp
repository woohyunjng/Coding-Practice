#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef complex<double> cpx;
const double PI = acos(-1);

const int MAX = 200001;

int A[MAX];

void FFT(vector<cpx> &v, bool inv) {
    int S = v.size(), K;
    cpx W, WK, A, B;
    double ang;

    for (int i = 1, j = 0; i < S; i++) {
        K = S >> 1;
        while (j >= K)
            j -= K, K >>= 1;
        j += K;
        if (i < j)
            swap(v[i], v[j]);
    }

    for (int i = 1; i < S; i <<= 1) {
        ang = 2 * PI / (i << 1) * (inv ? -1 : 1), W = {cos(ang), sin(ang)};
        for (int j = 0; j < S; j += i << 1) {
            WK = {1, 0};
            for (int k = 0; k < i; k++) {
                A = v[j + k], B = v[j + k + i] * WK;
                v[j + k] = A + B, v[j + k + i] = A - B;
                WK *= W;
            }
        }
    }

    if (inv)
        for (int i = 0; i < S; i++)
            v[i] /= S;
}

vector<int> mul(vector<int> A, vector<int> B) {
    int S = 2;
    vector<cpx> vA(A.begin(), A.end()), vB(B.begin(), B.end()), vC;
    vector<int> res;

    while (S < A.size() + B.size())
        S <<= 1;
    vA.resize(S), vB.resize(S), vC.resize(S);

    FFT(vA, false), FFT(vB, false);
    for (int i = 0; i < S; i++)
        vC[i] = vA[i] * vB[i];
    FFT(vC, true);

    res.resize(S);
    for (int i = 0; i < S; i++)
        res[i] = round(vC[i].real());

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S = 0, ans = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i], S = max(S, A[i]);

    vector<int> arr(S + 1, 0), res;
    for (int i = 0; i < N; i++)
        arr[A[i]]++;

    res = mul(arr, arr);

    cin >> M;
    while (M--) {
        cin >> S;
        ans += (S + 1 <= res.size() && res[S] > 0) || (S + 1 <= arr.size() && arr[S] > 0);
    }

    cout << ans << '\n';

    return 0;
}