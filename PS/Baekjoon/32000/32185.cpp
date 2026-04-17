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

    int N, M, A, B, C, cur;
    priority_queue<pr> pq;
    vector<int> res;

    cin >> N >> M;

    M--;

    cin >> A >> B >> C;
    cur = A + B + C;
    res.push_back(0);

    for (int i = 1; i <= N; i++) {
        cin >> A >> B >> C;
        pq.push({A + B + C, i});
    }

    while (M && !pq.empty()) {
        tie(A, B) = pq.top(), pq.pop();
        if (cur < A)
            continue;

        res.push_back(B);
        M--;
    }

    for (int i : res)
        cout << i << ' ';

    return 0;
}