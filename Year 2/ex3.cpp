#include<iostream>
#include<string>

class Masina{
	public:
		std::string prod,model;
		unsigned short an;
		class Sofer{
			public:
				std::string nume,cnp,adresa;
				unsigned short varsta;
		};
		Sofer sofer;
		void display(){
			std::cout<<std::endl<<"Detalii masina"<<std::endl<<prod<<std::endl<<model<<std::endl<<an<<std::endl<<"Detalii sofer"<<std::endl<<sofer.nume<<std::endl<<sofer.cnp<<std::endl<<sofer.adresa<<std::endl<<sofer.varsta<<std::endl;
		}};
	}
	

int main(){
	
	return 0;
}
