#include <iostream>

void f1(char c)
{
	c += 1;
}

void f2(char& c)
{
	c += 1;
}

void f3(char* c_p)
{
	*c_p = *c_p + 1;
}
int main()
{
	char c = 'a';
	std::cout << c << std::endl;
	f1(c);
	std::cout << c << std::endl;

	f2(c);
	std::cout << c << std::endl;

	f3(&c);
	std::cout << c << std::endl;
	return 0;
}
