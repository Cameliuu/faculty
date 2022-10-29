#include<iostream>
#include<string>

class Monitor
{
	private:
		std::string _producator;
		unsigned int _diagonala,_pret;
	public:
		Monitor(std::string producator, unsigned int diagonala, unsigned int pret)
		{
			_producator = producator;
			_diagonala = diagonala;
			_pret = pret;
		}
}
