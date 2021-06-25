#include <iostream>
#include <sstream>
#include <list>
#include <string>

int main()
{
	std::list<int> stack;
	std::string str;
	do {
		std::cin >> str;

		int n = 0;
		if (str == "push") {
			std::string help;
			std::cin >> help;
			std::istringstream iss (help, std::istringstream::in);
			iss >> n;
			stack.push_back(n);
			std::cout << "ok" << std::endl;
		} else if (str == "pop") {
			std::cout << stack.front() << std::endl;
			stack.pop_front();
		} else if (str == "front") {
			std::cout << stack.front() << std::endl;
		} else if (str == "size") {
			std::cout << stack.size() << std::endl;
		} else if (str == "clear") {
			stack.clear();
			std::cout << "ok" << std::endl;
		} else if (str == "exit") {
			std::cout << "bye" << std::endl;
		}
		
	} while (str != "exit");
	return 0;
}
