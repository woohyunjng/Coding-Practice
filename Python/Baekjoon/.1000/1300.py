N = int(input())
k = int(input())

left, right = 1, k
res = 0

while left <= right:
    mid = (left + right) // 2
    val = 0

    for i in range(1, N + 1):
        val += min(mid // i, N)

    if val >= k:
        res = mid
        right = mid - 1
    else:
        left = mid + 1

print(res)
