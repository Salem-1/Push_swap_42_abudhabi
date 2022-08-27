import random
import sys
 
# total arguments
n = len(sys.argv)


num = int(sys.argv[1])

gen = set()

while (len(gen) < int(num)):

	gen.add(random.randint(-21345687, 21345687))
	if len(gen) >= int(num):
		break
	gen.add(random.randint(-10, 5000))
	if len(gen) >= int(num):
		break
	gen.add(random.randint(0, 500))

print("../push_swap ", end=" ")
for i in gen:
	print(i, end=" ")
print(" | ../checker \" ")
for i in gen:
	print(i, end=" ")
print("\"")
