numbers = [10, 20, 30, 40, 50]
reversed_numbers = []

# loop through numbers backwards, and append each item to reversed_numbers
for i in range(len(numbers) - 1, -1, -1):
	reversed_numbers.append(numbers[i])

print("Original:", numbers)
print("Reversed:", reversed_numbers)
