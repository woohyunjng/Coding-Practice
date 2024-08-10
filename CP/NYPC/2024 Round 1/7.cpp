#include <bits/stdc++.h>
#define int long long
#define MAX 300010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SqrtDecomposition {
  public:
    int N, S, size;
    vector<int> arr, sqrt_arr;

    SqrtDecomposition(int n) : N(n), arr(n + 1, 0), sqrt_arr(n + 1, 0) {}

    void init() {
        S = sqrt(N);
        size = N / S;
        if (N % S)
            size++;
    }

    void update(int pos, int val) {
        sqrt_arr[pos / S] += val - arr[pos];
        arr[pos] = val;
    }

    int query() {
        for (int i = 0; i < size; i++) {
            if (sqrt_arr[i] == 0)
                continue;
            for (int j = 0; j < S; j++) {
                if (arr[i * S + j] != 0)
                    return i * S + j;
            }
        }
        return 0;
    }
};

int arr[MAX], ans[MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, S, A, B, nl, nr, l, r, mx = 0;
    vector<tp> query;

    cin >> N;
    S = sqrt(N);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    SqrtDecomposition tree(mx + 1);
    tree.init();

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> A >> B;
        query.push_back({A, B, i});
    }

    sort(query.begin(), query.end(), [S](tp a, tp b) {
        int af = a[0] / S, bf = b[0] / S;
        if (af == bf)
            return a[1] / S < b[1] / S;
        return af < bf;
    });

    for (int i = query[0][0]; i <= query[0][1]; i++) {
        cnt[arr[i]]++;
        if (cnt[arr[i]] == 1)
            tree.update(arr[i], 1);
        else
            tree.update(arr[i], 0);
    }

    ans[query[0][2]] = tree.query();
    nl = query[0][0], nr = query[0][1];

    for (int i = 1; i < Q; i++) {
        l = query[i][0], r = query[i][1];
        while (nl < l) {
            cnt[arr[nl]]--;
            if (cnt[arr[nl]] == 1)
                tree.update(arr[nl], 1);
            else
                tree.update(arr[nl], 0);
            nl++;
        }
        while (nr > r) {
            cnt[arr[nr]]--;
            if (cnt[arr[nr]] == 1)
                tree.update(arr[nr], 1);
            else
                tree.update(arr[nr], 0);
            nr--;
        }
        while (nl > l) {
            nl--;
            cnt[arr[nl]]++;
            if (cnt[arr[nl]] == 1)
                tree.update(arr[nl], 1);
            else
                tree.update(arr[nl], 0);
        }
        while (nr < r) {
            nr++;
            cnt[arr[nr]]++;
            if (cnt[arr[nr]] == 1)
                tree.update(arr[nr], 1);
            else
                tree.update(arr[nr], 0);
        }

        ans[query[i][2]] = tree.query();
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}
