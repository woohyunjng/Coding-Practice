#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    priority_queue<int> pq, res;
    vector<pr> arr_cpu, arr_fr;

    int N, M, K, ans = 0, A, B, X = 0;

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr_cpu.push_back({B, A});
    }
    sort(arr_cpu.begin(), arr_cpu.end());

    for (int i = 1; i <= M; i++) {
        cin >> A >> B;
        arr_fr.push_back({B, A});
    }
    sort(arr_fr.begin(), arr_fr.end());

    for (pr i : arr_cpu) {
        A = i.second, B = i.first;
        while (X < M && arr_fr[X].first <= B)
            pq.push(arr_fr[X].second), X++;

        if (!pq.empty())
            res.push(pq.top() - A), pq.pop();
    }

    while (!res.empty() && res.top() > 0 && K--)
        ans += res.top(), res.pop();

    cout << ans;

    return 0;
}