ary1 = [1, 2, 3, 4, 5]
ary2 = [1, 2, 3, 5]
result = 0

for num in ary1 + ary2:
	result ^= num
print result