# Luhn and Card Number Validity

by **Brehanu Bugg**

Banks and websites that require card number information need an efficient way to quickly evaluate if the number a user inputs is valid. Many times, websites will evaluate the card number as the user is typing it in. This is all possible because of the [Luhn algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm). It is a simple, but powerful, checksum formula devloped by IBM scientist [Hans Peter Luhn](https://en.wikipedia.org/wiki/Hans_Peter_Luhn), for whom the algorithm is named after.

## Running the Program

Once you've downloaded this project—either via GitHub or your command line—open up a new terminal session and run the following command:

`g++ --std=c++11 validator.cpp && ./a.out`

The first half of the command—up to the &&—will compile the C++ code into a executable file. This will only need to be run once. The second half of the command—post &&—will execute the program. If you want to run the program again, you just need to run the `./a.out` command.

It will prompt you for a card number. When you click enter, it will immediately tell you if the number is valid or not. Your input is not stored locally or sent anywhere.

## The Algorithm

Suppose a user inputs the card number `79927398713` into Amazon to buy a new pair of shoes. The Luhn algorithm works in 6 simple steps.

**1. Starting at the second to last number—and going from right-to-left—get every other number.**

The second-to-last number in this scenario is 1. Every other number in the left direction from 1 are as follows: `1, 8, 3, 2, 9`.

**2. Multiply the numbers by 2.**

The new list is now: `2, 16, 6, 4, 18`.

**3. For the numbers that are *ABOVE* 9, add their digits to keep all numbers single digit.** For example, 12 has digits 1 and 2 so the result will be 3.

The modified list is now: `2, 7, 6, 4, 9`.

**4. Add all the remaining numbers not chosen from the card to this list.**

The full list is now: `2, 7, 6, 4, 9, 7, 9, 7, 9, 7, 3`.

**5. Sum the list.**

The total is: 70.

**6. Check if the sum is a multiple of 10.** If the sum is multiply of 10—where (x % 10) = 0—, the card number is valid. Otherwise, it is not.

`(70 % 10) = 0`, therefore card number `79927398713` is valid.

*It's important to note that even if a card number sums to a multiple of 10, it doesn't mean that it exists. Just that it passes the number test.*

## Time Complexity

For the Luhn algorithm, the complexity would be `O(n) = n` since we have to examine every digit regardless. If one digit was a little too high or a little too low, the entire card becomes invalid. There's no way to skip a digit, unlike a sorting algorithm like binary search, because otherwise evaluating the validity would be impossible.

However, `O(n) = n` is not bad for this algorithm because card numbers typically range from 15-16 digits. Since it's a fixed size, and not a range from say 10-1 million, the algorithm will take the same amount of time to run regardless of the actual digits. Because this algorithm is very efficient, the time complexity is irrelevant.

## C++

I've had minimal experience with C++, so I challenged myself to write this algorithm in it. I haven't written it in any other language before, so it was especially a challenge. Although extremely frustrating compared to simpler languages like Python or JavaScript, I learned a lot in the few hours it took for me to do research and piece together the language.

If you're getting started in C++, I highly recommend trying this problem once you understand variables, functions, conditionals, operations, and program structure. It is extremely rewarding once you get it.