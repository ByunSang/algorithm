from collections import namedtuple

City = namedtuple('City', 'name country population coordinates')

tokyo = City('Tokyo', 'JP', 36.933, (35.123, 129.6969))

print(tokyo)

print(tokyo.population)

print(tokyo[1])




print(City._fields)

Latlong = namedtuple('Latlong', 'lat long')
delhi_data = ('Delhi NCR', 'IN', 21.935, Latlong(28.61, 77.123))

delhi=City._make(delhi_data) #same delhi=City(*delhi_data)
print(delhi._fields)
print(delhi._asdict)

for key, value in delhi._asdict().items():
	print(key + ':' , value)
