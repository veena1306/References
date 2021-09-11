#include <iostream>
#include <string>

int main()
{
	std::string str = "abc";
	std::string& r_str1 = str;
	// std::string&& rr_str = str;
	std::string&& rr_str = str + "aaa"; // compiles - rvalue ref extends lifetime
	const std::string& r_str = str + "aaa"; // lvalue ref to const extends lifetime

	rr_str += "m"; // can modify through ref to non-const (unlike the const lval version)
	return 0;
}
