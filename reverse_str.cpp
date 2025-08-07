void reverse_str( char input[]){
    int i;
    for ( i=0; input[i] != '\0'; ++i );
    i-=1;
    for ( int j=0; j < i ; ++j, --i ){
        char temp = input[j];
        input[j] = input[i];
        input[i] = temp;
    }
}
