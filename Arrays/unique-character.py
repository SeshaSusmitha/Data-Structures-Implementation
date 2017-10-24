def unique_char():
	s = "abcd"

	chars = set()

	for letter in s:
		if letter in chars:
			print "false"
			return
		else:
			chars.add(letter)
	print "true"

unique_char()