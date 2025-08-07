int* mergearr( int arra[], int sizea, int arrb[], int sizeb ){
    int arrm[sizea+sizeb];
    int a =0;
    int b =0;
    for ( int index = 0; index < sizea + sizeb; ++index  ){
        if ( arra[a] < arrb[b] ){
            arrm[index] = arra[a];
            ++a;
        }
        else{
            arrm[index] = arrb[b];
            ++b;
        }
    }
    return arrm;
}
