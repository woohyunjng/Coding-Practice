from sys import stdin

N = int(stdin.readline())
arr = list(map(int, stdin.readline().rstrip().split()))
all_min = min(arr)

arr = [(arr[i], i) for i in range(N)]
arr = list(sorted(arr))

comp_arr = [0 for i in range(N)]
checked = [False for i in range(N)]
for i in range(N):
    comp_arr[arr[i][1]] = i

res = 0
for i in range(N):
    if checked[i]:
        continue

    x = i
    ln = 0
    val, mn = 0, 1e12

    while not checked[comp_arr[x]]:
        checked[comp_arr[x]] = True
        x = comp_arr[x]
        mn = min(mn, arr[x][0])
        val += arr[x][0]
        ln += 1

    res += min(mn * (ln - 2), all_min * (ln + 1) + mn) + val

print(res)
