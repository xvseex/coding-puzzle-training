#include <iostream>

int main() { 
	int nums[5] = {4, 7, 1, 9, 2};
	int size = 5;

	int total = 0;
	for (int i = 0; i < 5; i++) {
		total = total + nums[i];
	}
	std::cout << total << std::endl;
	return 0;
}
