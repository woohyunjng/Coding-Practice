from bisect import bisect_left

N = int(input())
arr = list(map(int, input().split()))
length_front = [1 for i in range(N)]

for i in range(N):
    for j in range(i):
        if arr[j] < arr[i]:
            length_front[i] = max(length_front[i], length_front[j] + 1)

arr = list(reversed(arr))
length_back = [1 for i in range(N)]

for i in range(N):
    for j in range(i):
        if arr[j] < arr[i]:
            length_back[i] = max(length_back[i], length_back[j] + 1)

mx = -1
for i in range(N):
    mx = max(mx, length_front[i] + length_back[N - 1 - i] - 1)

print(mx)
