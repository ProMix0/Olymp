#include <iostream>
#include <string>

int jump(int start, int goal, int maxdist, std::string pads)
{
	int jumps = 0;
	if (start == goal)
		return 1;
	for (int i = start - maxdist; i <= start + maxdist; i++)
	{
		if (i == start)
			continue;
		if (i < 0)
			continue;
		if (i > goal)
			break;
		if (pads[i] == '0')
			continue;
		std::string padsl = pads;
		padsl[start] = '0';
		jumps += jump(i, goal, maxdist, padsl);
	}
	return jumps;
}

int main()
{
	int n, k;
	std::string pads = "";
	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
		pads += "1";
	std::cout << jump(0,n - 1,k,pads) << std::endl;
	return 0;
}