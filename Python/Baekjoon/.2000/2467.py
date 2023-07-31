N = int(input())
arr = list(map(int, input().split()))

mn, res_i, res_j = 1e10, 0, 0

i, j = 0, N - 1

while i < j:
    if abs(arr[i] + arr[j]) < mn:
        res_i, res_j = arr[i], arr[j]
        mn = abs(arr[i] + arr[j])
    if j - i == 1:
        break

    if arr[i] + arr[j] > 0:
        j -= 1
    else:
        i += 1

print(res_i, res_j)
