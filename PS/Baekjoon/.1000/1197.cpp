#include <bits/stdc++.h>
#define MAX 10010
#define int long long

using namespace std;
typedef array<int, 3> tp;

int parent[MAX];
vector<tp> link;

void clear(int K)
{
    for (int i = 1; i <= K; i++)
        parent[i] = i;
}

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

int mst()
{
    int res = 0, A, B;
    sort(link.begin(), link.end());

    for (tp i : link)
    {
        A = find(i[1]), B = find(i[2]);
        if (A == B)
            continue;
        uni(A, B);
        res += i[0];
    }

    return res;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E, A, B, C;
    cin >> V >> E;

    clear(V);

    while (E--)
    {
        cin >> A >> B >> C;
        link.push_back({C, A, B});
    }

    cout << mst();

    return 0;
}