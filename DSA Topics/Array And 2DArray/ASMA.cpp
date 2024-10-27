#include <iostream>
using namespace std;

int main() {
    // Define each row for each letter
    string A[] = {
        "    @    ",
        "   @ @   ",
        "  @@@@@  ",
        " @     @ ",
        "@       @"
    };

    string S[] = {
        "  $$$$$  ",
        " $       ",
        "  $$$$$  ",
        "       $ ",
        "  $$$$$  "
    };

    string M[] = {
        "M       M",
        "MM     MM",
        "M M   M M",
        "M  M M  M",
        "M   M   M"
    };

    // Smaller heart pattern, fully displayed
    string heart[] = {
        " **   ** ",
        "*********",
        " ******* ",
        "  *****  ",
        "   ***   ",
        "    *    "
    };

    // Print the letters row by row
    for (int i = 0; i < 5; i++) {
        cout << A[i] << "   " << S[i] << "   " << M[i] << "   " << A[i];
        if (i < 6) {
            cout << "   " << heart[i];  // Attach the heart to the same line
        }
        cout << endl;
    }

    // Print the last row of the heart
    cout << "                         " << heart[5] << endl;

    return 0;
}
