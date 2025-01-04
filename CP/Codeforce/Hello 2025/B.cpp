#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef pair<int, int> pr;

int A[MAX];
map<int, int> cnt;

void solve() {
    int N, K, res = 1;
    cin >> N >> K;

    cnt.clear();
    for (int i = 1; i <= N; i++)
        cin >> A[i], cnt[A[i]]++;

    vector<int> arr;
    for (pr i : cnt)
        arr.push_back(i.second);
    sort(arr.begin(), arr.end()), N = arr.size();

    for (int i = 0; i < N - 1; i++) {
        if (K < arr[i]) {
            res = N - i;
            break;
        } else
            K -= arr[i];
    }

    cout << res << '\n';
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