# CPP08

# Utilisation des différents conteneurs

## Choix du conteneur

![164319655236_P2C2-4.png](CPP08%20cd20f9c55f174fce980760c9e2ff89a3/164319655236_P2C2-4.png)

Tous les conteneur possèdent les méthodes suivantes :

| Méthode | Description |
| --- | --- |
| `push_back()` | Ajout d'un élément à la fin du tableau. |
| `pop_back()` | Suppression de la dernière case du tableau. |
| `front()` | Accès à la première case du tableau. |
| `back()` | Accès à la dernière case du tableau. |
| `assign()` | Modification du contenu d'un tableau. |
| `size()` | Retourne la taille du conteneur |
| `empty()` | Renvoie true si le conteneur est vide |
| `swap()` | Echange le contenu de 2 conteneurs |

## Vector

```cpp
#include <iostream>
#include <vector>

int main()
{

	std::vector<int> vectorInt0(4,4);
	std::vector<int> vectorEmpty;

	std::cout << "vectorInt0.empty() = " << vectorInt0.empty() << std::endl;	
	vectorInt0.swap(vectorEmpty);
	std::cout << "vectorInt0.empty() = " << vectorInt0.empty() << std::endl;
	vectorInt0.swap(vectorEmpty);
	std::cout << "vectorInt0.empty() = " << vectorInt0.empty() << std::endl;
	vectorInt0.clear();
	std::cout << "vectorInt0.empty() = " << vectorInt0.empty() << std::endl;
	
	vectorInt0.push_back(42);
	vectorInt0.push_back(3);
	vectorInt0.push_back(14);
	vectorInt0.push_back(15);
	vectorInt0.push_back(9);
	vectorInt0.push_back(21);
	for (int i = 0 ; i < 6; i++)
	{
		std::cout << vectorInt0[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "vectorInt0.size() = " << vectorInt0.size() << std::endl;
	std::cout << "vectorInt0.back() = " << vectorInt0.back() << std::endl;
	vectorInt0.pop_back();
	std::cout << "vectorInt0.size() = " << vectorInt0.size() << std::endl;
	std::cout << "vectorInt0.back() = " << vectorInt0.back() << std::endl;

	std::cout << "vectorInt0.front() = " << vectorInt0.front() << std::endl;
	vectorInt0.assign(5, 1000);
	std::cout << "vectorInt0.front() = " << vectorInt0.front() << std::endl;
	std::cout << "vectorInt0.back() = " << vectorInt0.back() << std::endl;

	int tab[5] = {10,12,11,14,100};
	vectorInt0.assign(tab, tab+5);
	for (int i = 0 ; i < 5; i++)
	{
		std::cout << vectorInt0[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
```

Il est possible de faire une deep copy d’un vecteur avec l’opérateur =

```cpp
std::vector<int> test;

test.push_back(10); 
test.push_back(20); 
test.push_back(30); 

for (std::vector<int>::iterator it = test.begin(); it!=test.end(); ++it) 
       std::cout << *it << " "; 

std::cout << std::endl;
std::vector<int>test2;

test2 = test;
test[0] = 42;
for (std::vector<int>::iterator it = test2.begin(); it!=test2.end(); ++it) 
       std::cout << *it << " "; 
std::cout << std::endl;

for (std::vector<int>::iterator it = test.begin(); it!=test.end(); ++it) 
       std::cout << *it << " ";
```

## Deque

Ils sont similaires aux vector mais on peut ajouter des éléments aux 2 extrémités de la liste.

Attention cela décale les indices chaque fois que l’on ajoute un élément au début.

```cpp
#include <iostream>
#include <deque> 

int main()
{ 
    std::deque<int> d(4,5); 
    
    d.push_front(2);
    d.push_back(8); 

    for(int i(0); i<d.size(); ++i)
        std::cout << d[i] << " ";

    return 0;
}
```

## Stack

LIFO : Last In First Out, le dernier élément ajouté est le premier supprimé. Il y a trois méthodes pour manipuler ces piles :

1. `push()` : ajouter un élément au début.
2. `top()` : consulter le dernier élément ajouté.
3. `pop()` : supprimer le dernier élément ajouté.

```cpp
#include <stack>
#include <iostream>

int main()
{
    std::stack<int> *pile = new std::stack<int>;
    pile->push(3);
    pile->push(4);
    pile->push(5);

	for (int i = 0; i < 28000000; i++)
	{
		pile->push(i);
	}

    std::cout << pile->top() << std::endl;
 
    pile->pop();
    std::cout << pile->top() << std::endl;

    return 0;
}
```

## Queue

FIFO : First In First Out, le premier élément ajouté est le premier élément supprimé. On utilise les 3 méthodes suivantes pour les manipuler :

1. `push()` : ajouter un élément au début.
2. `front()` : consulter le premier élément ajouté.
3. `pop()` : supprimer le dernier élément ajouté. 

```cpp
#include <queue>
#include <iostream>

int main()
{
	std::queue<std::string> waitingList;

	waitingList.push("Alice");
	waitingList.push("Bob");
	waitingList.push("Cartman");
	waitingList.push("Doris");

	std::cout << waitingList.front() << std::endl;
	waitingList.pop();
	std::cout << waitingList.front() << std::endl;
	waitingList.pop();
	std::cout << waitingList.front() << std::endl;
	waitingList.pop();
	std::cout << waitingList.front() << std::endl;
	waitingList.pop();
	std::cout << waitingList.front() << std::endl;

    return 0;
}
```

## Priority_queue

Les valeurs sont classées par leur grandeur. Seuls les objets dont l’opérateur de comparaison est surchargé peuvent être utilisés dans une queue.

```cpp
#include <queue>
#include <iostream>

int main()
{
		std::priority_queue<int> whoIsBig;
	
		whoIsBig.push(54);
		whoIsBig.push(554);
		whoIsBig.push(554);
		whoIsBig.push(546);
		whoIsBig.push(1054);
		whoIsBig.push(-56254);
	
		std::cout << whoIsBig.top() << std::endl;
		whoIsBig.pop();
		std::cout << whoIsBig.top() << std::endl;
		whoIsBig.pop();
		std::cout << whoIsBig.top() << std::endl;
	
	  return 0;
}
```

## Map

Les map sont des conteneurs à clé. Elles permettent d’assigner à chaque élément une clé unique. Le type de la clé et de la valeur sont choisis par l’utilisateur.

```cpp
#include <iostream>
#include <map>
#include <fstream>

int main()
{
	std::ifstream fichier("NotreDameDeParis.txt");
	std::string word;
	std::map<std::string, int> word_count;

	if (!fichier.is_open())
	{
		std::cerr << "Impossible" << std::endl;
		return EXIT_FAILURE;
	}

	while (fichier >> word)
	{
		word_count[word] += 1;
	}

	std::cout << word_count["Claude"] << std::endl;
	std::cout << word_count["Esmeralda"] << std::endl;
	std::cout << word_count["Quasimodo"] << std::endl;
	std::cout << word_count["le"] + word_count["Le"] << std::endl;

	return 0;

}
```

Attention aux maps avec des objets ! Par exemple une map de type map<int, Objet>, l’objet Objet doit avoir un constructeur par défaut pour pouvoir utiliser l’opérateur []. Le code suivant fonctionne :

```cpp
#include <iostream>
#include <map>

class Objet
{
	private :
		int _nb;

	public :
		Objet(int nb);
		Objet() : _nb(0) {};

};

Objet::Objet(int nb) : _nb(nb)
{
	std::cout << "nb : " << nb << std::endl;
}

int main ()
{
	std::map<int, Objet> map_objet;

	Objet objet1(1);

	map_objet[1] = objet1;

	return 0;
}
```

Le code suivant ne fontionne pas :

```cpp
#include <iostream>
#include <map>

class Objet
{
	private :
		int _nb;

	public :
		Objet(int nb);

};

Objet::Objet(int nb) : _nb(nb)
{
	std::cout << "nb : " << nb << std::endl;
}

int main ()
{
	std::map<int, Objet> map_objet;

	Objet objet1(1);

	map_objet[1] = objet1;

	return 0;
}
```

Même si il le constructeur par défaut n’est jamais appelé, il est nécessaire car l’opérateur [] apelle le constructeur par défaut de l’objet si il ne trouve pas l’entrée demandée.

# Les itérateurs et foncteurs

## Les fonction begin() et end()

La fonction begin() permet de créer un itérateur sur un objet. Le fonction end renvoie un itérateur sur l’élément juste après dans la mémoire. 

```cpp
#include <deque>
#include <iostream>

int main()
{
    std::deque<int> d(5,6);
    std::deque<int>::iterator it;

		d.push_back(45454);

		it = d.begin();

		while (it!=d.end())
		{
	    std::cout << *it << std::endl;
			++it;
		}
    return 0;
}
```

Il existe 5 types d’itérateurs. Voici les 2 types utilisés par les containers.

## Les "bidirectional iterators"

Ils sont utilisés par les **list, set et map**. Il permettent l’accès aux différents éléments du container par les opérateurs ++ et —.

### A propos des list

```cpp
#include <list>
#include <iostream>

int main()
{
    std::list<std::string> liste;
    liste.push_back("Bonjour");
    liste.push_back(" les petits ");
    liste.push_back("loups.");
    
    for(std::list<std::string>::iterator it = liste.begin(); it!=liste.end(); ++it)
    {
        std::cout << *it;
    }
    return 0;
}
```

### A propos des map

Les maps sont composés d’un autre container appelé les pairs. Ce container est une classe templaté de 2 attributs publics : first et second.

```cpp
#include <utility>
#include <iostream>

int main()
{
    std::pair<int, double> p(2, 3.14);
    std::cout << "La paire vaut (" << p.first << ", " << p.second << ")" << std::endl;

    return 0;
}
```

Les map possèdent plusieurs caractéristiques :

- Les [] permettent d’accéder à un élément par sa clé. Mais si la clé n’existe pas elle est créé.
- Les map trie leurs entrées en fonction de la clé.
- Pour vérifier si une clé existe on utilise la méthode find()

```cpp
#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, std::string> cri;
    
    cri["souris"] = "...";
    cri["tigre"] = "RRRRRrrrrrr...";
    cri["chat"] = "miaou";
    cri["elephant"] = "PRUUUIIIIIIIEEE";

    for(std::map<std::string, std::string>::iterator it=cri.begin(); it!=cri.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    std::cout << "cri[autruche] = " << cri["autruche"] << std::endl;

    std::map<std::string, std::string>::iterator poisson = cri.find("poisson");

    std::cout << (poisson == cri.end()) << std::endl;

    return 0;
}
```

## Les “random acess iterator”

Ils sont utilisés par les **vector et les deque**. Il permettent d’accéder directement à n’importe quel élément du container.

```cpp
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::vector<std::string> tab;

    tab.push_back("les");
    tab.push_back("Developpeurs");

    tab.insert(tab.begin() + 1, "bons");
    tab.insert(tab.begin(), "Salut");

    for(std::vector<std::string>::iterator it=tab.begin(); it!=tab.end(); ++it)
    {
        std::cout << *it << " ";
    }

    tab.erase(tab.begin());

	  std::cout << "-----" << std::endl;

    for(std::vector<std::string>::iterator it=tab.begin(); it!=tab.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}
```

## Les foncteurs

Les foncteurs sont des objets possédant une surcharge de l'opérateur `()`  .

### Foncteur simple

```cpp
#include <iostream>
#include <string>
#include <map>

class Foncteur
{
    public:
        void operator()(std::string str1, std::string str2)
        {
            std::cout << str1 << " " << str2 << std::endl;
        }
};

int main()
{
    Foncteur testFoncteur;

    testFoncteur("Hello", "World !");

    return 0;
}
```

### Foncteurs évolutifs

Ce sont des foncteurs qui utilisent leurs attributs pour pour modifier le comportement de la fonction operator()

```cpp
#include <iostream>

class Foncteur
{
    private :
        int _n;

    public:
        Foncteur(int n) : _n(n){};

        int operator()(int value)
        {
            this->_n += 2;
            return value + this->_n;
        }
};

int main()
{
    Foncteur testFoncteur(0);

    std::cout << testFoncteur(21) << std::endl;
    std::cout << testFoncteur(21) << std::endl;
    std::cout << testFoncteur(21) << std::endl;
    std::cout << testFoncteur(21) << std::endl;

    return 0;
}
```

Exemple avec une surcharge d’operator= ()() :

```cpp
#include <iostream>

class Foncteur
{
    private :
        int _n;

    public:
        Foncteur(int n) : _n(n){};

        int operator()(int value)
        {
            this->_n += 2;
            return value + this->_n;
        }
};

int main()
{
    Foncteur testFoncteur(0);

    std::cout << testFoncteur(21) << std::endl;
    std::cout << testFoncteur(21) << std::endl;
    std::cout << testFoncteur(21) << std::endl;
    std::cout << testFoncteur(21) << std::endl;

    return 0;
}
```

class Remplir
{
	public:
	    Remplir(int i) : m_valeur(i){}
	
	    int operator()()
	    {
	        ++m_valeur;
	        return m_valeur;
	    }
	
	private:
	    int m_valeur;
};

int main()
{ 
    vector<int> tab(100,0); //Un tableau de 100 cases valant toutes 0

    Remplir f(0);       

    for(vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it)
    {
        *it = f(); //On appelle simplement le foncteur sur chacun des éléments du tableau
    }
    
    return 0;
}
```

### Les prédicats

Ce sont des surcharges de l’opérateur = qui possèdent ce prototype : bool operator()(string const& chaine) const. Ils renvoient un boléen.

```cpp
#include <iostream>

class TestVoyelles
{
public:
    bool operator()(std::string const& chaine) const
    {
        for(int i(0); i<chaine.size(); ++i)
        {
            switch (chaine[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                    return true;
                default:
                    break;
            }
        }
        return false;
    }
};

int main()
{
    TestVoyelles testV;

    std::cout << testV("Est ce qu'il y a des voyelles ?") << std::endl;
    std::cout << testV("st c q'l ds vlls ?") << std::endl;

    return 0;
}
```

### Les foncteurs prédéfinis

Ce sont des foncteurs qui sont déjà codé dans la bibliothèque “functional”.

```cpp
#include <iostream>
#include <functional>

int main()
{
    std::plus<int> foncteur;
    int a(2), b(3);
    std::cout << a << " + " << b << " = " << foncteur(a,b) << std::endl;
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}
```

# La bibliotheque <algorithm>

Elle fournit des objets qui permettent de modifier les containers. 

## generate()

Cette fonction ressemble à la fonction iter du module précédent. La fonction passée en paramètre doit renvoyer le même type que celui choisis pour le container en paramètre.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

class Remplir
{
    public:
        Remplir(int i):m_valeur(i){}

        int operator()()       //TYPE DE RETOUR INT
        {
            ++m_valeur;
            return m_valeur;
        }

    private:
        int m_valeur;
};

int main()
{
    std::vector<int> tab(100,0); //TYPE POUR LE CONTAINER INT

    Remplir remplir(8);

    generate(tab.begin(), tab.end(), remplir);

    for (std::vector<int>::iterator it = tab.begin(); it!=tab.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}
```

## count()

Cette fonction permet de compter le nombre d’occurence d’une valeur dans un container.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>                                                     
#include <ctime>

class Remplir
{
    public:
        Remplir(int i):m_valeur(i){}

        int operator()()
        {
            ++m_valeur;
            return rand() % 10;
        }

    private:
        int m_valeur;
};

int main()
{
    srand(time(NULL));
    
    std::vector<int> tab(100,0);

    Remplir remplir(8);

    generate(tab.begin(), tab.end(), remplir);

    for (std::vector<int>::iterator it = tab.begin(); it!=tab.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    std::cout << std::endl;

    std::cout << count(tab.begin(), tab.end(), 6) << std::endl;

    return 0;
}
```

## count_if

Identique à l’exemple précédent mais il faut utiliser un prédicat comme troisième argument à la fonction count_if.

```cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class TestVoyelles
{
	public:
	    bool operator()(std::string const& chaine) const
	    {
	        for(int i(0); i<chaine.size(); ++i)
	        {
	            switch (chaine[i])
	            {
	                case 'a':
	                case 'e':
	                case 'i':
	                case 'o':
	                case 'u':
	                case 'y':
	                    return true;
	                default:
	                    break;
	            }
	        }
	        return false;
	    }
};

int main()
{
    std::vector<std::string> tableau;

    tableau.push_back("ppppppp");
    tableau.push_back("ppppppp");
    tableau.push_back("pppoppp");
    tableau.push_back("ppppppp");
    tableau.push_back("ppppppp");
    tableau.push_back("ppppppp");

    int const compteur = count_if(tableau.begin(), tableau.end(), TestVoyelles());

    std::cout << compteur;

    return 0;
}
```

## find(), find_if(), min_element() et max_element()

```cpp
#include <iostream>
#include <deque>
#include <algorithm>
#include <iostream>

class TestVoyelles
{
	public:
	    bool operator()(char const& chaine) const
	    {
            switch (chaine)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                    return true;
                default:
                    break;
            }
	        return false;
	    }
};

int main()
{
    std::deque<char> lettres;

    lettres.push_back('l');
    lettres.push_back('b');
    lettres.push_back('j');
    lettres.push_back('o');
    lettres.push_back('n');
    lettres.push_back('i');
    lettres.push_back('k');

    std::deque<char>::iterator trouve = find(lettres.begin(), lettres.end(), 'a');

    if(trouve == lettres.end())
        std::cout << "La lettre 'a' n'a pas ete trouvee" << std::endl;
    else
        std::cout << "La lettre 'a' a ete trouvee" << std::endl;

    std::deque<char>::iterator mini = min_element(lettres.begin(), lettres.end());
    std::deque<char>::iterator maxi = max_element(lettres.begin(), lettres.end());

    std::cout << "mini = " << *mini << std::endl;
    std::cout << "maxi = " << *maxi << std::endl;

    std::deque<char>::iterator first_voyelle = find_if(lettres.begin(), lettres.end(), TestVoyelles());
    std::cout << "first_voyelle = " << *first_voyelle << std::endl;

    return 0;
}
```

## sort()

Par défaut, la fonction `sort` utilise l'opérateur `<` pour comparer les éléments avant de les trier. Voici un exemple d’utilisation :

```cpp
#include <iostream>
#include <deque>
#include <algorithm>

int main()
{
    std::deque<char> lettres;

    lettres.push_back('d');
    lettres.push_back('d');
    lettres.push_back('n');
    lettres.push_back('o');
    lettres.push_back('a');
    lettres.push_back('i');
    lettres.push_back('k');

    for (std::deque<char>::iterator it = lettres.begin(); it!=lettres.end();++it)
    {
        std::cout << *it << std::endl;
    }

    sort(lettres.begin(), lettres.end());
    std::cout << std::endl;

    for (std::deque<char>::iterator it = lettres.begin(); it!=lettres.end();++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
```

Mais il existe également une autre version de cette fonction qui prend un troisième argument : un foncteur comparant deux éléments. Voici un exemple d’utilisation :

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class CompareLength
{
    public:
        bool operator() (const std::string & str1, const std::string & str2)
        {
            return str1.length() < str2.length();
        }
};

int main()
{
    std::vector<std::string> setences;

    setences.push_back("Voyager, c’est bien utile, ça fait travailler l’imagination.");
    setences.push_back("Tout le reste n’est que déceptions et fatigues.");
    setences.push_back("Notre voyage à nous est entièrement imaginaire.");
    setences.push_back("Voilà sa force.");
    
    for (std::vector<std::string>::iterator it = setences.begin(); it != setences.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    sort(setences.begin(), setences.end(), CompareLength());

    std::cout << std::endl;

    for (std::vector<std::string>::iterator it = setences.begin(); it != setences.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
```

## for_each

Cette fonction prend en parametre 2 itérateurs sur et un foncteur. Elle revoie un objet du même type que le foncteur. Elle permet d’appliquer une fonction à tous les éléments compris entre iterateur 1 et iterateur 2.

```cpp
#include <iostream>
#include <vector>

class AddAll
{
	public:
		AddAll():_result(0){};
		void operator()(int n)
		{
			this->_result += n;
		}

		int get_result()
		{
			return this->_result;
		}

	private :
		int _result;

};

int main()
{

	std::vector<int> vector_test;
	vector_test.push_back(7802);
	vector_test.push_back(1437);
	vector_test.push_back(1);
	vector_test.push_back(0);
	vector_test.push_back(-1);
	vector_test.push_back(15);
	vector_test.push_back(-18);
	vector_test.push_back(42);
	vector_test.push_back(21);
	vector_test.push_back(230);

	AddAll addAll0;

	addAll0 = for_each(vector_test.begin(), vector_test.end(), addAll0);

	std::cout << addAll0.get_result() << std::endl;

	return 0;
}
```

ATTENTION !!! Le troisième paramètre envoyé à for_each est une copie du foncteur. Le foncteur original n’est donc pas modifié ! C’est cette copie qui est renvoyée par la fonction for_each.

## transform

Cette fonction permet de gérer 2 containers en même temps. Elle prend 5 arguments. Le 5ème est un foncteur de la de la biblothèque functional :

1. Le début du premier tableau.
2. La fin du premier tableau.
3. Le début du deuxième tableau.
4. Le début de celui où seront stockés les résultats.
5. Et le foncteur.

```cpp
#include <iostream>
#include <vector>
#include <functional>

int main()
{

	std::vector<int> vector_test;
	vector_test.push_back(7802);
	vector_test.push_back(1437);
	vector_test.push_back(1);
	vector_test.push_back(0);
	vector_test.push_back(-1);
	vector_test.push_back(15);
	vector_test.push_back(-18);
	vector_test.push_back(42);
	vector_test.push_back(21);
	vector_test.push_back(230);

	std::vector<int> vector_test1;
	vector_test1.push_back(7802);
	vector_test1.push_back(1437);
	vector_test1.push_back(1);
	vector_test1.push_back(0);
	vector_test1.push_back(-1);
	vector_test1.push_back(15);
	vector_test1.push_back(-18);
	vector_test1.push_back(42);
	vector_test1.push_back(21);
	vector_test1.push_back(230);

	std::vector<int> vector_test2(10, 0);

	transform(vector_test.begin(), vector_test.end(), vector_test1.begin(), vector_test2.begin(), std::plus<int>());

	std::cout << vector_test2[0] << std::endl;

	return 0;
}
```

# C++ gère l’allocation dynamique

To insert a letter into a `std::string`, you can utilize the `insert` method provided by the `std::string` class. This method has several overloads for different use cases, but the most straightforward way to insert a single character would be to use the version of `insert` which takes a position and a count for the character to be inserted [cplusplus.com](https://cplusplus.com/reference/string/string/insert/).

Here's an example of how to use it:

```cpp
std::string str = "Hello, World!";
str.insert(7, 1, 'C'); // Insert 'C' at position 7
std::cout << str << std::endl; // Outputs: "Hello, CWorld!"
```

In this example, the `insert` method is used to insert the character 'C' at the 7th position in the string `str`. The first argument to `insert` is the position at which to insert the character, and the second argument is the character to insert.

Regarding your question about the variable declaration of type `std::string` on the stack, there's no issue with adding a letter to a `std::string` declared on the stack. The `std::string` class in C++ automatically manages the memory for the string data. When you add a letter to a `std::string`, it automatically allocates more memory if needed [stackoverflow.com](https://stackoverflow.com/questions/17810329/string-allocation-in-c).

```cpp
std::string str = "Hello";
str += '!';
std::cout << str << std::endl; // Outputs: "Hello!"
```

In this example, the `+=` operator is used to append a character to the end of the `std::string` `str`. The `std::string` class automatically handles any necessary memory allocation.

It's worth noting that C++'s `std::string` uses dynamic allocation under the hood for its storage needs. When you create a `std::string` on the stack, the string object itself is on the stack, but the memory for the character data it manages is allocated on the heap [softwareengineering.stackexchange.com](https://softwareengineering.stackexchange.com/questions/357985/how-does-c-dynamic-allocation-work).

In other words, `std::string` is a class that automatically handles the memory management for you, so you don't need to worry about it. It handles dynamic memory allocation internally, and ensures proper cleanup of the allocated memory when the string object is destroyed, whether it was created on the stack or heap. This is a key advantage of `std::string` over C-style strings, which require manual memory management.

# Aide pour l’exercice 00

A NE PAS FAIRE :

```cpp
#include <iostream>
#include <vector>
#include <map>

template <typename T>
bool easyfind(const T & haystack, const int & needle)
{

	for (typename T::const_iterator it = haystack.begin(); it!=haystack.end(); ++it)
	{
		std::cout << *it << std::endl;
		if (*it == needle)
		{
			return true;
		}

	}
	return false;
}

int main ()
{
	std::vector<int> vector0;

	vector0.push_back(3);
	vector0.push_back(1);
	vector0.push_back(4);
	vector0.push_back(28000000);

	std::cout << easyfind(vector0, 30) << std::endl;

	return 0;
}
```

# Aide pour l’exercice 02

To enable the use of iterators with your `MutantStack` class, you would need to expose the underlying container's iterator types and methods. In the case of `std::stack`, the underlying container is a `std::deque` by default, which has its own `begin` and `end`methods returning iterators.

Here's how you could modify your `MutantStack` class to allow for this:

```cpp
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::deque<T>::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }
};
```

In this code, `typedef typename std::deque<T>::iterator iterator;` creates a new type alias `iterator` that corresponds to the iterator type of the underlying `std::deque`. This allows you to use `MutantStack<int>::iterator` in your code.

Then, the `begin` and `end` methods return the `begin` and `end` iterators of the underlying `std::deque` respectively. These methods allow you to use `mstack.begin()` and `mstack.end()` in your code.

Now, you can use code like this in your `main` function:

```cpp
MutantStack<int> mstack;
mstack.push(14);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
```

This code creates a `MutantStack` of `int`, pushes an integer onto the stack, and then retrieves `begin` and `end` iterators for the stack [bytes.com](https://bytes.com/topic/c/answers/704073-making-iterator-custom-container-class) [stackoverflow.com](https://stackoverflow.com/questions/4925148/c-proper-way-to-iterate-over-stl-containers).

**What is the difference between this line of code : `typedef typename Container<T>::iterator iterator;`and this line of code :`using iterator = typename Container::iterator;`**

The key difference between the two lines of code lies in their syntax and not in their functionality. Both lines declare a type alias named `iterator` for the type `Container::iterator`.

The line:`typedef typename Container<T>::iterator iterator;`uses the `typedef` keyword to define `iterator` as an alias for `Container<T>::iterator`.

On the other hand, the line:`using iterator = typename Container::iterator;`uses the `using` keyword to define `iterator` as an alias for `Container::iterator`.

The `typedef` keyword is the traditional C++ mechanism for creating type aliases, while the `using` keyword is a more recent addition to the language introduced in **C++11**. The `using` keyword is generally considered more readable and flexible than `typedef`, especially when dealing with complex types like function pointers or templates. However, both lines of code achieve the same result in this context [cplusplus.com](https://cplusplus.com/forum/beginner/112649/).

**Precisions a propos de typedef**

Cette ligne dans la partie public de la classe MutantStack :

```cpp
typedef typename std::deque<T>::iterator iterator;
```

permet; avec l’opérateur de résolution de portée; d’utiliser cette syntaxe dans le main :

```cpp
MutantStack<int>::iterator it = mstack.begin();
```

Ainsi cela reviendrait à écrire ceci dans le main :

```cpp
MutantStack<int>::std::deque<T>::iterator  it = mstack.begin();
```

L’opérateur :: permet de dire au main “Dans la classe MutantStack, va utilise la fonction begin qui doit me renvoyer un iterator sur mon objet MutantStack<T>”. Dans la classe le typedef fais son travail, c’est à dire qu’il renvoie un iterator de type std::deque<T>::iterator issue de la classe deque chaque fois que la fonction membre begin est appelée.

Cela pourrait fonctionner aussi avec le typedef suivant :

```cpp
typedef typename std::stack<T>::container_type::iterator myiterator;
```

Ici le mot clé container_type fait référence à m’importe quel type de container utilisé dans la stack car l’objet stack est templaté ainsi :

```cpp
std::stack<T,Container>::stack
```

Par défaut le container est un deque mais on peut préciser quel type de container un objet stack doit utiliser. Si on veut une MutantStack capable de s’adapter à n’importe quel type de stack il vaudrait mieux utiliser cette syntaxe.

Pour finir au sujet du mot clé container_type il est définis au sein de la classe Stack ainsi :

| Member type | Definition |
| --- | --- |
| `container_type` | Container |
| `value_type` | Container::value_type |
| `size_type` | Container::size_type |
| `reference` | Container::reference |
| `const_reference` | Container::const_reference |

# Sources

[Utilisez les itérateurs et les foncteurs](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs)

[Découvrez la puissance des algorithmes](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532666-decouvrez-la-puissance-des-algorithmes)

[Les+principaux+conteneurs+du+Cpp.pdf](CPP08%20cd20f9c55f174fce980760c9e2ff89a3/LesprincipauxconteneursduCpp.pdf)

[Du C au C++ - La classe vector](https://fdrouillon.developpez.com/tutoriels/c-au-cpp-programmation-procedurale-a-objet/vecteurs/)