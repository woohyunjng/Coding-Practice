N = int(input())
K = int(input())

checked = [False for i in range(N + 1)]
line = [[] for i in range(N + 1)]

checked[1] = True

for i in range(K):
    A, B = map(int, input().split())
    line[A].append(B)
    line[B].append(A)


def dfs(P):
    res = 1
    for i in line[P]:
        if not checked[i]:
            checked[i] = True
            res += dfs(i)
    return res
    

print(dfs(1) - 1)
