#include<iostream>
#include<vector>
#include<string>

using namespace std;

class student{
    private:
        int age;
        string name;
    public:
        student(int age, const string& name)
            :age(age), name(name)
        {
        }
        void display(){
            cout << name << " " << age << endl;
        }
        ostream& operator<<(ostream& out, const student& s){
            out << s.age << ' ' << s.name;
            return out;
        }
};


int main(){
    char n1[] = "abcd";
    student s1(18, n1);
    cout << s1 << s2; cout.operator<<(s1);
    s1 << cout;
    s1 + s2; => s1.operator+(s2);
    s1.display();
    n1[3] = 'e';
    student s2(20, n1);
    s1.display();
    s2.display();
    return 0;
}
