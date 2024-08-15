#include <bits/stdc++.h>
#define int long long
#define MAX 1000100

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int arr[MAX], in[MAX], pre[MAX], cnt;

void get_order(int start, int end) {
    if (start > end)
        return;

    int root = arr[pre[++cnt]];
    get_order(start, root - 1);
    get_order(root + 1, end);
    cout << in[root] << ' ';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, T;
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> pre[i];

        for (int i = 1; i <= N; i++) {
            cin >> in[i];
            arr[in[i]] = i;
        }

        cnt = 0;
        get_order(1, N);
        cout << endl;
    }

    return 0;
}