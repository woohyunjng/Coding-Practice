M = int(input())
N = 0
arr = []

K = 0
while M > 0:
    arr.append([M % 3, K])
    N += M % 3
    K += 1
    M //= 3

arr = arr[::-1]
print(N)

for i, j in arr:
    for k in range(i):
        print(j, end=" ")
