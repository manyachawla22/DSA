void trimspaces(char arr[])
{
    for ( int i=0; arr[i] != '\0'; ++i ){
        if( arr[i] == ' ' ){
            int j=i;
            while( arr[j] != '\0' ){
                arr[j]=arr[j+1];
                ++j;
            }
            --i;
        }
    }
}
/* a better approach can be used by having two pointers - spaceindex & charindex, and they can be swapped. This would solve the problem in order of 3n
 * 1) find first spaceindex
 * 2) find first charindex after space
 * 3) for i in range( charindex , infinity )
 *  swap spaceindex and input[i] if input[i] != ' ' 
 *  increment spaceindex         */
