N, M = map(int, input().split())
min_arr, pls_arr = [], []
arr = list(map(int, input().split()))

for i in arr:
    if i < 0:
        min_arr.append(i)
    else:
        pls_arr.append(i)

min_arr = list(map(abs, sorted(min_arr)))
pls_arr = list(sorted(pls_arr, reverse=True))

go = [
    min_arr[-(len(min_arr) % M)] if len(min_arr) % M else 0,
    pls_arr[-(len(pls_arr) % M)] if len(pls_arr) % M else 0,
]
for i in range(len(min_arr) // M):
    go.append(min_arr[M * i])
for i in range(len(pls_arr) // M):
    go.append(pls_arr[M * i])

go = list(sorted(go))
print(sum(go) * 2 - go[-1])
