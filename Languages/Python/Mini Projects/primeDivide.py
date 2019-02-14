# Divide a given number by a prime
def isPrime(number):
	for x in range(2, number):
		if(number%x == 0):
			return False
	else:
		return True

# Get number
while True:
	try:
		value = int(input('Enter number: '))
	except:
		print('Not a valid number')
		continue
	break

# Prime factoring
factors = []
divisor = 2
while value != 1:
	while value % divisor == 0:
		factors.append(divisor)
		value /= divisor

	divisor += 1
	while isPrime(divisor) == False:
		divisor += 1

print(*factors, sep = '*')


