arr = []
for i in range(19):
    arr.append(list(map(int, input().split())))

N = int(input())

for i in range(N):
    A, B = map(int, input().split())
    for j in range(19):
        arr[j][B - 1] = int(not arr[j][B - 1])
        arr[A - 1][j] = int(not arr[A - 1][j])
print("\n".join(map(lambda x: " ".join(map(str, x)), arr)))
