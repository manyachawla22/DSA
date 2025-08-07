bool isPalindrome(char str[]) {
    int length = -1;
    int i =0;
    while ( str[i] != '\0'){
        ++length;
        ++i;
    }
    int count = length;
    for ( i =0; i != (count+1)/2; ++i, --length ){
        if ( str[i] != str[length]){
            return false;
        }
    }
    return true;
}
