import sys
import re

WORD_RE = re.compile(r'\w+')

#print(WORD_RE)

index = {}

with open(sys.argv[1], encoding = 'utf-8') as fp:
	for line_no, line in enumerate(fp, 1):
		for match in WORD_RE.finditer(line):
			word = match.group()
			column_no = match.start()+1
			location = (line_no, column_no)

			occur = index.get(word, [])
			occur.append(location)
			index[word] = occur

index_code = {i:code for code, i in index }
print(index_code)

for word in sorted(index, key=str.upper):
	print(word, index[word])
