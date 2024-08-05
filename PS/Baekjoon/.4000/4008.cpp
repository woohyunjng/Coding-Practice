#include <bits/stdc++.h>
#define int long long
#define MAX 1000100
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class ConvexHullTrick {
  public:
    vector<tp> F;
    int ftop = 0;

    void insert(pr X) {
        tp K = {X.first, X.second, 0};
        while (!F.empty()) {
            K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
            if (F.back()[2] < K[2])
                break;
            F.pop_back();
            if (F.size() == ftop)
                --ftop;
        }
        F.push_back(K);
    }

    int query(int x) {
        while (ftop + 1 < F.size() && F[ftop + 1][2] < x)
            ++ftop;
        return F[ftop][0] * x + F[ftop][1];
    }
};

int arr[MAX], sm[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C, res = 0;
    cin >> N;
    cin >> A >> B >> C;

    ConvexHullTrick cht;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        res += B * arr[i];
        sm[i] = sm[i - 1] + arr[i];
    }

    cht.insert({0, 0});

    for (int i = 1; i <= N; i++) {
        dp[i] = cht.query(sm[i]) + A * sm[i] * sm[i] + C;
        cht.insert({-2 * A * sm[i], dp[i] + A * sm[i] * sm[i]});
    }

    cout << dp[N] + res;

    return 0;
}