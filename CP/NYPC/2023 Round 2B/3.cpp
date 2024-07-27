#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool current[MAX], checked[MAX];
vector<int> arr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, S, res = 0, A, B, C, D;

    cin >> N >> M >> K >> S;
    for (int i = 1; i <= S; i++) {
        cin >> A;
        current[A] = true;
    }

    while (M--) {
        cin >> A >> B >> C >> D;
    }

    queue<int> q;
    q.push(1);
    checked[1] = true;

    cout << res;

    return 0;
}