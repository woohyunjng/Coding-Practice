#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 4> tp;

const int MAX = 100001;
const int BASE = 1000000000;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, minH, Y, N, Q;
    double X;

    vector<int> arr;
    vector<pr> ans;
    pr V;

    vector<tp> hull;
    tp K;

    cin >> H >> minH >> N, H -= minH;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) {
        if (A[x] - B[x] == A[y] - B[y])
            return A[x] > A[y];
        return A[x] - B[x] > A[y] - B[y];
    });

    for (int i : arr) {
        tp K = {A[i] - B[i], B[i], 0, i};
        while (!hull.empty()) {
            if (hull.back()[0] == K[0]) {
                hull.pop_back();
                continue;
            }
            K[2] = ((double)(hull.back()[1] - K[1]) * H / (K[0] - hull.back()[0])) * BASE;
            if (hull.back()[2] < K[2])
                break;
            hull.pop_back();
        }
        hull.push_back(K);
    }

    hull[0][2] = -BASE * BASE;
    for (tp i : hull)
        ans.push_back({i[2], i[3]});

    cin >> Q;
    while (Q--) {
        cin >> X, Y = (X - minH) * BASE;
        V = *prev(upper_bound(ans.begin(), ans.end(), (pr){Y, N + 1}));
        cout << V[1] << '\n';
    }

    return 0;
}