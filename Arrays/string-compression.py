#  Run length compression algorithm

s = "AAAAABBBBCCCC"
# s = "ab"
# s = "aab"

r = ""
print s
str_len = len(s)
print str_len

# for length 0
if str_len == 0:
	print ""
if str_len == 1:
	print s+"1"

last = s[0]
count = 1
i = 1

while i < str_len:
	if s[i] == s[i-1]:
		count += 1
		
	else:
		r = r + s[i-1] + str(count)
		count = 1

	i += 1

r = r + s[i-1] + str(count)
print r