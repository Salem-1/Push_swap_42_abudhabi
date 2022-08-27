#!/bin/bash


echo "please enter number of integers you want to generate"
read n

echo "#!/bin/bash" > generated_nums.sh
make -C ../
python3 generator.py $n >> generated_nums.sh
chmod +x generated_nums.sh
./generated_nums.sh
echo "---------------------------------------------------"
echo "Number of moves = $(./generated_nums.sh | wc -l) "

echo -n "Checker result =        "
./checker_generated_nums.sh