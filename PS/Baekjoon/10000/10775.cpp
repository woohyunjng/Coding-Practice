#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

bool checked[100100];
int parent[100100];

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

    int G, P, A, res = 0;
    cin >> G >> P;

    for (int i = 1; i <= G; i++)
        parent[i] = i;

    while (P--)
    {
        cin >> A;
        A = find(A);
        if (!A)
            break;
        res++;
        uni(A - 1, A);
    }

    cout << res;

    return 0;
}