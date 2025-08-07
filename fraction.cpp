#include<iostream>
#include<vector>

using namespace std;

class fraction{
    private:
        int num;
        int den;
        int hcf()const{
            int hcf = 1;
            int min = (num>den) ? den : num;
            for(int i = 1; i<= min; ++i){
            if( num%i == 0 && den%i == 0 )
                hcf = i;
            }
            return hcf;
        }
        void simplify(){
            int gcd  = hcf();
            num /= gcd;
            den /= gcd;
        }
    public:
        fraction(): num(0),den(1){
            simplify();
        }
        fraction(int num , int den = 1)
            : num(num), den(den){
                simplify();
            }
        void display() const {
            cout << num << "/" << den << endl;
        }
        int getNum() const {
            return num;
        }
        int getDen() const {
            return den;
        }
        void setNum(int n){
            num = n;
        }
        void setDen(int d){
            den = d;
        }
        fraction operator*( fraction const &f2 )const {
            int x = num * f2.num;
            int y = den * f2.den;
            fraction product(x,y);
            product.simplify();
            return product;
        }
        fraction operator+( fraction const &f2 )const{
            int x  = (num * f2.den) + (f2.num * den);
            int y = den * f2.den;
            fraction fsum(x,y);
            fsum.simplify();
            return fsum;
        }
        bool operator==( fraction const& f2 )const{
            return ((num == f2.num) && (den == f2.den));
        }
        fraction& operator++(){
            num += den;
            simplify();
            return *this;
        }
        fraction operator++(int){
            fraction copy(num,den);
            num += den;
            simplify();
            return copy;
        }
        fraction& operator+=( fraction const& f2 ) {
            *this = *this + f2;
            return *this;
        }

};

int main(){

    fraction f5;
    fraction f1(10,2), f2(15,4);
    f1.display();
    f1++;
    ++f1;
    f1.display();
    /*
    fraction f3 = f1.add(f2);
    f1.display();
    f2.display();
    f3.display();
    fraction f4(1);
    fraction f5 = f4 + f4 + f4;
    f5.display();
    fraction f6 = f5 * f5;
    f6.display();
    bool result = f6==f5;
    cout << result << endl;
    */
    return 0;
}
