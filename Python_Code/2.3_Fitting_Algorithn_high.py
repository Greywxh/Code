import pandas as pd
import math

PI = 3.1415926
All_Point = []

# 每个Point的倾斜角度数
Tilt_Angle = PI / 18

# 模拟曲线与y轴交点
Y = 140

# 附近区间偏移量
flag = 0

# 跳过前xt个点
xt = int(math.tan(Tilt_Angle) * Y + 1)

for i in range(xt):
    Point1 = [0, i, 0, 0, 0]
    All_Point.append(Point1)

# 每条线的倾角弧度
a = 0
# 前一个点的横纵坐标
x0 = xt
y0 = 0

# 与y轴交点坐标
Ylab = 0
t = 0
i = 0

# 正半轴
for j in range(300 - xt):
    Point = []
    for i in range(1, 1000000000, 1):
        t = i / 1000000000
        Ylab = y0 + 0.5 * math.sin(a + t) - math.tan(PI / 2 + 2 * a + 2 * t + Tilt_Angle) * (x0 + 0.5 * math.cos(a + t))
        if Ylab < Y + flag:
            break
    a += t
    Point = [a, x0 + math.cos(a + t), y0 + math.sin(a + t), i, Ylab]
    All_Point.append(Point)
    print("第%d次计算:" % (j + 1 + xt))
    print(a, x0 + 0.5 * math.cos(a + t), y0 + 0.5 * math.sin(a + t), i, Ylab)
    x0 += math.cos(a + t)
    y0 += math.sin(a + t)

# 负半轴开始迭代
x0 = 0
y0 = 0
aver = Tilt_Angle / 2 / xt
a = aver
for i in range(xt):
    x0 -= math.cos(a)
    y0 += math.sin(a)
    a += aver
    Point = [a, x0, y0, 0, 0]
    All_Point.append(Point)
    print(Point)

for j in range(300 - xt):
    Point = []
    for i in range(1, 1000000000, 1):
        t = i / 1000000000
        Ylab = y0 + 0.5 * math.sin(a + t) - math.tan(PI / 2 + Tilt_Angle - 2 * a - 2 * t) * (x0 - 0.5 * math.cos(a + t))
        if Ylab < Y + flag:
            break
    a += t
    Point = [a, x0 - math.cos(a + t), y0 + math.sin(a + t), i, Ylab]
    All_Point.append(Point)
    print("第%d次计算:" % (j + 1 + xt))
    print(a, x0 - 0.5 * math.cos(a + t), y0 + 0.5 * math.sin(a + t), i, Ylab)
    x0 -= math.cos(a + t)
    y0 += math.sin(a + t)

df = pd.DataFrame(All_Point, columns=['倾斜角', 'X点坐标', 'Y点坐标', '计算次数', 'Ylab'])
output_path = "E:\output_high_2_3.xlsx"
df.to_excel(output_path, index=False)
