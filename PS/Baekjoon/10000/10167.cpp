#include <bits/stdc++.h>
#define int long long
#define MAX 3000

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> gold;
typedef tuple<int, int, int, int> tp;

gold arr[5000];
tp tree[2 * MAX + 1];
int N;

tp get_sum(tp A, tp B)
{
    bool a = (get<0>(A) == 0 && get<1>(A) == 0 && get<2>(A) == 0 && get<0>(A) == 0),
         b = (get<0>(B) == 0 && get<1>(B) == 0 && get<2>(B) == 0 && get<0>(B) == 0);
    if (a && b)
        return {0, 0, 0, 0};
    else if (a)
        return B;
    else if (b)
        return A;
    return {
        max(get<0>(A), get<3>(A) + get<0>(B)),
        max(get<1>(B), get<1>(A) + get<3>(B)),
        max(max(get<2>(A), get<2>(B)), get<1>(A) + get<0>(B)),
        get<3>(A) + get<3>(B)};
}

void update(int node, int start, int end, int index, int value)
{
    if (index < start || end < index)
        return;
    else if (start == end)
    {
        tree[node] = (tp){
            get<0>(tree[node]) + value,
            get<1>(tree[node]) + value,
            get<2>(tree[node]) + value,
            get<3>(tree[node]) + value};
    }
    else
    {
        update(node << 1, start, (start + end) >> 1, index, value);
        update(node << 1 | 1, ((start + end) >> 1) + 1, end, index, value);
        tree[node] = get_sum(tree[node << 1], tree[node << 1 | 1]);
    }
}

tp query(int node, int start, int end, int left, int right)
{
    if (left <= start && end <= right)
        return tree[node];
    else if (right < start || end < left)
        return {0, 0, 0, 0};
    else
    {
        tp left_val = query(node << 1, start, ((start + end) >> 1), left, right);
        tp right_val = query(node << 1 | 1, ((start + end) >> 1) + 1, end, left, right);
        return get_sum(left_val, right_val);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, K, A, B, C, res = -1;
    vector<int> X, Y;

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        arr[i] = {A, B, C};
        X.push_back(A);
        Y.push_back(B);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    K = X.size();
    N = Y.size();
    vector<pr> Xgold[K];

    for (gold i : arr)
        Xgold[lower_bound(X.begin(), X.end(), get<0>(i)) - X.begin()].push_back({lower_bound(Y.begin(), Y.end(), get<1>(i)) - Y.begin(),
                                                                                 get<2>(i)});

    for (int i = 0; i < K; i++)
    {
        for (int j = i; j < K; j++)
        {
            for (pr k : Xgold[j])
                update(1, 0, N - 1, k.first, k.second);
            res = max(res, get<2>(query(1, 0, N - 1, 0, N - 1)));
        }
        for (int j = i; j < K; j++)
        {
            for (pr k : Xgold[j])
                update(1, 0, N - 1, k.first, -k.second);
        }
    }

    cout << res;
    return 0;
}