#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef complex<double> cpx;
const double PI = acos(-1);

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

    int N, M;
    string A, B;
    vector<int> vA, vB, res;

    cin >> A >> B, N = A.size(), M = B.size();

    for (int i = N - 1; i >= 0; i--)
        vA.push_back(A[i] - '0');
    for (int i = M - 1; i >= 0; i--)
        vB.push_back(B[i] - '0');

    res = mul(vA, vB);
    for (int i = 0; i < res.size(); i++) {
        if (res[i] >= 10) {
            if (i + 1 == res.size())
                res.push_back(0);
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }

    while (res.size() > 1 && res.back() == 0)
        res.pop_back();
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    cout << '\n';

    return 0;
}