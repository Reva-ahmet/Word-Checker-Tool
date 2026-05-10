#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

int main() {
    char choice; // Fixed spelling from 'choise' to 'choice'

    cout << "====================================" << endl;
    cout << "          WORD CHECKER TOOL         " << endl;
    cout << "    (Using Stacks & Queues Logic)   " << endl;
    cout << "====================================" << endl;

    do {
        string input;
        stack<char> s;
        queue<char> q;

        cout << "\nEnter a word or phrase to check: ";
        getline(cin, input);


        // 1. Load the characters into both structures

        for (char c : input){
            if (isspace(c)) continue;  // Skip spaces

            //If we type "TEN"
            //The Queue looks like: [T, E, N] (T is at the front)
            //The Stack looks like: [N, E, T] (N is at the top)

            char cleanchar = tolower(c);
            s.push(cleanchar);
            q.push(cleanchar);
        }


        // 2. Logic Check

        bool isPalindrome = true;
        //tells the computer to keep checking until the stack is empty
        while (!s.empty()) {
                //s.top() looks at the last letter (from the Stack)
                //q.front() looks at the first letter (from the Queue)
            if (s.top() != q.front()) {
                //If we find a mismatch, we set our variable to false and break (stop the loop) immediately to save time
                isPalindrome = false;
                break;
            }
            //If the letters matched, we "throw them away" so we can look at the next pair of letters in the next turn of the loop
            s.pop();
            q.pop();
        }

        // 3. Display Result
        cout << "RESULT: ";
        if (isPalindrome) {
            cout << "Yes, it is a palindrome!" << endl;
        } else {
            cout << "No, it is not a palindrome." << endl;
        }

        // 4. Ask to continue
        cout << "\nWould you like to check another word? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y'); // Fixed 'choise' to 'choice'

    cout << "\nThank you for using the Word Checker Tool! Goodbye." << endl;

    return 0; // Added this to properly end the program
}
