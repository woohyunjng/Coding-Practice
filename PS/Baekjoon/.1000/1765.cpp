#include <bits/stdc++.h>
#define int long long
#define MAX 1010

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

vector<int> arr_friends[MAX], arr_rivals[MAX];
int parent[MAX], cnt[MAX];

int find(int K)
{
    if (parent[K] != K)
        parent[K] = find(parent[K]);
    return parent[K];
}

void uni(int A, int B)
{
    A = find(A), B = find(B);
    if (A > B)
        swap(A, B);
    parent[B] = A;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, P, Q, res = 0;
    char A;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    while (M--)
    {
        cin >> A >> P >> Q;
        if (A == 'F')
        {
            arr_friends[P].push_back(Q);
            arr_friends[Q].push_back(P);
        }
        else
        {
            arr_rivals[P].push_back(Q);
            arr_rivals[Q].push_back(P);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j : arr_friends[i])
            uni(i, j);
        for (int j : arr_rivals[i])
        {
            for (int k : arr_rivals[j])
                uni(i, k);
        }
    }

    for (int i = 1; i <= N; i++)
        cnt[find(i)]++;

    for (int i = 1; i <= N; i++)
    {
        if (cnt[i])
            res++;
    }

    cout << res;

    return 0;
}