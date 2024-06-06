N = int(input())
dice = list(map(int, input().split()))

three = min(
    [
        dice[0] + dice[1] + dice[2],
        dice[0] + dice[1] + dice[3],
        dice[0] + dice[2] + dice[4],
        dice[0] + dice[3] + dice[4],
        dice[5] + dice[1] + dice[2],
        dice[5] + dice[1] + dice[3],
        dice[5] + dice[2] + dice[4],
        dice[5] + dice[3] + dice[4],
    ]
)
two = min(
    [
        dice[0] + dice[1],
        dice[0] + dice[2],
        dice[0] + dice[3],
        dice[0] + dice[4],
        dice[5] + dice[1],
        dice[5] + dice[2],
        dice[5] + dice[3],
        dice[5] + dice[4],
        dice[1] + dice[2],
        dice[2] + dice[4],
        dice[4] + dice[3],
        dice[3] + dice[1],
    ]
)
one = min(dice)

if N >= 2:
    print(4 * three + 4 * (2 * N - 3) * two + (N - 2) * (5 * N - 6) * one)
else:
    print(sum(dice) - max(dice))
