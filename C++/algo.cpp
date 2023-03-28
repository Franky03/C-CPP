#include <iostream>

class Produto {
	private:
	std::string name;
	int quant;
	double preco;
	public:
	
	Produto();
	Produto(std::string n, int q, double p);
	std::string getName();
	int getQuant();
	double getPreco();
	
	void setName(std::string n);
	void setQuant(int q);
	void setPreco(double p);
};

Produto::Produto() : Produto("", 0, 0.0)
{
	
}

Produto::Produto(std::string n, int q, double p){
	setName(n);
	setQuant(q);
	setPreco(p);
}


void Produto::setName(std::string n){
	name = n;
}

void Produto::setQuant(int q){
        quant = q;
}

void Produto::setPreco(double p){
        preco = p;
}

std::string  Produto::getName(){
        return name;
}

int Produto::getQuant(){
        return quant;
}

double Produto::getPreco(){
        return preco;
}

class ControleProduto {
        private:
			Produto *produtos[10];
			int idx;
        public:
			int getIdx();
			void increaseIdx(int i);
			ControleProduto();
			Produto **getProdutos();
			void efetuaVenda(std::string, int q);
			void cadastraProduto2(std::string n,int q, double p);
			void cadastraProduto1(Produto p);
			void excluiProduto(std::string n);
};

ControleProduto::ControleProduto()
{
	idx = 0;
}

int ControleProduto::getIdx(){
	return idx;
}

void ControleProduto::increaseIdx(int i = 1){
	idx+=i;
}

Produto **ControleProduto::getProdutos(){
	return this->produtos;
}

void ControleProduto::cadastraProduto2(std::string n,int q, double preco){
	Produto* p = new  Produto(n, q, preco);
	this -> cadastraProduto1(*p);
	delete p;
}	

void ControleProduto::cadastraProduto1(Produto p){
	bool existe = false;
	if(getIdx() < 10){
		for(auto i=0; i<getIdx(); i++){
			if(produtos[i]->getName() == p.getName()){
				int quant = produtos[i]->getQuant();
				produtos[i]->setQuant(quant + p.getQuant());
				if(produtos[i]->getPreco() != p.getPreco()){
					produtos[i]->setPreco(p.getPreco());
				}
			existe = true;
			break;
			}
		}

		if(!existe){
			produtos[getIdx()] = new Produto(p);
			increaseIdx();
		}
		
	}
	else {
		std::cerr << "No Space";
	}
}

void ControleProduto::efetuaVenda(std::string n, int q){
	bool compra = false;
	for(auto i = 0; i< getIdx(); i++){
		if(produtos[i]->getName() == n){
			if(produtos[i]->getQuant() >= q){
				produtos[i]->setQuant(produtos[i]->getQuant() - q);
				compra = true;
				break;
			} else {
				std::cerr << "Quantidade insuficiente" << std::endl;
			}
		}
	}

	if(!compra){
		std::cerr << "Produto não encontrado" << std::endl;
	}
}

void ControleProduto::excluiProduto(std::string n){
	int index = -1;
	
	for(int i = 0; i<getIdx(); i++){
		if(produtos[i]->getName() == n){
			index = i;
			break;
		}
	}

	if(index == -1){
		std::cerr << "Produto não encontrado\n";
	}
	else {
		delete produtos[index];
		for(int i = index + 1; i<getIdx(); i++){
			produtos[i-1] = produtos[i];
		}
		increaseIdx(-1);
	}
}



int main(void){
	ControleProduto cp = ControleProduto();
	cp.cadastraProduto2("Arroz", 10, 10.0);
	cp.cadastraProduto2("Feijão", 10, 10.0);
	cp.cadastraProduto2("Macarrão", 10, 10.0);

	cp.efetuaVenda("Arroz", 1);
	std::cout << cp.getProdutos()[0]->getQuant() << std::endl;
	cp.cadastraProduto2("Arroz", 15, 10.34);
	std::cout << cp.getProdutos()[0]->getQuant() << std::endl;
	
	return 0;
}	
