s1 = "public relations"
s2 = "crap built on lies"


# Removing spaces
s1 = s1.replace(' ', '')
s2 = s2.replace(' ', '')

flag = 0


#  Create a new dictionary 
count = {}

for letter in s1:
	if letter in count:
		count[letter] += 1
	else:
		count[letter] = 1

for letter in s2:
	if letter in count:
		count[letter] -= 1
	else:
		count[letter] = 1

for k in count:
	if count[k] != 0:
		flag = 1


if flag == 0:
	print "anagrams"
else:
	print "not anagrams"


