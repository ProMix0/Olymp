#include <iostream>
#include <cmath>

int findGCD(int a, int b) {
	if (b == 0)
		return a;
	return findGCD(b, a % b);
	}

int main()
{
	int hour, min, sec, timeel;
	std::cin >> hour >> min >> sec >> timeel;
	double hourhalftop = timeel * pow(hour, 2) , minhalftop = timeel * 12 * pow(min, 2), sechalftop = timeel * 720 * pow(sec,2);
	std::cout <<sechalftop - minhalftop  << std::endl;
	//double hourarea = hourhalf / 2 * pow(hour, 2); 
	//std::cout << hourarea << std::endl;
	//double secarea = (sechalf)/2 * pow(sec,2);
	//std::cout << secarea << std::endl;
}