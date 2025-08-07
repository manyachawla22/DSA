#include<iostream>
using namespace std; 

bool checksequenece(char large[], char *small) {
    if ( small[0] == '\0')
        return true;
    else if( large[0] == '\0')
        return false;
    
    int index = -1, i;
    for( i = 0; large[i] != '\0'; ++i){
        for( int j = 0; small[j] != '\0'; ++j){
            if( large[i] == small[j]){
                index = j;
                break;
            }
        }
        if( index != -1)
            break;
    }
    bool result = false;
    if( index == 0)
        result = checksequenece( (large+i+1),  small+1);
    return result;

}

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true" << endl;
	else
		cout<<"false" << endl;

}

