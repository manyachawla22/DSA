bool isPermutation( char arr1[], char arr2[] ){
    
    // total 94 printable characters in ASCII, initialze them with zero
    char count[94] = {0};
    
    // increase the value of ith index, which is ASCII value of char-32
    for( int i = 0; arr1[i]!='\0'; ++i ){
        int index = arr1[i] - 32;
        count[index]+=1;
    }

    // decrease the value of ith index in second array to make it zero
    for ( int i=0; arr2[i] != '\0'; ++i ){
        int index = arr2[i] -32;
        count[index]-=1;
    }

    // if array is non zero, return false
    for( int i =0; i<94; ++i ){
        if( count[i] != 0 )
            return false;
    }
    return true;
}
