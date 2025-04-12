import matplotlib.pyplot as plt
import numpy as np

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号

# 创建图形
plt.figure(figsize=(6, 6))

# 数据准备
attributes = [
    "机构有良好的声誉",
    "机构保障我的基本权益",
    "机构网络平台安全稳定",
    "机构网络页面设置整洁、功能明确",
    "机构有线下的咨询点",
    "机构课程时间安排合理",
    "机构提供的讲义新颖全面"
]

expectation = [4.006, 4.006, 4.031, 4.0075 ,4.0327, 4.03066, 4.03265]
perception = [4.063, 4.051, 4.067, 4.021, 4.006, 3.986, 3.986]

mean_exp = np.mean(expectation)
mean_per = np.mean(perception)
plt.scatter(expectation, perception, color="#1A77BB", s=30)

population = [(50, -5),(60, -5),(0, -20),(50, -20),(-20, 10),(-40, 10),(10, -20)]

for i, txt in enumerate(attributes):
    plt.annotate(txt, (expectation[i], perception[i]),
                 xytext=population[i],  # 正上方偏移量 (x=0, y=10)
                 textcoords='offset points',
                 ha='center',  # 水平居中
                 va='bottom')   # 垂直底部对齐(文本在点的上方)

plt.axvline(mean_exp, color='red', linestyle='--', alpha=0.5)
plt.axhline(mean_per, color='red', linestyle='--', alpha=0.5)

plt.xlim(4.005, 4.035)
plt.xticks(np.arange(4.005, 4.035, 0.005))
plt.ylim(3.98, 4.07)
plt.yticks(np.arange(3.98, 4.071, 0.01))
plt.xlabel('平均期望')
plt.ylabel('平均感知')
plt.title('IPA 分析矩阵')

plt.tight_layout()
plt.show()