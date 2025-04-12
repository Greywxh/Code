import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['SimSun']  # 改用黑体确保加粗明显
plt.rcParams['font.weight'] = 'extra bold'
plt.rcParams['axes.unicode_minus'] = False

plt.rcParams['mathtext.fontset'] = 'cm'  # 使用Computer Modern字体

# 创建画布
fig, ax = plt.subplots(figsize=(8, 4))
ax.set_xlim(0, 11)
ax.set_ylim(0, 5)
ax.axis('off')

ax.plot([1, 1], [2.9, 3.1], color='black', linewidth=1)
ax.plot([1, 2], [3, 3], color='black', linewidth=1)
ax.plot([2, 2], [2.9, 3.1], color='black', linewidth=1)
ax.plot([2, 4], [3, 3], color='black', linewidth=1)
ax.plot([4, 4], [2.9, 3.1], color='black', linewidth=1)
ax.plot([4, 6], [3, 3], color='black', linewidth=1)
ax.plot([6, 6], [2.9, 3.1], color='black', linewidth=1)
ax.plot([6, 10], [3, 3], color='black', linewidth=1)
ax.plot([10, 10], [2.9, 3.1], color='black', linewidth=1)

ax.text(1.5, 3.2, 'A', ha='center', va='bottom', fontsize=12, color='black')
ax.text(3, 3.2, 'B', ha='center', va='bottom', fontsize=12, color='black')
ax.text(5, 3.2, 'C', ha='center', va='bottom', fontsize=12, color='black')
ax.text(8, 3.2, 'D', ha='center', va='bottom', fontsize=12, color='black')
ax.text(1.5, 3.6, '影像', ha='center', va='bottom', fontsize=12, color='black')
ax.text(3, 3.6, '自然物', ha='center', va='bottom', fontsize=12, color='black')
ax.text(5, 3.6, '数学对象', ha='center', va='bottom', fontsize=12, color='black')
ax.text(8, 3.6, '善', ha='center', va='bottom', fontsize=12, color='black')
ax.text(2.25, 4.2, '可感领域', ha='center', va='bottom', fontsize=12, color='black')
ax.text(6.5, 4.2, '可知领域', ha='center', va='bottom', fontsize=12, color='black')
ax.text(1.5, 2.5, '幻想', ha='center', va='bottom', fontsize=12, color='black')
ax.text(3, 2.5, '信念', ha='center', va='bottom', fontsize=12, color='black')
ax.text(5, 2.5, '数学知识', ha='center', va='bottom', fontsize=12, color='black')
ax.text(8, 2.5, '理性知识', ha='center', va='bottom', fontsize=12, color='black')
ax.text(2.25, 1.9, '意见', ha='center', va='bottom', fontsize=12, color='black')
ax.text(6.5, 1.9, '知识', ha='center', va='bottom', fontsize=12, color='black')


# 新增数学公式（自动适应位置）
ax.text(1.3, 1.1, '其中，', ha='center', va='bottom', fontsize=12, color='black')
formula_text = r'$\frac{AB}{CD} : \frac{A}{B} : \frac{C}{D} = \frac{1}{2}$'
ax.text(2.6, 1.2, formula_text, ha='center', va='center', fontsize=14, color='black')

ax.plot([1.45, 1.5], [4, 4.1], color='black', linewidth=1)
ax.plot([1.5, 2.2], [4.1, 4.1], color='black', linewidth=1)
ax.plot([2.2, 2.25], [4.1, 4.2], color='black', linewidth=1)
ax.plot([2.25, 2.3], [4.2, 4.1], color='black', linewidth=1)
ax.plot([2.3, 3], [4.1, 4.1], color='black', linewidth=1)
ax.plot([3, 3.05], [4.1, 4], color='black', linewidth=1)

ax.plot([1.45, 1.5], [2.4, 2.3], color='black', linewidth=1)
ax.plot([1.5, 2.2], [2.3, 2.3], color='black', linewidth=1)
ax.plot([2.2, 2.25], [2.3, 2.2], color='black', linewidth=1)
ax.plot([2.25, 2.3], [2.2, 2.3], color='black', linewidth=1)
ax.plot([2.3, 3], [2.3, 2.3], color='black', linewidth=1)
ax.plot([3, 3.05], [2.3, 2.4], color='black', linewidth=1)

ax.plot([5, 5.05], [4, 4.1], color='black', linewidth=1)
ax.plot([5.05, 6.45], [4.1, 4.1], color='black', linewidth=1)
ax.plot([6.45, 6.5], [4.1, 4.2], color='black', linewidth=1)
ax.plot([6.5, 6.55], [4.2, 4.1], color='black', linewidth=1)
ax.plot([6.55, 7.95], [4.1, 4.1], color='black', linewidth=1)
ax.plot([7.95, 8], [4.1, 4], color='black', linewidth=1)

ax.plot([5, 5.05], [2.4, 2.3], color='black', linewidth=1)
ax.plot([5.05, 6.45], [2.3, 2.3], color='black', linewidth=1)
ax.plot([6.45, 6.5], [2.3, 2.2], color='black', linewidth=1)
ax.plot([6.5, 6.55], [2.2, 2.3], color='black', linewidth=1)
ax.plot([6.55, 7.95], [2.3, 2.3], color='black', linewidth=1)
ax.plot([7.95, 8], [2.3, 2.4], color='black', linewidth=1)

plt.savefig('line_text_basic.png', dpi=300)
plt.show()
