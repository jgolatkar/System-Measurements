import random
import numpy

size = [256]

for x in size:
	fp = open("size_{}M".format(x), "wb")
	content = numpy.random.bytes(x*1024*1024)
	fp.write(content)
	fp.close()
