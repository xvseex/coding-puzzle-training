# Week 3: Python lists, sets, and dicts

Five beginner problems, each with tests.

## Problems
- Two SUm: brute force (0(n^2)) and dict version (0(n))
- Contains Duplicate: uses a set
- VAlid Anagram: counts letters with a dict
- Majority Element: counts values with a dict
- Single Number: counts values with a dict

## Run 
python3 problems.py

Prints 'All tests passed' if every test succeeds.

## What I learned
- A dict remembers things I have already seen, so I don't have to re-scan the list.
- 'return' hands a value back to the caller; 'print' only shows it on screen.

## What broke
I used 'print(count)' inside a function instead of 'return count', so the function gave back 'None'. CHange it to 'return' fixed it. 
