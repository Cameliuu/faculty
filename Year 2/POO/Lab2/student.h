#include<iostream>
#include<string>

class Student
{
	private:
		std::string m_nume,m_rol,m_adresa,m_cod;
	public:
		Student()
		{
			std::cout<<std::endl<<"Nume: ";
			std::cin>>m_nume;
			std::cout<<"Rol:";
			std::cin>>m_rol;
			std::cout<<"Adresa";
			std::cin>>m_adresa;
			std::cout<<"Cod";
			std::cin>>m_cod;
		}
	void Display()
	{
		std::cout<<std::endl<<"Informatii Student"<<std::endl<<"Nume: "<<m_nume<<std::endl<<"Rol: "<<m_rol<<std::endl<<"Adresa: "<<m_adresa<<std::endl<<"Cod: "<<m_cod<<std::endl;
	}	
};	

