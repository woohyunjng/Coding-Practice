arr, mx = [], -1
for i in range(5):
    arr.append(input())
    mx = max(mx, len(arr[-1]))

res = ""
for i in range(mx):
    for j in range(5):
        if len(arr[j]) > i:
            res += arr[j][i]

print(res)
