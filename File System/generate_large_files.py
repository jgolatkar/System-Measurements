import random
import numpy


"""
since we have total memory 2GB, available memory is around 1GB
when no memory intensive application is running. 

"""
size = [1]
for x in size:
	fp = open("size_{}GB".format(x), "wb")
	content = numpy.random.bytes(x*1024*1024*1024)
	fp.write(content)
	fp.close()
