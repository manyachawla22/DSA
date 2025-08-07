#include<cstring>
void shiftString( char arr[]){
	int len = strlen( arr);
	for( int i = len; i >= 0; --i ){
		arr[i+2] = arr[i];
	}
}

void replacePi(char input[]) {
	if( input[0] == '\0')
		return;
	int x =1;
	if( input[0] == 'p'){
		if( input[1] == 'i'){
			shiftString(input);
			input[0]='3';
			input[1] = '.';
			input[2] = '1';
			input [3] = '4';
			x = 4;
		}
	}
	return replacePi( input + x);

}

#include <iostream>
using namespace std;

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

