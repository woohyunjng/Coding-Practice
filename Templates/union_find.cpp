#include <bits/stdc++.h>
#define MAX 1000
#define int long long

using namespace std;
typedef pair<int, int> pr;

int parent[MAX];

int subst(int A, int B) { return A * MAX + B; }
pr to_pair(int K) { return {K / MAX, K % MAX}; }

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