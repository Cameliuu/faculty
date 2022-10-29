#include<iostream>
#include<string>
#include<monitor.h>

class LED : public Monitor
{
	private:
		std::string _ecran;
		unsigned short _iluminare,_boxe;
	public:
		LED(std:: string ecran, unsigned short iluminare, unsigned short boxe)
		{
			_ecran = ecran;
			_iluminare=iluminare;
			_boxe=boxe;
		}
}
