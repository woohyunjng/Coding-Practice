# 100 (0:22)

T = int(input())
for i in range(T):
    h, m = map(int, input().split(":"))
    tp = "AM"
    if h >= 12:
        if h > 12:
            h -= 12
        tp = "PM"
    if h == 0:
        h = 12
    print(f"{str(h).rjust(2, '0')}:{str(m).rjust(2, '0')} {tp}")
