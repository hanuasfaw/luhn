/**
    Luhn Algorithm: Evaluate the validity of a given card number.
    @file validator.cpp
    @author Brehanu Bugg
    @version 1.0
*/

// import necessary header files
#include <iostream>
#include <string>
#include <vector>

// to eliminate the repetitive std:: prefix
using namespace std;

/**
    Retrieves necessary numbers and normalizes them to be less than 10.
    @param card_number, the card number as a string.
    @return result, a integer vector array with the numbers to be iterated.
*/
vector<int> split_numbers(string card_number) {
    vector<int> result;

    // start at the end-2 and skip every 2 index
    for(int index = card_number.length()-2; index >= 0; index -= 2) {
        // card_number[index] - 48 converts the string into integer
        int current = (card_number[index] - 48) * 2;
        
        if(current > 9) {
            string as_string = to_string(current);

            // get the first and second digit
            int first = as_string[0] - 48;
            int second = as_string[1] - 48;

            result.push_back(first + second);
        } else {
            result.push_back(current);
        }
    }

    // start at the very end and cover the skipped indices
    for(int index = card_number.length()-1; index >= 0; index -= 2) {
        // card_number[index] - 48 converts the string into integer
        int current = card_number[index] - 48;
        result.push_back(current);
    }

    return result;
}

/**
    Sums the numbers in a given integer vector array.
    @param numbers, the integer vector array to be iterated.
    @return result, a single integer which is the sum.
*/
int sum_numbers(vector<int> numbers) {
    int result = 0;
    for(int number : numbers)
        result += number;
    return result;
}

/**
    Run the Luhn algorithm to evaluate the validity of a given card number.
    @param card_number, the card number as a string.
    @return result, 0 if the card number is valid, 1 if not.
*/
int Luhn(string card_number) {
    // only get the required numbers from the card
    vector<int> numbers = split_numbers(card_number);

    // get the total sum
    int total_sum = sum_numbers(numbers);

    // only if the total sum is a multiple of 10, the card number is valid
    if((total_sum % 10) == 0)
        return 0;   // valid number
    else
        return 1;   // invalid number
}

/**
    Run the Luhn algorithm and print whether or not the card is valid or not.
    @return 0 if program is successful.
*/
int main() {
    // will hold the card number from the user
    string card_number;

    // collect user's card number
    cout << "Enter a card number to verify: ";
    cin >> card_number;

    // run the Luhn algorithm
    int result = Luhn(card_number);

    if(result == 0)
        cout << "This card number is valid!" << endl;
    else
        cout << "This card number is NOT valid." << endl;
    
    // must return a integer for the main function return type
    return 0;
}