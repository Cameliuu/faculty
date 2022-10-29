#include<iostream>
#include<string>
#include<monitor.h>
class LCD : public Monitor
{
	private:
		std::string _ecran,_conectori;
		int _timp;
	public:
		LCD(std::string ecran, std::string conectori, int timp)
		{
			_ecran = ecran;
			_conectori = conectori;
			_timp = timp;
		}	
}
