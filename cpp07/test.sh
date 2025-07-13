echo "------------------EX00------------------\n"
cd ex00/
make
make re
echo "\n"
./whatever
echo "\n"
g++ -Wall -Wextra -Werror -std=c++98 main_subject.cpp
./a.out
echo "\n"

echo "------------------EX01------------------\n"
echo "\n"
cd ../ex01/
make
make re
echo "\n"
./iter
echo "\n"
g++ -Wall -Wextra -Werror -std=c++98 main_subject.cpp
./a.out
echo "\n"


echo "------------------EX02------------------\n"
cd ../ex02/
make
make re
echo "\n"
./array
echo "\n"
g++ -Wall -Wextra -Werror -std=c++98 main_subject.cpp
./a.out
echo "\n"

cd ..

echo "\n"
echo "------------------ CHECK LEAKS ------------------\n"
echo "\n"

echo "------------------EX00------------------\n"
cd ex00/
make
make re
echo "\n"
leaks -atExit -- ./whatever
echo "\n"
g++ -Wall -Wextra -Werror -std=c++98 main_subject.cpp
leaks -atExit -- ./a.out
echo "\n"


echo "------------------EX01------------------\n"
cd ../ex01/
make
make re
echo "\n"
leaks -atExit -- ./iter
echo "\n"
g++ -Wall -Wextra -Werror -std=c++98 main_subject.cpp
leaks -atExit -- ./a.out
echo "\n"


echo "------------------EX02------------------\n"
cd ../ex02/
make
make re
echo "\n"
leaks -atExit -- ./array
echo "\n"
g++ -Wall -Wextra -Werror -std=c++98 main_subject.cpp
leaks -atExit -- ./a.out


cd ..
cd ex00/
make fclean
rm ./a.out

cd ..
cd ex01/
make fclean
rm ./a.out

cd ..
cd ex02/
make fclean
rm ./a.out
