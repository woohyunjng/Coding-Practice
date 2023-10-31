C = int(input())
for i in range(C):
    score = list(map(int, input().split()))[1:]
    avg = sum(score) / len(score)
    res = 0

    for i in score:
        res += int(i > avg)

    print(f"{(res / len(score) * 100): .3f}%")
