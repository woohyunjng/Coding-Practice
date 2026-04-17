arr = [0, 1]
N = int(input())

for i in range(20):
    arr.append(arr[-1] + arr[-2])

print(arr[N])
