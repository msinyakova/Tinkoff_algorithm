#include <iostream>
#include <string>
#include <list>

int main()
{
	std::string str;
	std::cin >> str;

	std::list<char> brackets;
	for(int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			brackets.push_back(str[i]);
		} else {
			if (brackets.size() == 0) {
				std::cout << "no" << std::endl;
				return 0;
			}
			if ((str[i] == ')' && brackets.back() != '(') ||
				 (str[i] == ']' && brackets.back() != '[') ||
				 (str[i] == '}' && brackets.back() != '{')) {
				std::cout << "no" << std::endl;
				return 0;
			}
			brackets.pop_back();
		}
	}
	if (brackets.size() != 0)
		std::cout << "no" << std::endl;
	else
		std::cout << "yes" << std::endl;
	return 0;
}
