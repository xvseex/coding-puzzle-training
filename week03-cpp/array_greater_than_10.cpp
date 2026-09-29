#include <iostream>

int main() {
	int nums[6] = {5, 56, 45, 2, 10};
	int size = 6;

	int count = 0;
	for (int i = 0; i < size; i++) {
		if (nums[i] < 10) {
			count = count + 1;
		}
	}
	std::cout<< count << std::endl;
	return 0;
} 
