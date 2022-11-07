#include <iostream>

template <typename T>
class Polynomial
{
    public:
int degree;
T* coefficients;
Polynomial(): degree(0),coefficients(nullptr) {}
Polynomial(int degree):degree(degree)
{
    this->coefficients=new T[degree+1];
    for(int i=0;i<=degree;++i)
    {
        this->coefficients[i]=0;
    }
}
Polynomial(int degree,T* coefficients):degree(degree)
{
    this->coefficients=new T[degree+1];
    for(int i=0;i<=degree;++i)
    {
        this->coefficients[i]=coefficients[i];
    }
}

friend Polynomial<T> operator-(Polynomial p)
{
    Polynomial<T> p2(p.degree);
    for(int i=0;i<=p.degree;++i)
    {
        p2.coefficients[i]=-p.coefficients[i];
    }
    return p2;
}

friend Polynomial<T> operator+(Polynomial p1,Polynomial p2)
{
    int max_degree=p1.degree,min_degree=p1.degree;
    bool first_bigger=true;
    if(p2.degree>max_degree) {max_degree=p2.degree;first_bigger=false;}
    else min_degree=p2.degree;
    Polynomial<T> p3(max_degree);
    for(int i=0;i<=max_degree;++i)
    {
        while(i<=min_degree)
        {
            p3.coefficients[i]=p1.coefficients[i]+p2.coefficients[i];
            i++;
        }
        if(first_bigger)
        {
            p3.coefficients[i]=p1.coefficients[i];
        }
        else
        {
            p3.coefficients[i]=p2.coefficients[i];
        }
    }

    while(p3.degree>0 && p3.coefficients[p3.degree]==0)
    {
        --p3.degree;
    }
    return p3;
}

friend Polynomial<T> operator-(Polynomial p1,Polynomial p2)
{
    return p1+(-p2);
}

friend Polynomial<T> operator*(Polynomial p1,Polynomial p2)
{
    Polynomial<T> p3(p1.degree+p2.degree);
    for(int i=0;i<=p1.degree;++i)
    {
        for(int j=0;j<=p2.degree;++j)
        {
            p3.coefficients[i+j]+=p1.coefficients[i]*p2.coefficients[j];
        }
    }
    return p3;
}

friend Polynomial<T> operator*(T scalar,Polynomial p)
{
    Polynomial<T> p3(p.degree);
    for(int i=0;i<p.degree;++i)
    {
        p3.coefficients[i]=scalar*p.coefficients[i];
    }
    return p3;
}

friend Polynomial<T> operator/(Polynomial p1,Polynomial p2)
{
    Polynomial<T> p3(p1.degree-p2.degree);
    while(p1.degree!=0)
    {
        T times=p1.coefficients[p1.degree]/p2.coefficients[p2.degree];
        p3.coefficients[p1.degree-p2.degree]=times;
        Polynomial<T> pom(p1.degree-p2.degree);
        pom.coefficients[p1.degree-p2.degree]=times;
        p1=p1-pom*p2;
    }
    return p3;
}

friend std::ostream& operator<<(std::ostream& out,const Polynomial& p)
{
    for(int i=p.degree;i>0;--i)
    {
        if(p.coefficients[i]==0) continue;
        if(p.coefficients[i]==1) 
        {
            out<<"x^"<<i<<" + ";
            continue;
        }
        out<<p.coefficients[i]<<"x^"<<i<<" + ";
    }
    out<<p.coefficients[0]<<'\n';
    return out;
}
};