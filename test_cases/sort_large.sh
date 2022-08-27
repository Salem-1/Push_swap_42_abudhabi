#!/bin/bash

echo "please enter number of integers you want to generate"
read n
echo "Do you want to use the checker(y / n)?"
read check
if [$check  == n ]
then
	echo "#!/bin/bash" > generated_nums.sh
	python3 generator.py $n >> generated_nums.sh
	chmod +x generated_nums.sh
	./generated_nums.sh
else
	echo "#!/bin/bash" > generated_nums.sh
	python3 checker_gen.py $n >> generated_nums.sh
	chmod +x generated_nums.sh
	./generated_nums.sh
fi