#include <bits/stdc++.h>
#define int long long
#define MAX 300100

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

int parent[MAX];

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

    int N, A, B;
    cin >> N;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= N - 2; i++)
    {
        cin >> A >> B;
        uni(A, B);
    }

    A = find(1);
    for (int i = 2; i <= N; i++)
    {
        B = find(i);
        if (A != B)
        {
            cout << 1 << ' ' << i;
            break;
        }
    }

    return 0;
}