#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    queue<int> q;
    q.push(1);
    checked[1] = true;

    while (!q.empty()) {
        A = q.front(), q.pop();
        cout << A << ' ';

        for (int i : arr[A]) {
            if (checked[i])
                continue;
            checked[i] = true;
            q.push(i);
        }
    }

    return 0;
}