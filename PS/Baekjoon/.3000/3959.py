from sys import stdin
from math import atan, degrees

T = int(input())
g = 9.81


for i in range(T):
    j, p, H, L = map(int, stdin.readline().rstrip().split())

    if 8 * j * (2 * p + H) < L**2:
        l = (4 * j * p * L**2 / (L**2 - 8 * H * j)) ** 0.5
        tan_h = -4 * H / L**2 * l
    elif 8 * j * (2 * p + H) >= L**2 > (H + p) * 4 * j:
        l = (
            8 * H * j * L
            + 2
            * L
            * (j * (8 * H**2 * j - H * L**2 + 8 * H * p * j + p * L**2)) ** 0.5
        ) / (8 * H * j + L**2)
        tan_h = 2 * H * (2 * l / L**2 - 2 / L)
    else:
        l = ((H + p) * 4 * j) ** 0.5
        tan_h = 0

    def get_height(l):
        return -(l**2) / (4 * j) + H + p

    def get_velocity(h):
        return (2 * g * (j + p + H - h)) ** 0.5

    height = get_height(l)
    velocity = get_velocity(height)
    tan_f = -l / (2 * j)

    ski_and_ball_degree = abs(degrees(atan(abs((tan_h - tan_f) / (1 + tan_h * tan_f)))))

    print(l, velocity, ski_and_ball_degree)
