#include <iostream>
#include <string>

using namespace std;

class Invoice{

    private:
        std::string numero;
        std::string descricao;
        int quantidade;
        float preco;
    
    public:
        Invoice(){

        };

        // get methods;

        std::string getNum() const {
            return numero;
        };
        std::string getDescr() const {
            return descricao;
        }

        int getQuant() const {
            return quantidade;
        }

        float getPreco() const {
            return preco;
        }

        // set methods;

        void setNum(std::string num){
            numero = num;
        }

        void setDescr(std::string descr){
            descricao = descr;
        }

        void setQuant(int quant){
            if(quant<0) quantidade = 0;
            else quantidade = quant;
        }

        void setPreco(float preco_){
            if(preco_ < 0) preco = 0.0;
            else this->preco = preco_;
        }

        float getInvoiceAmount() const {
            return quantidade * preco;
        }
        // 100 - Teclado USB - 2 - 143.9 - 287.8
        void print() const {
            std::cout   << numero << " - " 
                        << descricao << " - " 
                        << quantidade << " - " 
                        << preco << " - " 
                        << getInvoiceAmount() << std::endl;
        }
    
};


void readInv(Invoice *i){
    std::string num;
    std::string descr;
    int quant;
    float preco;

    getline(cin, num);
    getline(cin, descr);

    cin >> quant;
    cin >> preco;
    cin.ignore();

    i->setNum(num);
    i->setDescr(descr);
    i->setQuant(quant);
    i->setPreco(preco);

}

int main(void){
    Invoice i1;
    Invoice i2;

    readInv(&i1);
    readInv(&i2);

    i1.print();
    i2.print();
    

    return 0;
}