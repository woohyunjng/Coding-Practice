#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class ConvexHullTrick {
  public:
    vector<tp> F;
    int top = 0, ftop = 0;

    void insert(tp K) {
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

int A[MAX], B[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, top = 0, ftop = 0;
    cin >> N;

    ConvexHullTrick cht;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];

    cht.insert({B[1], 0, 0});

    for (int i = 2; i <= N; i++) {
        dp[i] = cht.query(A[i]);
        cht.insert({B[i], dp[i], 0});
    }

    cout << dp[N];

    return 0;
}