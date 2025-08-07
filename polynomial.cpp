#include<iostream>

using namespace std;

class Polynomial{
    private:
        int* degCoeff;
        int capacity;
        void resize(){
            capacity *= 2;
            int* temp = new int[capacity];
            for(int i = 0; i<(capacity/2); ++i)
                temp[i] = degCoeff[i];
            for(int i = capacity/2; i<capacity; ++i)
                temp[i] = 0;
            delete[] degCoeff;
            degCoeff = temp;
        }
    public:
        Polynomial()
            : capacity(5){
                degCoeff = new int [capacity];
                for(int i = 0; i<capacity; ++i)
                    degCoeff[i] = 0;
            }
        Polynomial( Polynomial const& p2 ){
            capacity = p2.capacity;
            degCoeff = new int[capacity];
            for(int i = 0; i<capacity; ++i)
                degCoeff[i] = p2.degCoeff[i];
        }
        ~Polynomial(){
            delete[] degCoeff;
        }
        void setCoeff(int deg, int coeff){
            while( deg >= capacity )
                resize();
            degCoeff[deg] = coeff;
        }
        int getCoeff(int deg){
            if(deg >= capacity)
                return 0;
            return degCoeff[deg];
        }
        Polynomial& operator=(Polynomial const& p2){
            while(capacity<p2.capacity)
                resize();
            for(int i = 0; i<p2.capacity; ++i)
                degCoeff[i] = p2.degCoeff[i];
            return *this;

        }
        Polynomial operator+(Polynomial const& p2)const{
            Polynomial sum;
            int highsize = (capacity > p2.capacity) ? capacity : p2.capacity;
            int lowsize = (capacity > p2.capacity) ? p2.capacity : capacity;
            Polynomial const& bigger = (capacity > p2.capacity) ? *this : p2;
            while(sum.capacity < highsize)
                sum.resize();
            for(int i = 0; i< lowsize; ++i)
                sum.degCoeff[i] = degCoeff[i] + p2.degCoeff[i];
            for( int i = lowsize; i<highsize; ++i )
                sum.degCoeff[i] = bigger.degCoeff[i];
            return sum;
        }
        Polynomial operator-(Polynomial const& p2)const{
            Polynomial sum;
            int highsize = (capacity > p2.capacity) ? capacity : p2.capacity;
            int lowsize = (capacity > p2.capacity) ? p2.capacity : capacity;
            Polynomial const& bigger = (capacity > p2.capacity) ? *this : p2;
            while(sum.capacity < highsize)
                sum.resize();
            for(int i = 0; i< lowsize; ++i)
                sum.degCoeff[i] = degCoeff[i] -  p2.degCoeff[i];
            for( int i = lowsize; i<highsize; ++i )
                sum.degCoeff[i] = 0 -  bigger.degCoeff[i];
            return sum;
        }
        Polynomial operator*(Polynomial const& p2){
            Polynomial const& bigger = (capacity > p2.capacity) ? *this : p2;
            Polynomial const& smaller = (capacity > p2.capacity) ? p2 : *this;
            Polynomial product;
            while( product.capacity < (capacity + p2.capacity ))
                product.resize();
            for( int i = 0; i<bigger.capacity; ++i ){
                for( int j = 0; j<smaller.capacity; ++j ){
                    int deg = i + j;
                    int coeff = bigger.degCoeff[i] * smaller.degCoeff[j];
                    product.degCoeff[deg] += coeff;
                }
            }
            return product;
        }
        void print()const{
            for( int i = 0; i<capacity; ++i ){
                if(degCoeff[i] != 0)
                    cout << degCoeff[i] << 'x' << i << ' ';
            }
            cout << endl;
        }
};

int main(){
    int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoeff(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoeff(degree2[i],coeff2[i]);
    }
    first.print();
    second.print();
    Polynomial third = first *  second;
    third.print();
    /*

    cin >> choice;

    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;

        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }
    */

    return 0;
}
