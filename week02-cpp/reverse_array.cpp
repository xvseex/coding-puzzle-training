#include <iostream>
#include <vector>

int main() {
	std::vector<int> numbers = {1, 2, 3, 4, 5};

	int left = 0;
	int right = numbers.size() -1;

	while (left < right) {
		int temp = numbers[left];
		numbers[left] = numbers[right];
		numbers[right] = temp;

		left++;
		right--;
	}

	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
