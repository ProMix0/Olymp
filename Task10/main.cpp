#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	uint32_t n, routes;
	std::vector<uint64_t> heights;
	uint64_t height = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		uint32_t tmp;
		std::cin >> tmp;
		heights.push_back(tmp);
	}
	std::sort(heights.begin(), heights.end(), std::greater<uint64_t>());
	uint32_t maxp = 0, minp = heights.size() - 1;
	height += heights[maxp] - heights[minp];
	height += heights[maxp++] - heights[minp - 1];
	routes += 2;
	while (routes < n - 1)
	{
		height += heights[maxp++] - heights[minp--];
		routes++;
	}
	std::cout << height << std::endl;
	return 0;
}