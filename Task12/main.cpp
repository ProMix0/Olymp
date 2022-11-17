#include <iostream>
#include <string>

int main()
{
	std::string input;
	int diffs = 0;
	std::cin >> input;
	long len = input.length();
	for (int i = 0; i < len ; i++)
	{
		if (input[i] != input[len - i - 1])
			diffs++;
	}
	if(diffs == 2 || diffs == 0)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return 0;
}