#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int D[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, R;
    cin >> N >> R;

    for (int i = 1; i <= N; i++) {
        cin >> D[i] >> A[i];
        if (D[i] == 1 && 1600 <= R && R <= 2799)
            R += A[i];
        else if (D[i] == 2 && 1200 <= R && R <= 2399)
            R += A[i];
    }

    cout << R << '\n';

    return 0;
}