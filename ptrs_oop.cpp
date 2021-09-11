#include <iostream>
#include <string>

class Person
{
private:
	char* name_;
	int id_;
public:
	Person() : id_(0)
	{
		std::cout << "Default constructor was called" << std::endl;
		name_ = nullptr;
	}
	Person(const char* name, int id) : id_(id)
	{
		std::cout << "Constructor was called" << std::endl;
		name_ = new char[strlen(name) + 1];
		//for (int i = 0; i < strlen(name); i++) { name_[i] = name[i]; }
		memcpy(name_, name, strlen(name));
		name_[strlen(name)] = '\0';
	}
	Person(const Person& p) : id_(p.id_)
	{
		std::cout << "Copy-Constructor was called" << std::endl;
		if (p.name_ == nullptr)
			name_ = nullptr;
		else
		{
			name_ = new char[strlen(p.name_) + 1];
			memcpy(name_, p.name_, strlen(p.name_) + 1);
			// p is guaranteed to have \0 from its defenition !!!
		}
	}
	Person& operator=(const Person& p)
	{
		std::cout << "Assignment opeator was called" << std::endl;
		if (this == &p)
			return *this;
		if (name_)
			delete[] name_;
		id_ = p.id_;
		name_ = new char[strlen(p.name_) + 1];
		memcpy(name_, p.name_, strlen(p.name_) + 1); 
		return *this;
	}
	~Person()
	{
		std::cout << "Destructor was called" << std::endl;
		delete[] name_;
	}
};

static Person pStatic("pStat", 555);

void f1(Person p)
{
	return;
}
Person f2()
{
	Person temp("bla", 0);
	return temp;
}
void f3(Person* p)
{
	return;
}
Person* f4()
{
	Person* temp = new Person("M", 8);
	return temp;
}
void f5(Person& p)
{
	return;
}
Person& f6()
{
	return pStatic;
}

#if 0
int main()
{
	Person p("abc", 1234);
#if 0
	/* Pass and Return by value */
	std::cout << std::endl;
	f1(p);
	std::cout << std::endl;
	p = f2();
#endif
#if 0
	/* Pass and Return by address */
	std::cout << std::endl;
	f3(&p);
	std::cout << std::endl;
	Person* ret_val = f4();
#endif
#if 0
	/* Pass and Return by reference */
	f5(p);
	std::cout << std::endl;
	p = f6();
#endif
	return 0;
}
#endif