#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int A[MAX];

void solve() {
    int N, M, S = 0;
    vector<int> arr;
    vector<pr> ans;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr.push_back(i);
    sort(arr.begin(), arr.end(), [](int x, int y) { return A[x] < A[y]; });

    if (M * 2 > N) {
        cout << -1 << '\n';
        return;
    }

    if (M == 0) {
        for (int i = N - 2; i >= 0; i--) {
            ans.push_back({arr[i], arr[N - 1]}), S += A[arr[i]];
            if (S >= A[arr[N - 1]]) {
                for (int j = i - 1; j >= 0; j--)
                    ans.push_back({arr[j], arr[j + 1]});
                break;
            }
        }
        if (S < A[arr[N - 1]]) {
            cout << -1 << '\n';
            return;
        }
    } else
        for (int i = N - 1; i >= M; i--)
            ans.push_back({arr[i], arr[i - M]});

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (pr i : ans)
        cout << i[0] << ' ' << i[1] << '\n';
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