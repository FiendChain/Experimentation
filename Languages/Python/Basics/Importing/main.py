# Import our sequence module
import mathematics as cmath

# Getting help function
cmath.help()

# Using our sequences module
print(cmath.sequence.fibonacci(10))
print(cmath.sequence.tribonacci(10))
print(cmath.sequence.powers(total = 10, power = 3))

# Creating a complex number
complexNum = cmath.complex.ComplexClass(real = 5, imaginary = 20)
complexNum.angle()
complexAngle = complexNum.degree
print('%(complex)s has an angle of %(angle).2lf degrees' 
    %{'complex': complexNum.itself(), 'angle': complexAngle})
