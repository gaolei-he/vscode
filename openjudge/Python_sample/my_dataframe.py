from unicodedata import numeric
import pandas as pd
pd.set_option('display.unicode.east_asian_width', True)

scores = [['男', 108, 115, 97], ['女', 115, 87, 105], 
['女', 100, 60, 130], ['男', 112, 80, 50]]
names = ['张三', '李四', '王五', '赵六']
courses = ['性别', '语文', '数学', '英语']
df = pd.DataFrame(data=scores, index=names, columns=courses)
print(df)

print(df.values[0][1], type(df.values))
print(list(df.index))
print(list(df.columns))
print(df.index[2], df.columns[2])
s1 = df['语文']
print(s1['张三'], s1[0])
print(df['语文']['李四'])
s2 = df.loc['王五']
print(s2['性别'], s2['语文'], s2[2])


print(df.T)
print(df.sort_values('语文', ascending=False))

df2 = df.iloc[[1, 3], 2:4]
df2 = df.loc[:'王五', ['语文', '英语']]
print(df2)
print(df['语文'].idxmax()) # 语文最高分所在行的标签
print(df['数学'].argmin()) #数学最低分所在行的行号
print(df.loc[(df['语文'] > 100) & (df['数学'] >= 85)]) #语文大于100，数学大于85的行
print('----下面是DataFrame的增删和修改')
df['物理'] = [80, 70, 90, 100]
df.loc[:, '英语'] += 10
print(df)

df.drop(['物理'], axis=1, inplace=True)#列 axis = 1
df.drop('王五', axis=0, inplace=True)#行 axis = 0