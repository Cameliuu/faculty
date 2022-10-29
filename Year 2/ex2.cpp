#include<iostream>
#include<string>
class Masina{
	public:
		std::string prod,model;
		unsigned int an;
		class Sofer{
			public:
				std::string nume,cnp,adresa;
				unsigned short varsta;
		};
		Sofer sofer;
		void display(){
			std::cout<<std::endl<<"Detalii Masinan\n"prod<<std::endl<<model<<std::endl<<an<<std::endl<<"Detalii Sofer\n"<<std::endl<<sofer.nume<<std::endl<<sofer.cnp<<std::endl<<sofer.adresa<<std::endl<<sofer.varsta<<std::endl};
};
int main(){

	return 0;
}
