import pandas as pd
import math

PI = 3.1415926

a = math.asin(1 / 300)
x0 = math.cos(a)
y0 = math.sin(a)

All_Point = [[0, 0, 0, 0, 0, 0], [a, x0, y0, 0, 0, 0]]

t = 0
y_high = 0
y_low = 0
i = 0
for j in range(300):
    Point = []
    for i in range(1, 1000000000, 1):
        t = i / 1000000000
        y_high = y0 + math.sin(a + t) - math.tan(PI / 2 + 2 * a + 2 * t) * (x0 + math.cos(a + t))
        if y_low < 150:
            t = i / 1000000000
            y_low = y0 - math.tan(PI / 2 + 2 * a + 2 * t) * x0
            break
    x0 += math.cos(a + t)
    y0 += math.sin(a + t)
    a += t
    Point = [a, x0, y0, i, y_low, y_high]
    print("第%d次计算:" % (j+1))
    print(a, x0, y0, i, y_low, y_high)
    All_Point.append(Point)

df = pd.DataFrame(All_Point, columns=['倾斜角', 'X点坐标', 'Y点坐标', '计算次数', 'Y_low', 'Y_high'])
output_path = 'E:\output_high_3_3.xlsx'
df.to_excel(output_path, index=False)
