#list(filter(lambda x:print(x, end=' ') if x[0] != ' ' else None, input().split()))
import re
print(re.sub('  *', ' ', input()))