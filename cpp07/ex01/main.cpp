#include "iter.hpp"
#include <cstdlib>
#include <ctime>

template <typename T>
void addOne(T &v)  
{
    v++;
}

template <typename T>
void byTwo(T &v)  
{
    v *= 2;
}

int main() 
{

  std::cout << "----------------------------" << std::endl;

  srand(time(NULL));
  int *mirror = new int[10];

  for (int i = 0; i < 10; i++)
  {
      mirror[i] = rand() % 10;
      std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
  }

  std::cout << "----------------------------" << std::endl;

  iter<int>(mirror, 10, addOne);
  iter<int>(mirror, 10, byTwo);

  for (int i = 0; i < 10; i++)
  {
      std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
  }
  std::cout << "----------------------------" << std::endl;

  char char_tab[3];

  char_tab[0] = 'a';
  char_tab[1] = 'b';
  char_tab[2] = 'C';

  for (int i = 0; i < 3; i++)
  {
      std::cout << "char_tab[" << i << "] = " << char_tab[i] << std::endl;
  }

  std::cout << "----------------------------" << std::endl;

  iter<char>(char_tab, 3, addOne);

  for (int i = 0; i < 3; i++)
  {
      std::cout << "char_tab[" << i << "] = " << char_tab[i] << std::endl;
  }

  delete[] mirror;  
  
  return 0;
}
