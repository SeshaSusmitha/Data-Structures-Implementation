arr = [1, 3, 2, 2]
k = 4

if len(arr) < 2:
	cout << "only 2 elements"
	# return 

seen = set()
output = set()

for num in arr:

	target = k - num
	if target not in seen:
		seen.add(num)

	else:
		output.add(((min(num, target)),(max(num,target))))

print '\n'.join(map(str, list(output)))
print len(output)