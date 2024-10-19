#include <bits/stdc++.h>

#define MAX 100100
#define MAX_K 210
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<long long, 3> tp;
typedef array<long long, 4> ftp;

class ConvexHullTrick {
  public:
    vector<ftp> F;
    int ftop = 0;

    void insert(tp X) {
        ftp K = {X[0], X[1], 0, X[2]};
        while (!F.empty()) {
            if (F.back()[0] == K[0]) {
                if (F.back()[1] >= K[1])
                    return;
            } else {
                K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
                if (F.back()[2] < K[2])
                    break;
            }
            F.pop_back();
            if (F.size() == ftop)
                --ftop;
        }
        F.push_back(K);
    }

    tp query(int x) {
        while (ftop + 1 < F.size() && F[ftop + 1][2] < x)
            ++ftop;
        return {F[ftop][0] * x + F[ftop][1], F[ftop][3]};
    }

    void clear() {
        F.clear();
        ftop = 0;
    }
};

int A[MAX], sm[MAX], track[MAX][MAX_K];
long long dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    long long res;

    tp val;
    vector<int> ans;
    ConvexHullTrick cht[2];

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sm[i] = sm[i - 1] + A[i];
    }

    for (int i = 0; i <= K; i++) {
        cht[i & 1].clear();

        for (int j = i + 1; j <= N; j++) {
            val = (i ? cht[(i + 1) & 1].query(sm[j]) : tp{0, 0});
            dp[j] = (long long)sm[j] * sm[j] + val[0];
            track[j][i] = val[1];
            cht[i & 1].insert({-2 * sm[j], dp[j] + (long long)sm[j] * sm[j], j});
        }
    }

    res = ((long long)sm[N] * sm[N] - dp[N]) / 2;
    cout << res << '\n';

    while (K--) {
        N = track[N][K + 1];
        ans.push_back(N);
    }

    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << ' ';

    return 0;
}