# 本文件对于用空格隔开的数据字符串进行处理
# 将其读入列表里面并且作为数字进行存储
# 本处针对字符串类型用例：1 29 34 12 43

# a_list = list[map(int, input().split())]

a_list = [int(i) for i in input().split()]
print(a_list)
print(type(a_list), type(a_list[0]))


def square(x):  # 计算平方数
    return x ** 2


print(map(square, [1, 2, 3, 4, 5]))  # 计算列表各个元素的平方
print(list(map(square, [1, 2, 3, 4, 5])))
for i in map(square, [1, 2, 3, 4, 5]):
    print(i)
