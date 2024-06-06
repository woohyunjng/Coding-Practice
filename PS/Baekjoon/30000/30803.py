from sys import stdin

N = int(input())
arr = list(map(int, stdin.readline().rstrip().split()))
opn = [True for i in range(N)]

Q = int(input())

current = sum(arr)
print(current)

for i in range(Q):
    line = list(map(int, stdin.readline().rstrip().split()))
    if line[0] == 1:
        if opn[line[1] - 1]:
            current += line[2] - arr[line[1] - 1]
        arr[line[1] - 1] = line[2]
    else:
        if opn[line[1] - 1]:
            current -= arr[line[1] - 1]
        else:
            current += arr[line[1] - 1]
        opn[line[1] - 1] = not opn[line[1] - 1]
    print(current)
