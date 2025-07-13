echo "--------------- COMPILATION -----------------\n"
echo "ex00"
cd ex00/
make fclean
make
make
echo "\n"

echo "ex01"
cd ../ex01/
make fclean
make
make
echo "\n"

echo "ex02"
cd ../ex02/
make fclean
make
make
echo "\n"

cd ..

echo "--------------- CHECK LEAKS -----------------\n"
echo "ex00"
cd ex00/
leaks -atExit -- ./easyfind | grep "total leaked bytes"
echo "\n"

echo "ex01"
cd ../ex01/
leaks -atExit -- ./span > test.txt
cat test.txt | grep "total leaked bytes"
rm test.txt
echo "\n"

echo "ex02"
cd ../ex02/
leaks -atExit -- ./mutant | grep "total leaked bytes"
echo "\n"

cd ..

echo "--------------- PROCESS -----------------\n"
echo "\033[0;32m-----------------ex00-----------------\033[0m"
cd ex00/
./easyfind
echo "\n"


echo "\033[0;32m-----------------ex01------------------\033[0m"
cd ../ex01/
./span
echo "\n"

echo "\033[0;32m-----------------ex02----------------\033[0m"
cd ../ex02/
./mutant
echo "\n"


cd ..

cd ex00/
make fclean
cd ../ex01/
make fclean
cd ../ex02/
make fclean
cd ..