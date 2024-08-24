#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int query[MAX], val[MAX], sparse[MAX][20];
pr lectures[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, K, res;
    cin >> N >> M;

    vector<pr> arr;
    vector<int> x_comp;
    stack<pr> interval;

    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        arr.push_back({X, Y});
        lectures[i] = {X, Y};
        x_comp.push_back(X);
    }

    sort(x_comp.begin(), x_comp.end());
    x_comp.erase(unique(x_comp.begin(), x_comp.end()), x_comp.end());
    sort(arr.begin(), arr.end());

    fill(val, val + x_comp.size() + 2, INF);

    for (int i = N; i >= 1; i--) {
        X = lower_bound(x_comp.begin(), x_comp.end(), arr[i - 1].first) - x_comp.begin() + 1;
        val[X] = min(val[X], arr[i - 1].second);
    }

    sparse[x_comp.size() + 1][0] = INF;
    for (int i = x_comp.size(); i >= 1; i--) {
        sparse[i][0] = min(sparse[i + 1][0], val[i]);
        for (int j = 1; j < 20; j++) {
            X = lower_bound(x_comp.begin(), x_comp.end(), sparse[i][j - 1] + 1) - x_comp.begin() + 1;
            sparse[i][j] = sparse[X][j - 1];
            if (!sparse[i][j])
                break;
        }
    }

    while (M--) {
        cin >> K;
        for (int i = 1; i <= K; i++)
            cin >> query[i];
        res = K;

        interval.push({0, lectures[query[1]].first});
        interval.push({lectures[query[K]].second, 1000000000});
        for (int i = 1; i < K; i++)
            interval.push({lectures[query[i]].second, lectures[query[i + 1]].first});

        while (!interval.empty()) {
            X = interval.top().first, Y = interval.top().second;
            interval.pop();

            X = lower_bound(x_comp.begin(), x_comp.end(), X + 1) - x_comp.begin() + 1;

            for (int i = 19; i >= 0; i--) {
                if (sparse[X][i] != 0 && sparse[X][i] < Y) {
                    res += 1 << i;
                    X = lower_bound(x_comp.begin(), x_comp.end(), sparse[X][i] + 1) - x_comp.begin() + 1;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}