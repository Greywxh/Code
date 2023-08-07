import pandas as pd
import math

PI = 3.1415926

# 每个Point的倾斜角度数
a = math.asin(1 / 280)

# 前一个点的横纵坐标
x0 = math.cos(a)
y0 = math.sin(a)

All_Point = [[0, 0, 0, 0, 0], [a, x0, y0, 0, 140.000525]]

# 与y轴交点坐标
Ylab = 0
t = 0
i = 0

# flag作为范围控制的变量
flag = 0

for j in range(300):
    Point = []
    for i in range(1, 1000000000):
        t = i / 1000000000
        Ylab = y0 + 0.5 * math.sin(a + t) - math.tan(PI / 2 + 2 * a + 2 * t) * (x0 + 0.5 * math.cos(a + t))
        if Ylab < 140 + flag:  # 此处可作为附加“附近”参数口
            break
    a += t
    Point = [a, x0 + 0.5 * math.cos(a + t), y0 + 0.5 * math.sin(a + t), i, Ylab]
    print("第%d次计算:" % (j + 1))
    print(a, x0 + 0.5 * math.cos(a + t), y0 + 0.5 * math.sin(a + t), i, Ylab)
    All_Point.append(Point)
    x0 += math.cos(a + t)
    y0 += math.sin(a + t)

df = pd.DataFrame(All_Point, columns=['倾斜角', 'X中点坐标', 'Y中点坐标', '计算次数', 'Ylab'])
output_path = 'E:\output_high_1_3.xlsx'
df.to_excel(output_path, index=False)
