#include "Span.hpp"
#include <cstdlib>
#include <ctime>

#define N 5
#define M 1000000

class Display
{
	public:
		void operator()(int a) const
		{
			std::cout << a << " ";
		}
};

class GiveRandNumb
{
	private :
		const int _modulo;

	public :
		GiveRandNumb() : _modulo(0){};
		GiveRandNumb(const int n) : _modulo(n){};
		~GiveRandNumb(){};

		int operator()(){return rand() % this->_modulo;};
};

int main()
{
	srand(time(NULL));

	std::cout << "vector<int> randomNumbers : ";
	std::vector<int> randomNumbers(N);
	GiveRandNumb giveRandN(100);
	std::generate(randomNumbers.begin(), randomNumbers.end(), giveRandN);
	for_each(randomNumbers.begin(), randomNumbers.end(), Display());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST 0 : default constructor :"<<std::endl;
	Span span0;
	std::cout << "span0.size() = " << span0.size() << std::endl;
	try
	{
		span0.addNumber(18);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "TEST 1 : constructor Span(5) and function addNumber():"<<std::endl;
	Span span1(5);
	try
	{
		span1.addNumber(-49);
		span1.addNumber(-13);
		span1.addNumber(0);
		span1.addNumber(51);
		span1.addNumber(1003);
		span1.addNumber(9);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "span1 : ";
	for_each(span1.get_datas().begin(), span1.get_datas().end(), Display());
	std::cout << std::endl;
	std::cout << "Shortest span = " << span1.shortestSpan() <<std::endl;
	std::cout << "Longest  span = " << span1.longestSpan() <<std::endl;

	std::cout << std::endl;
	std::cout << "TEST 2 : copy constructor Span(span1):"<<std::endl;
	Span span2(span1);
	std::cout << "span2 : ";
	for_each(span2.get_datas().begin(), span2.get_datas().end(), Display());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST 3 : operator= :"<<std::endl;
	Span span3;
	span3 = span2;
	std::cout << "span3 : ";
	for_each(span3.get_datas().begin(), span3.get_datas().end(), Display());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST 4 : addNumbers :"<<std::endl;
	Span span4(N);
	span4.addNumbers(randomNumbers.begin(), randomNumbers.end());
	std::cout << "span4 : ";
	for_each(span4.get_datas().begin(), span4.get_datas().end(), Display());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST 5 : addNumber then addNumbers :"<<std::endl;
	Span span5(N + 1);
	span5.addNumber(1000);
	span5.addNumbers(randomNumbers.begin(), randomNumbers.end());
	std::cout << "span5 : ";
	for_each(span5.get_datas().begin(), span5.get_datas().end(), Display());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST 6 : addNumber(1000) then addNumbers overflow :"<<std::endl;
	Span span6(N);
	span6.addNumber(1000);
	try
	{
		span6.addNumbers(randomNumbers.begin(), randomNumbers.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "span6 : ";
	for_each(span6.get_datas().begin(), span6.get_datas().end(), Display());
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "TEST 7 : shortestSpan and longestSpan :"<<std::endl;
	std::cout << "span5 : ";
	for_each(span5.get_datas().begin(), span5.get_datas().end(), Display());
	std::cout << std::endl;
	std::cout << "Shortest span = " << span5.shortestSpan() <<std::endl;
	std::cout << " Longest span = " << span5.longestSpan() <<std::endl;

	std::cout << std::endl;
	std::cout << "TEST 8 : shortestSpan and longestSpan :"<<std::endl;

	std::vector<int> randThousandNumbs(M);
	GiveRandNumb giveRandNtwo(M);
	std::generate(randThousandNumbs.begin(), randThousandNumbs.end(), giveRandNtwo);

	Span span8(M);
	span8.addNumbers(randThousandNumbs.begin(), randThousandNumbs.end());
	std::cout << "Shortest span = " << span8.shortestSpan() <<std::endl;
	std::cout << " Longest span = " << span8.longestSpan() <<std::endl;
	std::cout << std::endl;

	std::cout << "TEST 9 : subject :"<<std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}