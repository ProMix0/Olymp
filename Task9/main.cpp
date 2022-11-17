#include <iostream>
#include <bitset>
#include <string>

int main()
{
	uint64_t a, b;
	std::cin >> a >> b;
	if (a == b)
	{
		std::cout << 0 << std::endl;
		return 0;
	}
	std::string astr = std::bitset<64>(a).to_string(), bstr = std::bitset<64>(b).to_string();
	auto aptr = astr.find('1');
	auto bptr = bstr.find('1');
	astr = astr.substr(aptr == std::string::npos ? 63 : aptr);
	bstr = bstr.substr(bptr == std::string::npos ? 63 : bptr);
	int indx = 0;
	if ((indx = astr.find(bstr)) != std::string::npos)
		std::cout << indx << std::endl;
	else
		std::cout << -1 << std::endl;
	return 0;
}