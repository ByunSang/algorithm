my_dict = {}

import collections

#isinstance(my_dict, collections.abc.Mappling)

tt = (1,2,(30,40))
#print(hash(tt))
t1 = (1,2,(30,40))
#print(hash(t1))
t2 = (1,2, frozenset([30,40]))
#print(hash(t2))

a = dict(one=1, two=2, three=3)
b = {'one':1, 'two':2, 'three':3}
c = dict({'one':1, 'two':2, 'three':3})
d = dict([('two',2), ('one',1), ('three', 3)])

if a==b==c==d:
	print("TRUE")


DIAL_CODES = [(86, 'China'), (87, 'India'), (88, 'Korea'), (6, 'Russia'), (55, 'Brazil'), ]

country_code = {country: code for code, country in DIAL_CODES}
print(country_code)
country_reverse = {code: country.upper() for country, code in country_code.items() if code > 50}
print(country_reverse)
