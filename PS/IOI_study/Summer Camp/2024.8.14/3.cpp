#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, P, X, cnt, res = true;
    cin >> N;
    cin >> K >> P;

    arr[P] = K;
    checked[K] = true;

    stack<int> st;
    queue<int> q;

    cnt = 1;
    X = P;
    while (X > 1) {
        X >>= 1;
        st.push(X);
    }

    while (!st.empty()) {
        X = st.top(), st.pop();
        while (checked[cnt])
            cnt++;
        arr[X] = cnt;
        checked[cnt] = true;
    }

    if (arr[P] < arr[P >> 1]) {
        cout << -1;
        return 0;
    }

    cnt = K + 1;
    q.push(P);

    while (!q.empty()) {
        X = q.front(), q.pop();
        if (X << 1 <= N) {
            while (checked[cnt])
                cnt++;
            arr[X << 1] = cnt;
            checked[cnt] = true;
            q.push(X << 1);
        }
        if ((X << 1 | 1) <= N) {
            while (checked[cnt])
                cnt++;
            arr[X << 1 | 1] = cnt;
            checked[cnt] = true;
            q.push(X << 1 | 1);
        }
    }

    cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (!arr[i]) {
            while (checked[cnt])
                cnt++;
            arr[i] = cnt;
            checked[cnt] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i] > N)
            res = false;
    }

    if (!res)
        cout << -1;
    else
        for (int i = 1; i <= N; i++)
            cout << arr[i] << '\n';

    return 0;
}