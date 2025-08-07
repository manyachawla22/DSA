int power( int base, exp) 
{
    long  result = 1;
    for(i = 1; i <= exp; i++)
          result *= base;
    return result;
}
