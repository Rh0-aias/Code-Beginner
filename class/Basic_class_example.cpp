#include <iostream>
using namespace std;
//g++ -I path_to_included_library Basic_class_example.cpp -o example  -O3

class MyClass{
    // Default type: Private
    int    a;
    double b;
public:
    static int StaticVar;//Sattic variables are shared with all the instances of thsi class. It can be modified! 
    static const int StaticConstVar = 0;//Only constant static variables can be initialized like this. It cannot be modified!
    int c;
    int d;
    int value;

    //Constructor
    MyClass(int init_a=0, double init_b=0, int init_c=0): a(init_a), b(init_b), c(init_c){
        cout << "MyClass1 is being created" << endl;
        /* The intialization can also be done as:
           a = init_a;
           b = init_b;
           c = init_c;
        */
    }

    //Deconsturctor
    ~MyClass(){
        cout << "MyClass1 is being deleted" << endl;
    }

    //Function can be defined inside class
    void Func_Inside(){cout << "Function can be defined inside class" << endl;}

    //Function can be defined outside class
    void Func_Outside();

    //If the name of input parameter is the same with member variable: 
    //'this->a' is the member variable while 'a' is the parameter input of SetValue function
    void SetValue(int a){this->a = a;}

    int getValue(){ return a; }
};

int MyClass::StaticVar = 666; //Intialization outside any function included main function

void MyClass::Func_Outside(){cout << "Function can be defined outside class" << endl;}

int main(){
    cout << "Demonstration of very basic C++ class usage.(without inheritance)" << endl;
    MyClass  obj(10,10.5,11);
    MyClass  obj1(10,12.5,13);
    MyClass* Ptr = new MyClass(10,12.5,13);
    obj.c = 12;//Only public member can be accessed
    obj.d = 16;
    MyClass::StaticVar = 666;// Which is equal to obj1.StaticVar = 17;
    obj.SetValue(777);
    cout << "obj's private a is set to: " << obj.getValue() << endl;
    cout << "Use '::' for class : MyClass::StaticVar=" << MyClass::StaticVar << endl;
    cout << "Use '.' for instance : obj.StaticVar=" << obj.StaticVar << endl;
    cout << "Different instances have the same StaticVar: obj.StaticVar=obj1.StaticVar=" << obj1.StaticVar << endl;
    cout << "c=" << obj.c << endl;
    cout << "d=" << obj.d << endl;
    obj.Func_Inside();
    obj.Func_Outside();
    cout << "For class pointer, using '->' " << endl;
    cout << "Ptr->StaticConstVar=" << Ptr->StaticConstVar << endl;
    return 0;
}
