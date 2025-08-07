#include<iostream>
using namespace std;
void spiralPrint(int **arr, int rows, int colms)
{
    int x, y, limx, limy, limit;
    x = y = 0;
    limx = rows-1;
    limy = colms-1;
    if( rows == colms)
        limit = (rows+1)/2;
    else{
        if( rows < colms )
            limit = (rows+1)/2;
        else
            limit = (colms+1)/2;
    }
        limit = (colms+1)/2;
    for( int k=0; k < limit; ++k ){
        while( y <= limy ){
            cout << arr[x][y] << " ";
            ++y;
        }
        --y;
        ++x;
        while( x <= limx ){
            cout << arr[x][y] << " ";
            ++x;
        }
        --x;
        --y;
        while( (x+y) >= rows-1 ){
            cout << arr[x][y] << " ";
            --y;
        }
        ++y;
        --x;
        while ( x > y ){
            cout << arr[x][y] << " ";
            --x;
        }
        ++y;
        ++x;
        --limy;
        --limx;
    }
}
