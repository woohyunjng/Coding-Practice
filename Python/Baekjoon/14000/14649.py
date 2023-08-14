P = int(input())
N = int(input())
arr = [0 for i in range(101)]

for i in range(N):
    X, Y = input().split()
    if Y == "R":
        for j in range(int(X) + 1, 101):
            arr[j] = (arr[j] + 1) % 3
    else:
        for j in range(int(X) - 1, 0, -1):
            arr[j] = (arr[j] + 1) % 3

a, b, c = 0, 0, 0
for i in range(1, 101):
    if arr[i] == 0:
        a += 1
    elif arr[i] == 1:
        b += 1
    else:
        c += 1

print("{:.2f}".format(P * a / 100))
print("{:.2f}".format(P * b / 100))
print("{:.2f}".format(P * c / 100))
