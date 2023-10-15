from sys import stdin

N, P = map(int, stdin.readline().rstrip().split())
arr = [0]
parent = [i for i in range(N + 1)]

for i in range(N):
    arr.append(int(stdin.readline()))

lines = []
for i in range(P):
    S, E, L = map(int, stdin.readline().rstrip().split())
    lines.append((L * 2 + arr[S] + arr[E], S, E))
lines = list(sorted(lines))


def find(i):
    if i != parent[i]:
        parent[i] = find(parent[i])
    return parent[i]


def uni(i, j):
    i, j = find(i), find(j)
    parent[max(i, j)] = min(i, j)


res = 0
for i, j, k in lines:
    j, k = find(j), find(k)
    if j != k:
        uni(j, k)
        res += i
print(res + min(arr[1:]))
