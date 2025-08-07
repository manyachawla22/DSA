#include<cmath>
#include <cstring>
int stringToNumber(char input[]) {
    const int asciiZero = '0';
    if ( ( input == nullptr ) || ( input[0] == '\0') )
        return 0;    
    int curr = (input [0] - asciiZero);
    curr *= pow(10, strlen(input)-1);
    return curr + stringToNumber( input +1);
}

#include <iostream>
using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}


