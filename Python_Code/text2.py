import math


class Point:
    def __init__(self, radian, Ylab):
        self.radian = radian
        self.Ylab = Ylab


def Reflect_Weight(p):
    half_long = math.cos(p.radian) / 2*math.sin(2 * p.radian)
    high = p.Ylab + half_long
    low = p.Ylab - half_long

    if 150 <= low or high <= 130:
        return 0
    if low < 130 < high <= 150:
        return (high - 130) / (high - low)
    if high > 150 > low >= 130:
        return (150 - low) / (high - low)
    if 130 <= low and high <= 150:
        return 1
    if low < 130 and 150 < high:
        return 20 / (high - low)
