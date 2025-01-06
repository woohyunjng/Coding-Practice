#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int in[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B;
        arr[A].push_back(B);
        in[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (!in[i])
            pq.push(i);
    }

    while (!pq.empty()) {
        A = pq.top(), pq.pop();
        cout << A << ' ';

        for (int i : arr[A]) {
            in[i]--;
            if (!in[i])
                pq.push(i);
        }
    }

    return 0;
}