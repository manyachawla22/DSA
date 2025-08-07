#include<iostream>
#include<vector>

using namespace std;

class complexNo{
    private:
        int real;
        int img;
    public:
        complexNo(int real=0, int img=0)
            : real(real), img(img){}
        void add(complexNo const &c2){
            real += c2.real;
            img += c2.img;
        }
        void multiply(complexNo const &c2){
            int c1r = real;
            real = (real * c2.real) - (img * c2.img);
            img = (c1r * c2.img) + (img * c2.real);
        }
        void print(){
            cout << real << " + i" << img <<  endl;
        }
};

int main(){
    complexNo c1;
    complexNo c2(3,4);
    c1.add(c2);
    c1.print();
    c1.multiply(c2);
    c1.print();
    c2.print();
    return 0;
}
