# CPP05

# EX00

## La classe exception

```cpp
class exception 
{
public:
    exception() throw(){ } //Constructeur.
    virtual  exception() throw(); //Destructeur.
 
    virtual const char* what() const throw(); //Renvoie une chaîne "à la C" contenant des infos sur l'erreur.
};
```

La classe exception contient des fonctions virtuelles. Ainsi on peut dériver nos propres classes erreurs sans problème de résolution des liens. Mais il ne faut pas oublier de throw les exceptions sous forme de référence afin que ce soit les méthodes de la classe fille qui soient utilisées.

[Gérez des erreurs avec les exceptions](https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532931-gerez-des-erreurs-avec-les-exceptions)

## Nested classes

[Nested Classes in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/nested-classes-in-c/)

Dans le cadre de l’exercice, les nested class sont implémentées ainsi : 

```cpp
class Bureaucrat
{

	public:
    	Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator= (const Bureaucrat& rhs);
		~Bureaucrat();
		std::string getName() const;
		void setGrade(int grade);
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too High !!!";
			}
		};

		class GradeTooLowException : public std::exception
		{

			virtual const char* what() const throw()
			{
				return "Grade too Low !!!";
			}

		};

	private:	
		const std::string	_name;
		int					_grade;

};
```

Ensuite on appel ces nested class en utilisant une référence vers l’objet parent, c’est à dire exception :

```cpp
try
	{
		Bureaucrat ignazio("Ignazio", 2);
		std::cout << ignazio << std::endl;
		ignazio.incrementGrade();
		std::cout << ignazio << std::endl;
		ignazio.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
```

Si on essaie de catch directement l’erreur GradeTooLowException ou GradeTooHighException, il faudrait utiliser cette syntaxe :

```cpp
std::cout << std::endl;
	std::cout << "TEST 3 : Bureaucrat : José, grade 150" << std::endl;
	try
	{
		Bureaucrat jose("Jose", 150);
		std::cout << jose << std::endl;
		jose.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

```

Mais cela ne peut fonctionner que avec une nested class avec des fonctions publics :

```cpp
class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw()
			{
				return "Grade too Low !!!";
			}
	};
```

## Overloading the << Operator

```cpp
ostream& operator<< (std::ostream& out, const MyObject& myObject);
```

Ceci est la signature de la fonction qui overload <<.  Nous avons :

- << : l’opérateur binaire
- opérateur de gauche : référence vers l’objet std::ostream. std::cout est en fait un objet de type std::ostream.
- opérateur de droite : référence vers mon objet

```cpp
std::ostream& operator<< (std::ostream& out, const MyObject& myObject)
{
    out << "example" << myObject.getAttribute() ; 
    return out;
}
```

Ici std::cout est devenu le paramètre out que l’on retourne entant que référence. Il est indispensable que l’overloading soit fait de cette manière. Les autres possibilités sont fausses :

- `ostream operator<< (std::ostream& out, const MyObject& myObject);`: impossible car l’objet ostream ne peut pas être copié
- `void operator<< (std::ostream& out, const MyObject& myObject);` : ne fonctionnera pas si on veut chainer les appels. Par exemple : `std::cout << myObject0 << “\n”` . Si on execute cette ligne de commande, elle va être interpreté ainsi : `void << “\n”`. Cela n’a pas de sens. Ce prototype ne fonctionnerait que pour `std::cout << myObject0`.

[Overloading the << Operator for Your Own Classes](https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170)

[21.4 — Overloading the I/O operators](https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/)
