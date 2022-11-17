#include <iostream>
#include <bitset>
#include <string>

int main()
{
	unsigned long a, b;
	std::cin >> a >> b;
	if (a == b)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	if (a == 0)
	{
		std::cout << -1 << std::endl;
		return 0;
	}
	std::string astr = std::bitset<64>(a).to_string(), bstr = std::bitset<64>(b).to_string();
	astr = astr.substr(astr.find('1'));
	bstr = bstr.substr(bstr.find('1'));
	int indx = 0;
	if ((indx = astr.find(bstr)) != std::string::npos)
		std::cout << indx << std::endl;
	else
		std::cout << -1 << std::endl;
	return 0;
}