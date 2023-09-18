from sys import stdin

N = int(stdin.readline())
arr = [0] + list(map(int, stdin.readline().rstrip().split()))
arr2 = [0 for i in range(N + 1)]
parent = [i for i in range(N + 1)]


def find(i):
    if parent[i] != i:
        parent[i] = find(parent[i])
    return parent[i]


for i in range(1, N + 1):
    arr2[arr[i]] = i
    A, B = find(i), find(arr[i])
    parent[max(A, B)] = min(A, B)

C, M = 0, 0
res = []

for i in range(1, N + 1):
    if i != 1:
        A, B = find(i - 1), find(i)
        if A != B:
            C += 1
            M += 1
            parent[max(A, B)] = min(A, B)
            res.append((arr2[i], arr2[i - 1]))
            arr2[i], arr2[i - 1] = arr2[i - 1], arr2[i]
    if i != N:
        A, B = find(i), find(i + 1)
        if A != B:
            C += 1
            M += 1
            parent[max(A, B)] = min(A, B)
            res.append((arr2[i], arr2[i + 1]))
            arr2[i], arr2[i + 1] = arr2[i + 1], arr2[i]

print(C, M)
for i, j in res:
    print(min(i, j), max(i, j))
