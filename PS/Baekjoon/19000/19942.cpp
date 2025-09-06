#include <bits/stdc++.h>
using namespace std;

const int MAX = 16;
const int INF = 1e9;

int P[MAX], F[MAX], S[MAX], V[MAX], C[MAX];

vector<int> min(vector<int> X, vector<int> Y) {
    for (int i = 0; i < min(X.size(), Y.size()); i++) {
        if (X[i] != Y[i])
            return X[i] < Y[i] ? X : Y;
    }
    return X.size() < Y.size() ? X : Y;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, MP, MF, MS, MV, ans = INF, VP, VF, VS, VV, VC;
    vector<int> ans_vec, val;

    cin >> N;
    cin >> MP >> MF >> MS >> MV;

    for (int i = 0; i < N; i++)
        cin >> P[i] >> F[i] >> S[i] >> V[i] >> C[i];

    for (int i = 0; i < (1 << N); i++) {
        VP = VF = VS = VV = VC = 0, val.clear();
        for (int j = 0; j < N; j++) {
            if (!(i & (1 << j)))
                continue;
            VP += P[j], VF += F[j], VS += S[j], VV += V[j], VC += C[j];
            val.push_back(j);
        }

        if (VP >= MP && VF >= MF && VS >= MS && VV >= MV && VC <= ans)
            ans_vec = ans == VC ? min(ans_vec, val) : val, ans = VC;
    }

    cout << (ans == INF ? -1 : ans) << '\n';
    if (ans != INF) {
        for (int i : ans_vec)
            cout << i + 1 << ' ';
        cout << '\n';
    }

    return 0;
}