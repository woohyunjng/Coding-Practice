from sys import stdin

N, Q = map(int, stdin.readline().rstrip().split())
arr = list(map(int, input().split()))

for i in range(Q):
    query = list(map(lambda x: int(x) - 1, stdin.readline().rstrip().split()))
    if query[0] == 0:
        print(sum(arr[query[1] : query[2] + 1]))
        arr[query[1]], arr[query[2]] = arr[query[2]], arr[query[1]]
    else:
        print(sum(arr[query[1] : query[2] + 1]) - sum(arr[query[3] : query[4] + 1]))
