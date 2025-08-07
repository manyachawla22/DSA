#include<cstring>
void shiftString( char arr[], int x){
	int len = strlen( arr);
	for( int i = len; i >= 0; --i ){
		arr[i+x] = arr[i];
	}
}

