void reverseEachWord(char arr[]) {
    for( int i=0; arr[i] != '\0'; ++i ){
        int wordLen = 0;
        while( (arr[wordLen+i] != ' ') && (arr[wordLen+i] != '\0'))
            ++wordLen;
        --wordLen;
        i += wordLen;
        int end=i-1;
        for( int start=i-wordLen; start<end; ++start, --end){
            char temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
        }
    }
}
