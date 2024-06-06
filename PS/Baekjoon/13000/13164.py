N, K = map(int, input().split())
arr = list(map(int, input().split()))

sub_arr = []
for i in range(N - 1):
    sub_arr.append(arr[i + 1] - arr[i])

sub_arr = list(sorted(sub_arr))[: N - K]
print(sum(sub_arr))
