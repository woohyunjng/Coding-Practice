#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;
typedef tuple<int, int, int> tp;

bool checked[100100];
int parent[1100];

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

    int N, A, B, res = 0;
    cin >> N;

    for (int i = 1; i <= 1000; i++)
        parent[i] = i;

    vector<pr> arr;
    for (int i = 1; i <= N; i++)
    {
        cin >> A >> B;
        arr.push_back({-B, -A});
    }

    sort(arr.begin(), arr.end());
    for (pr i : arr)
    {
        A = -i.first, B = -i.second;
        B = find(B);
        if (B)
        {
            res += A;
            uni(B - 1, B);
        }
    }

    cout << res;
    return 0;
}