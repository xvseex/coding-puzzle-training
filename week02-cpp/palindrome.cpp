#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string word;
	std::cout << "Enter a word or phrase: ";
	std::getline (std::cin, word);

	std::string cleaned = "";
	for (char c : word) {
		if (std::isalpha(c)) {
			cleaned += std::tolower(c);
		}
	}

	std::string reversed = cleaned;
	std::reverse(reversed.begin(), reversed.end());

	if (cleaned  == reversed) {
		std::cout << word << " is a palindrome." << std::endl;
	} else {
		std::cout << word << " is not a palindrome." << std::endl;
	}

	return 0;
}
