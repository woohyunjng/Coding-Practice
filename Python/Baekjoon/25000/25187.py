from sys import stdin

N, M, Q = map(int, stdin.readline().rstrip().split())
arr = list(map(int, stdin.readline().rstrip().split()))
parent = [i for i in range(N)]
group = [0 for i in range(N)]


def find(i):
    if parent[i] != i:
        parent[i] = find(parent[i])

    return parent[i]


for i in range(M):
    u, v = map(int, stdin.readline().rstrip().split())
    U, V = find(u - 1), find(v - 1)
    parent[max(U, V)] = min(U, V)

for i in range(N):
    j = find(i)
    group[j] += 1 if arr[i] else -1

for i in range(Q):
    K = int(stdin.readline().rstrip())
    k = find(K - 1)

    print(int(group[k] > 0))
