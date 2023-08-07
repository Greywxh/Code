import math

PI = 3.14159265358979


class Point:
    def __init__(self):
        self.X = 0.0  # 中点横坐标
        self.Y = 0.0  # 中点纵坐标
        self.Slope = 0.0  # 对应点与前一个点构成直线的斜率
        self.radian = 0.0  # 锐角弧度数---2倍的α
        self.Ylab = 0.0  # 在y轴交点坐标


P = [Point() for i in range(300)]
x0, y0 = 0.0, 0.0  # 前一个点的坐标
xt, yt = 0.0, 0.0  # 当前点的坐标
for i in range(300):
    Rad = (i + 1) / 300.0
    xt = 300.0 * math.sin(Rad)
    yt = 300.0 * (1 - math.cos(Rad))
    P[i].Slope = (yt - y0) / (xt - x0)
    P[i].radian = math.atan(P[i].Slope)
    print("x0={}  y0={}  xt={}".format(x0, y0, xt))
    print("yt={}  Rad={}  radian={}".format(yt, Rad, P[i].radian))
    P[i].X = (xt + x0) / 2.0
    P[i].Y = (yt + y0) / 2.0
    P[i].Ylab = P[i].Y - P[i].X * math.tan(2.0 * P[i].radian + PI / 2.0)
    x0, y0 = xt, yt

calculate = []  # 统计每个区间段反射点Ylab的数据个数
for i in range(160):
    calculate.append(0)
for i in range(300):
    print("X[%d]=%f      Y[%d]=%f       " % (i, P[i].X, i, P[i].Y), end=' ')
    print("Ylab[%d]=%f      Y[%d]转换=%f" % (i, P[i].Ylab, i, P[i].Ylab - 300))
    t = int(P[i].Ylab)
    calculate[t] += 1

for i in range(160):
    print("{0:>4d}".format(calculate[i]), end='')
    if i % 10 == 9:
        print()

# 第一问解答
sum1 = sum(calculate[100:120])
print("射在[-200,-180]区间的数量为{0:d}个".format(sum1))

sum2 = 0
for i in range(300):
    if 100 <= P[i].Ylab <= 120:
        sum2 += 1

print("射在[-200,-180]区间的数量为{0:d}个".format(sum2))

sum3 = 0
for i in range(300):
    if 130 <= P[i].Ylab <= 150:
        sum3 += 1
print("射在[-200,-180]区间的数量为{0:d}个".format(sum3))
