#ifndef DATA_H
#define DATA_H
#include <iostream>

class Data
{
    public:
        Data(int d, int m, int a);
        std::string getDay();
        std::string getMonth();
        int getYear();
        void setX(int v, char x);

        void printData();
        void nextDay();
        int getDaysMonth(int m);
    
    private:
        int dia;
        int mes;
        int ano;
};

#endif