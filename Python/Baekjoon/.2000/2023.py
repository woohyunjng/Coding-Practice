N = int(input())


def dfs(num, k):
    if k == N:
        print(num)
        return

    for i in range(1, 10, 2):
        j = num * 10 + i
        for x in range(2, int(j**0.5) + 1):
            if not j % x:
                break
        else:
            dfs(j, k + 1)


for i in [2, 3, 5, 7]:
    dfs(i, 1)
