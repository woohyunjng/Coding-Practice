#include <bits/stdc++.h>
#define MAX 1000
#define int long long

using namespace std;
typedef array<int, 3> tp;

int parent[MAX];
vector<tp> link;

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
        ;
        uni(A, B);
        res += i[0];
    }

    return res;
}