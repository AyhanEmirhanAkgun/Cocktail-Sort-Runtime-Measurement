# Python program for implementation of Cocktail Sort
from datetime import datetime
import numpy as np


def cocktailSort(a):
	n = len(a)
	swapped = True
	start = 0
	end = n-1
	while (swapped == True):

		# reset the swapped flag on entering the loop,
		# because it might be true from a previous
		# iteration.
		swapped = False

		# loop from left to right same as the bubble
		# sort
		for i in range(start, end):
			if (a[i] > a[i + 1]):
				a[i], a[i + 1] = a[i + 1], a[i]
				swapped = True

		# if nothing moved, then array is sorted.
		if (swapped == False):
			break

		# otherwise, reset the swapped flag so that it
		# can be used in the next stage
		swapped = False

		# move the end point back by one, because
		# item at the end is in its rightful spot
		end = end-1

		# from right to left, doing the same
		# comparison as in the previous stage
		for i in range(end-1, start-1, -1):
			if (a[i] > a[i + 1]):
				a[i], a[i + 1] = a[i + 1], a[i]
				swapped = True

		# increase the starting point, because
		# the last stage would have moved the next
		# smallest number to its rightful spot.
		start = start + 1


# Random integer numpy array
a = np.random.randint(1000, size = 100)
b = np.random.randint(1000, size = 1000)
c = np.random.randint(1000, size = 10000)

# Sort array a
start_time = datetime.now()

cocktailSort(a)

end_time = datetime.now()

print("Sorted array is:")
for i in range(len(a)):
	print("% d" % a[i])

a1 = (end_time - start_time)

# Sort array b
start_time = datetime.now()

cocktailSort(b)

end_time = datetime.now()

print("Sorted array is:")
for i in range(len(b)):
	print("% d" % b[i])

b1 = (end_time - start_time)

#Sort array c
start_time = datetime.now()

cocktailSort(c)

end_time = datetime.now()

print("Sorted array is:")
for i in range(len(c)):
	print("% d" % c[i])

c1 = (end_time - start_time)

print("Run time  : a = ", a1, " b = ", b1, " c = ", c1)

