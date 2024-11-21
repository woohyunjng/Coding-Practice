#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, T, res = 0;
    vector<tp> arr;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> T;
        arr.push_back({A + T, i, T});
        arr.push_back({B, i, T});
    }

    sort(arr.begin(), arr.end());

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    A = arr[0][0] - arr[0][2];

    for (tp i : arr) {
        while (!pq.empty() && vst[pq.top().second] == 2)
            pq.pop();
        if (!pq.empty()) {
            T = pq.top().first;
            res += (i[0] - A) / T;
            A = A + (i[0] - A) / T * T;
        }

        if (vst[i[1]] == 0) {
            if (A <= i[0] - i[2])
                res++, A = i[0];
            pq.push({i[2], i[1]}), vst[i[1]] = 1;
        } else if (vst[i[1]] == 1)
            vst[i[1]] = 2;
    }

    cout << res << '\n';

    return 0;
}