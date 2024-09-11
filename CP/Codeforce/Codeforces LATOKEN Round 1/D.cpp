#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int depth[MAX], parent[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, odd = 0, even = 0;
    cin >> N;

    cout << "? 1" << endl;
    cout.flush();

    for (int i = 1; i <= N; i++) {
        cin >> depth[i];
        if (depth[i] & 1)
            odd++;
        else
            even++;

        if (depth[i] == 1)
            parent[i] = 1;
    }
    even--;

    if (even > odd) {
        for (int i = 2; i <= N; i++) {
            if ((depth[i] & 1) == 0)
                continue;

            cout << "? " << i << endl;
            cout.flush();

            for (int j = 1; j <= N; j++) {
                cin >> K;
                if (K == 1 && depth[j] == depth[i] + 1)
                    parent[j] = i;
                if (K == 1 && depth[j] == depth[i] - 1)
                    parent[i] = j;
            }
        }
    } else {
        for (int i = 2; i <= N; i++) {
            if (depth[i] & 1)
                continue;
            cout << "? " << i << endl;
            cout.flush();

            for (int j = 1; j <= N; j++) {
                cin >> K;
                if (K == 1 && depth[j] == depth[i] + 1)
                    parent[j] = i;
                if (K == 1 && depth[j] == depth[i] - 1)
                    parent[i] = j;
            }
        }
    }

    cout << "!\n";
    for (int i = 2; i <= N; i++)
        cout << i << ' ' << parent[i] << '\n';
    cout.flush();

    return 0;
}