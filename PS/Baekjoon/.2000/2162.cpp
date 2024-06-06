#include <bits/stdc++.h>
#define int long long
#define MAX 3100

using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> double_pair;
typedef tuple<int, int, int> tp;

int parent[MAX], cnt[MAX];
double_pair arr[MAX];

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

int CCW(pr A, pr B, pr C)
{ // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

bool is_intersect(pr A, pr B, pr C, pr D)
{ // A-B C-D 교차판정
    int AtoC = CCW(A, B, C) * CCW(A, B, D);
    int CtoA = CCW(C, D, A) * CCW(C, D, B);

    if (AtoC == 0 && CtoA == 0)
    {
        if (A > B)
            swap(A, B);
        if (C > D)
            swap(C, D);

        return C <= B && A <= D;
    }

    return AtoC <= 0 && CtoA <= 0;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, P, res = 0, mx = 0;
    pr A, B;
    bool K;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A.first >> A.second >> B.first >> B.second;
        parent[i] = i;
        arr[i] = {A, B};
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            K = is_intersect(arr[i].first, arr[i].second, arr[j].first, arr[j].second);
            if (!K)
                continue;
            uni(i, j);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        P = find(i);
        if (P == i)
            res++;
        cnt[P]++;
        mx = max(mx, cnt[P]);
    }

    cout << res << '\n'
         << mx;

    return 0;
}