# 9 / 100

N, K = map(int, input().split())
arr = list(map(int, input().split()))

mx, res_S, res_E = 0, -1, -1

for i in range(N):
    for j in range(i, N):
        new_arr = arr.copy()
        for k in range(i, j + 1):
            new_arr[k] += K

        res = 0
        for k in range(N):
            for l in range(k + 1, N):
                if new_arr[k] >= new_arr[l]:
                    res += 1
        if res >= mx:
            mx = res
            res_S, res_E = i + 1, j + 1

print(res_S, res_E)
