#include "data3.h"
#include <iostream>
#include <string>

using namespace std;

Data::Data(int d, int m, int a){
    if(m>=1 && m<=12)
        setX(m, 'm');
    else 
    {
        cout << "Atributo mês Inválido" << endl;
        setX(1, 'm');
    }

    if(d>=1 && d<=getDaysMonth(m))
        setX(d, 'd');
    else
    {
        cout << "Atributo dia Inválido" << endl;
        setX(1, 'd');
    }
    
    setX(a, 'a');
}

void Data::setX(int v, char x)
{
    if(x=='d') dia = v;
    else if(x=='m') mes = v;
    else if(x='a') ano = v;
    
}

std::string Data::getDay()
{
    if(dia< 10)
        return "0" + to_string(dia);
    return to_string(dia);
}

std::string Data::getMonth()
{
    if(mes< 10)
        return "0" + to_string(mes);
    return to_string(mes);
}

int Data::getYear()
{
    return ano;
}
   
void Data::printData()
{
    cout << getDay() + "/" + getMonth() + "/" + to_string(getYear()) << endl;
}

int Data::getDaysMonth(int m)
{
    if(m==2){
        return 28;
    }
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
        return 31;
    }
    return 30;
}

void Data::nextDay(){
    dia++;
    if(dia > getDaysMonth(mes)){
        dia = 1;
        mes++;
        if(mes > 12){
            mes=1;
            ano++;
        }
    }
}
