# CPP07

# Les Templates

Permet d’envoyer un type qui n’est pas predeterminé à l’avance :

```cpp
template<typename T>
```

## Exemple simple :

```cpp
template<typename T>

T const & max(const T & lhs, const T & rhs)
{
	return ( lhs>=rhs ? lhs : rhs);
}

int main(void)
{
	int a = 42;
	int b = 410;

	std::cout << max<int>(a, b) <<std::endl;

	return 0;
}
```

`max<int>` permet de “caster” le typename, dans les cas les plus simples, ce cast peut être implicit. Dans le cas ou on instantie une classe template de façon implicit, le compilateur se charge de determiner le type de la variable qu’on lui envoie.

## Exemple d’un template à 2 typename

```cpp
template<typename U, typename V>
void donne(U a, V b)
{
	std::cout << a << " " << b << std::endl;
}

template<typename U, typename V>
V donnePlus(U a, V b)
{
	std::cout << a << b << std::endl;
	return b;
}

int main(void)
{

	float result = donnePlus<std::string, float>("Je te donne plus ", 3.14159);
	std::cout << "Result = " << result << std::endl;

	return 0;
}
```

Ici il y a 2 typename U et V qui sont explicitement donnés lors de l’appel à la fonction `donnePlus<std::string, float>`

Il est nécessaire de déclarer chaque template avant chaque fonction.

## Exemple d’utilisation des template pour les listes chainées

Problème : pour chaque type de variable, il faut créer une liste chainée différente. Les template permettent de résoudre ce problème.

```cpp
class ListInt
{
	public :
		ListInt(){};
		ListInt(int content) : _content(content), _next(nullptr)
		{
			std::cout << "Creation List : " << content << std::endl;
		}
		void set_next(ListInt * next)
		{
			this->_next = next;
		}
		int get_content()
		{
			return this->_content;
		}
		ListInt *get_next ()
		{
			return this->_next;
		}

	private:
		int			_content;
		ListInt*	_next;

};

template <typename W>
class List 
{
	public :
		List<W>(W content) : _content(content), _next(nullptr)
		{
			std::cout << "Creation List : " << content << std::endl;
		}
		void set_next(List *next)
		{
			this->_next = next;
		}

		List* get_next()
		{
			return this->_next;
		}

		W get_content()
		{
			return this->_content;
		}

	private:
		W		_content;
		List<W>	*_next;
};

int main(void)
{
	ListInt *nodeInt0 = new ListInt(42);
	ListInt *nodeInt1 = new ListInt(420);
	nodeInt0->set_next(nodeInt1);
	std::cout<< "Ça doit afficher 420 : " << nodeInt0->get_next()->get_content() << std::endl;

	List<float> *node0 = new List<float>(3.14159);
	List<float> *node1 = new List<float>(42);
	node0->set_next(node1);
	std::cout<< "Ça doit afficher 42 : " << node0->get_next()->get_content() << std::endl;

	return 0;
}
```

La première liste chainée ne peut prendre que des int alors que dans la suivante, on peut utiliser le type que l’on veut. Cependant il faut absolument que ce soit le même type dans chaque noeud. 

# Default type

Il est possible de mettre un type par défaut dans le typename.

```cpp
template <typename X = double>
class LoTest
{
	public :
		LoTest(const X & ve) : _ve(ve) {};
		X getVe() const {return this->_ve;};

	private :
		LoTest(){};
		X const _ve;

};

int main(void)
{
	LoTest<> LoTest0(42.25);
	std::cout << "Affiche 42.25 : " << LoTest0.getVe() << std::endl;

	LoTest<int> LoTest1(42.25);
	std::cout << "Affiche 42 : " << LoTest1.getVe() << std::endl;

	return 0;
}
```

# Specialization

Il est possible de spécialiser le comportement d’une classe template en fonction du type de variable envoyé. On distingue la spécialisation partielle et la spécialisation totale.

```cpp
template <typename Y, typename Z>
class Specialized
{
	public :
		Specialized(const Y & y, const Z & z) : _y(y), _z(z)
		{
			std::cout << "Instance non spécialisée." << std::endl;
		};

	private :
		Specialized();
		Y const & _y;
		Z const & _z;
};

template <typename Z>
class Specialized <int ,Z>
{
	public :
		Specialized(const int & y, const Z & z) : _y(y), _z(z)
		{
			std::cout << "Instance partiellement spécialisée." << std::endl;
		};

	private :
		Specialized();
		int const & _y;
		Z const & _z;
};

template <>
class Specialized<int, bool>
{
	public :
		Specialized(const int & y, const bool & z) : _y(y), _z(z)
		{
			std::cout << "Instance totalement spécialisée." << std::endl;
		};

	private :
		Specialized();
		const int & _y;
		const bool & _z;
};

int main(void)
{
		Specialized<float, std::string> UnSpe0(42.25, "a random string");
		Specialized<int, std::string> ParSpe0(42, "an other random string");
		Specialized<int, bool> Spe0(42, true);
	
		return 0;
}
```

Pour l’appel d’un template spécifique, il faut spécifier entre <> les types de variable envoyés afin que le compilateur sache à quelle template il doit de référer.

# Semi solution de ex01

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void iter(T *arr_addr, int arr_size, T (&f)(const T&))
{
    for (int i = 0; i < arr_size; i++)
    {

        arr_addr[i] = f(arr_addr[i]);

    }
}

template <typename T>
T addOne(T const &v)  
{
    return (v + 1);
}

template <typename T>
T byTwo(T const &v)  
{
    return (v * 2);
}

int main(void)
{
    srand(time(NULL));

	std::cout << "Tableau initial :" << std::endl;

    int *mirror = new int[10];
    for (int i = 0; i < 10; i++)
    {
        mirror[i] = rand() % 100;
        std::cout << mirror[i] << std::endl;
    }

	std::cout << std::endl;
	std::cout << "Tableau after addOne :" << std::endl;
	iter<int>(mirror, 10, addOne);
    for (int i = 0; i < 10; i++)
    {
        std::cout << mirror[i] << std::endl;
    }

	std::cout << std::endl;
	std::cout << "Tableau after byTwo :" << std::endl;
	iter<int>(mirror, 10, byTwo);
    for (int i = 0; i < 10; i++)
    {
        std::cout << mirror[i] << std::endl;
    }

    delete[] mirror;  

    return 0;
}
```

Avec cette solution il n’y a que le tableau de valeur qui est modifié. Le reste est en const.
