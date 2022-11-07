#include <iostream>
#include "calc.h"
#include "polynomial.h"

int main()
{
    //test for int
Calculator<int> c1(1,1,'+');
std::cout<<c1.exec()<<'\n';
Calculator<int> c2(1,1,'-');
std::cout<<c2.exec()<<'\n';
Calculator<int> c3(1,1,'*');
std::cout<<c3.exec()<<'\n';
Calculator<int> c4(1,1,'/');
std::cout<<c4.exec()<<'\n';
//test for double
Calculator<double> c5(1.5,1.2,'+');
std::cout<<c5.exec()<<'\n';
Calculator<double> c6(1.5,1.2,'-');
std::cout<<c6.exec()<<'\n';
Calculator<double> c7(1.5,1.2,'*');
std::cout<<c7.exec()<<'\n';
Calculator<double> c8(1.5,1.2,'/');
std::cout<<c8.exec()<<'\n';

int a[]={1,2,3,2,1,5};
int b[]={1,1,3,4};
Polynomial<int> p1(5,a);
std::cout<<p1<<'\n';

Polynomial<int> p2(3,b);
std::cout<<p2<<'\n';

Polynomial<int> p3=p1+p2;
std::cout<<p3<<'\n';

std::cout<<(-p3)<<'\n';

Polynomial<int> p4=p3-p2;
std::cout<<p4<<'\n';

Polynomial<int> p5=p3*p2;
std::cout<<p5<<'\n';

Calculator<Polynomial<int>> c9(p1,p2,'+');
std::cout<<c9.exec()<<'\n';
Calculator<Polynomial<int>> c10(p1,p2,'-');
std::cout<<c10.exec()<<'\n';
Calculator<Polynomial<int>> c11(p1,p2,'*');
std::cout<<c11.exec()<<'\n';


return 0;
}