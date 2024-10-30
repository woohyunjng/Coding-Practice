T = int(input())

for t in range(T):
    S = input().split(",")
    name, time = S[0], int(S[1])

    min = time % 60
    time //= 60

    hour = time % 24
    time //= 24

    day = time % 365
    time //= 365

    year = time

    res = f"{name} -"

    if year:
        res += f" {year} year(s)"
    if day:
        res += f" {day} day(s)"
    if hour:
        res += f" {hour} hour(s)"
    if min:
        res += f" {min} minute(s)"

    print(res)
