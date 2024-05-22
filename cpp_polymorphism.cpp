/*
WAP to input and print employee details containing
Empcode					i/p
Empname					i/p
Designation				i/p
Salary for 12 months []	i/p
Tax						o/p
NetSalary				o/p

void getEmployee()
void putEmployee()
void calculate()
*/
using namespace std;
#include <iostream>
#include <stdio.h>
class Employee
{
private:         // access specifier
    int empcode; // data members
    char empname[20];
    char designation[20];
    long salary[12], tax, netsalary, total;

public: // access specifier
    Employee()
    {
        total = 0;
    }
    inline void getEmployee()
    {
        cout << "Enter emp code";
        cin >> empcode;
        fflush(stdin);
        cout << "Enter emp name";
        gets(empname);
        cout << "Enter designation";
        gets(designation);
        for (int index = 0; index <= 11; index++)
        {
            cout << "Enter salary";
            cin >> salary[index];
        }
    }
    inline void calculate()
    {

        for (int index = 0; index <= 11; index++)
        {
            total = total + salary[index];
        }
        if (total > 1000000)
            tax = 10000;
        else
            tax = 5000;
        netsalary = total - tax;
    }
    void putEmployee()
    {
        cout << "Empcode = " << empcode << endl;
        cout << "Employee Name = " << empname << endl;
        cout << "Designation = " << designation << endl;
        cout << "Total = " << total << endl;
        cout << "Tax = " << tax << endl;
        cout << "Net Salary = " << netsalary << endl;
    }
};
main()
{
    Employee obj; // object declaration and instantiation
    obj.getEmployee();
    obj.calculate();
    obj.putEmployee();
}

/* Inline Functions : Inline is a reserved in CPP
All member functions defined inside the class are by default inline.
These fall inline in the final arrangement during execution of the program.

Member Functions defined outside the class are not inline by default. They have to be made
--------------------------------------------- inline by using inline keyword at the time of
declaration of these functions.

All member function containing /using any control structure are not inline by default.
*/
using namespace std;
#include <iostream>
#include <stdio.h>
class Student
{
    int rollno;
    char name[20];
    char address[30];

public:
    inline void getStudent();
    inline void putStudent();
};
void Student::getStudent() // function defned outside the class
{
    cout << "Enter rollno name address";
    cin >> rollno;
    fflush(stdin);
    gets(name);
    gets(address);
}
void Student::putStudent()
{
    cout << "Rollno =" << rollno << endl;
    cout << "Name =" << name << endl;
    cout << "Address =" << address << endl;
}
main()
{
    Student st;
    st.getStudent();
    st.putStudent();
}

/* Member Functions defined inside the class but using control structures are not inline and can
be made inline using inline keyword

Inline functions execute faster compared to other
*/

/*
            Compilation				Execution
Source Code --------> Object Code  --------> Output
           Compile time		       Run time


Polymorphism is the ability of a class member to act in more than one ways.
It has two types
----------------
1. Compile Time Polymorphism : If the multiple nature of a class member is encountered
----------------------------- during the compile time of program execution than it is
called CTP.
It is implemented in three ways
a. Function Overloading
b. Constructor Overloading
c. Operator Overloading

2. Run Time Polymorphism : If the multiple nature of a class member is encountered
----------------------------- during the run time of program execution than it is
called RTP.
It is implemented in two ways
a. Virtual Function
b. Virtual Class


Function Overloading - If a class contain more than one function with same name but
---------------------- different no of arguements or different order of arguements than
we call that function as Overloaded Function.

I Different no of arguements
*/
using namespace std;
#include <iostream>
class Sample
{
public:
    int add(int a1, int b1)
    {
        return a1 + b1;
    }
    int add(int a1, int b1, int c1)
    {
        return a1 + b1 + c1;
    }
};
main()
{
    Sample s1;
    cout << s1.add(12, 23) << endl;
    cout << s1.add(23, 34, 45) << endl;
}

/*Function Overloading - If a class contain more than one function with same name but
---------------------- different no of arguements or different order of arguements than
we call that function as Overloaded Function.

II Differenet order of arguements
*/
using namespace std;
#include <iostream>
class Sample
{
public:
    float add(int a1, float b1)
    {
        return a1 + b1;
    }
    float add(float a1, int b1)
    {
        return a1 + b1;
    }

    //	This leads to ambiguos function call
    //  different type of parameters is not function overloading
    /*float add(float a1, float b1)
    {
        return a1+b1;
    }
    int add(int a1,int b1)
    {
        return a1+b1;
    }*/
};
main()
{
    Sample s1;
    cout << s1.add(2, 3.5) << endl;
    cout << s1.add(3.3, 4) << endl;
    // cout<<s1.add(3.4,4.5)<<endl;
    // cout<<s1.add(2,3);
}

// cons overloading is same is fun overloading and any class with two constructors is an example

/* Operator Overloading : This is a special mechanism in which we define new meanings of
operators such that these can be now used with objects. This is done by using a reserved
word operator for defining an operator function with symbol as the function name. The
basic meaning and usage of operator does not change


2 Types
i. Unary Operator Overloading
ii. Binary Operator Overloading


Q Overload ++ operator to increment a value in an object
*/
using namespace std;
#include <iostream>
class Counter
{
    int c;

public:
    Counter()
    {
        c = 6;
    }
    void show()
    {
        cout << c << endl;
    }
    void operator++() // for prefix call of operator
    {
        c++;
    }
    void operator++(int) // for postfix call of operator
    {
        c++;
    }
};
main()
{
    Counter obj;
    obj.show();
    ++obj; // obj.++();
    // obj.operator++();	this is ok
    obj.show();
    obj++;
    // obj.operator++(int);	this is ok
    obj.show();
}

/* Overload Unary Minus to negate a value */
using namespace std;
#include <iostream>
class Negate
{
    int n;

public:
    void getdata()
    {
        cout << "Enter n";
        cin >> n;
    }
    void putdata()
    {
        cout << n << endl;
    }
    void operator-()
    {
        n = -n;
    }
};
main()
{
    Negate obj;
    obj.getdata();
    -obj; // obj.-();
    obj.putdata();
    -obj;
    obj.putdata();
}

/* Binary Operator Overloading

Overload + operator to add two distances
feet inches
6'	7"
3'	9"
----------
10' 4"

7+9=16%12=4"
7+9=16/12=1'
6+3+1=10' */
using namespace std;
#include <iostream>
class Distance
{
    int feet, inches;

public:
    void getDistance()
    {
        cout << "Enter feet and inches";
        cin >> feet >> inches;
    }
    void putDistance()
    {
        cout << feet << " " << inches << endl;
    }
    Distance operator+(Distance d2) // function containing object as arguement
    {                               // and object as return type
        Distance d3;
        d3.feet = feet + d2.feet + (inches + d2.inches) / 12;
        d3.inches = (inches + d2.inches) % 12;
        return d3;
    }
};
main()
{
    Distance d1, d2, d3;
    d1.getDistance();
    d2.getDistance();
    d3 = d1 + d2; // d3=d1.+(d2);
    d3.putDistance();
}

/* Binary Operator Overloading

Overload > operator to compare two distances
if feet1 > feet2	then d1
if feet1 = feet2
    if inches1>inches2 then d1
else
d2

 */
using namespace std;
#include <iostream>
// enum boolean {t, f};
class Distance
{
    int feet, inches;

public:
    void getDistance()
    {
        cout << "Enter feet and inches";
        cin >> feet >> inches;
    }
    void putDistance()
    {
        cout << feet << " " << inches << endl;
    }
    bool operator>(Distance d2) // function containing object as arguement
    {                           // and enum as return type
        if (feet > d2.feet)
            return true;
        else if (feet == d2.feet)
            if (inches > d2.inches)
                return true;
            else
                return false;
        else
            return false;
    }
};
main()
{
    Distance d1, d2;
    d1.getDistance();
    d2.getDistance();
    if (d1 > d2 == true) // if(d1.>(d2)==true)
        d1.putDistance();
    else
        d2.putDistance();
}

/*
            Compilation				Execution
Source Code --------> Object Code  --------> Output
           Compile time		       Run time


Polymorphism is the ability of a class member to act in more than one ways.
It has two types
----------------
1. Compile Time Polymorphism : If the multiple nature of a class member is encountered
----------------------------- during the compile time of program execution than it is
called CTP.
It is implemented in three ways
a. Function Overloading
b. Constructor Overloading
c. Operator Overloading

2. Run Time Polymorphism : If the multiple nature of a class member is encountered
----------------------------- during the run time of program execution than it is
called RTP.
It is implemented in two ways
a. Virtual Function
b. Virtual Class


Function Overloading - If a class contain more than one function with same name but
---------------------- different no of arguements or different order of arguements than
we call that function as Overloaded Function.

I Different no of arguements
*/
using namespace std;
#include <iostream>
class Sample
{
public:
    int add(int a1, int b1)
    {
        return a1 + b1;
    }
    int add(int a1, int b1, int c1)
    {
        return a1 + b1 + c1;
    }
};
main()
{
    Sample s1;
    cout << s1.add(12, 23) << endl;
    cout << s1.add(23, 34, 45) << endl;
}

/*Function Overloading - If a class contain more than one function with same name but
---------------------- different no of arguements or different order of arguements than
we call that function as Overloaded Function.

II Differenet order of arguements
*/
using namespace std;
#include <iostream>
class Sample
{
public:
    float add(int a1, float b1)
    {
        return a1 + b1;
    }
    float add(float a1, int b1)
    {
        return a1 + b1;
    }

    //	This leads to ambiguos function call
    //  different type of parameters is not function overloading
    /*float add(float a1, float b1)
    {
        return a1+b1;
    }
    int add(int a1,int b1)
    {
        return a1+b1;
    }*/
};
main()
{
    Sample s1;
    cout << s1.add(2, 3.5) << endl;
    cout << s1.add(3.3, 4) << endl;
    // cout<<s1.add(3.4,4.5)<<endl;
    // cout<<s1.add(2,3);
}

// cons overloading is same is fun overloading and any class with two constructors is an example

/*
Constructor:
It is a public member function with same name as class
It donot have a return type
It may or maynot have any parameters
It is called automatically when an object is declared
It is used to initialise class data members
*/
using namespace std;
#include <iostream>
class Sample
{
    int a;
    float b;

public:
    Sample() // Default constructor
    {
        a = 6;
        b = 7.5;
    }
    void show()
    {
        cout << a << " " << b << endl; // endl is manipulator
    }
};
main()
{
    Sample s1, s2; // constructor gets called here
    s1.show();
    s2.show();
}

/*
Types
------
A by default constructor is always there even if we dont make one. It initialses data
members with a garbage value.

1. Default Constructor		It initialses data members with given values
2. Parameterised Constructor
3. Copy Constructor
4. Dynamic Constructor
*/

/* Destructor
is a public member function
that has same name as class preceded by a symbol tilde ~
It donot have a return type
It donot have any parameters
It is called automatically when an object is destroyed at the end of the program execution
It releases the memory occupied by object
*/
using namespace std;
#include <iostream>
class Sample
{
public:
    Sample() // C
    {
        cout << "Constructing" << endl;
    }
    ~Sample() // D
    {
        cout << "Destroying" << endl;
    }
    void show() // F
    {
        cout << "Showing" << endl;
    }
};
main()
{
    Sample s1, s2;
    s1.show();
}

// here size of object is 1 byte because there are no data members
// such classes are called empty classes and there object use 1 byte only