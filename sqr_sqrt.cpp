#include <iostream>
#include <cmath>
#include <iomanip>

const int N = 100000;

int main()
{
	long double c;
	std::cin >> c;
	long double eps = 1e-10;
	long double left = 0.0;
	long double right = sqrt(c);
	for (int i = 0; i < N; i++) {
		long double middle = (right + left) / 2;
		if (sqrt(middle) + pow(middle, 2) - c > eps)
			right = middle;
		else
			left = middle;
	}
	std::cout << std::setprecision(10) << right << std::endl;
	return 0;
}