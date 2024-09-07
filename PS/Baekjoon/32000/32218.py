N = int(input())
arr = list(map(int, input().split()))
temp = [0] * N
res = 1

while all([arr[i] == 0 for i in range(N)]) == False:
    for i in range(N):
        val = 0
        for j in range(i, N):
            if arr[j] > arr[i]:
                val += 1
        temp[i] = val
    arr = temp[:]
    res += 1

print(res)
