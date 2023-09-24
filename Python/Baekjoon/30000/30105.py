from collections import defaultdict

N = int(input())
arr = list(map(int, input().split()))
ind = defaultdict(lambda: -1)

for i in range(N):
    ind[arr[i]] = i

res = []
for i in range(1, N):
    mn = arr[i] - arr[0]
    checked = [False for i in range(N)]

    for j in range(N):
        if checked[j]:
            if ind[arr[j] + mn] != -1:
                checked[ind[arr[j] + mn]] = True
        else:
            if ind[arr[j] + mn] == -1:
                break
            checked[ind[arr[j] + mn]] = True
            checked[j] = True
    else:
        res.append(mn)

print(len(res))
print(" ".join(map(str, res)))
