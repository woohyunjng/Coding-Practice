#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];

void solve() {
    int N, sm = 0, res = INF, X, Y, cnt[2] = {0};
    vector<pr> arr;
    vector<int> one, two;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] == 1)
            cnt[0]++;
        else if (A[i] == 2)
            cnt[1]++;
    }

    for (int i = 1; i <= N - cnt[1]; i++) {
        if (A[i] == 2)
            two.push_back(i);
        else if (A[i] == 1)
            one.push_back(i);
    }
    reverse(one.begin(), one.end());

    for (int i = N; i > N - cnt[1]; i--) {
        if (A[i] == 2)
            continue;
        else if (A[i] == 1) {
            Y = two.back(), two.pop_back();
            arr.push_back({i, Y});
            A[i] = 2, A[Y] = 1;
        } else {
            X = *one.begin();
            arr.push_back({X, i});
            A[X] = 0, A[i] = 1;
            one.erase(X);
            Y = two.back(), two.pop_back();
            arr.push_back({i, Y});
            A[i] = 2, A[Y] = 1;
            one.insert(Y);
        }
    }

    two.clear();
    for (int i = 1; i <= N - cnt[1] - cnt[0]; i++)
        if (A[i] == 1)
            two.push_back(i);

    for (int i = N - cnt[1]; i > N - cnt[1] - cnt[0]; i--) {
        if (A[i] == 1)
            continue;
        else {
            Y = two.back(), two.pop_back();
            arr.push_back({i, Y});
            A[i] = 1, A[Y] = 0;
        }
    }

    cout << arr.size() << '\n';
    for (pr i : arr)
        cout << i.first << ' ' << i.second << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}