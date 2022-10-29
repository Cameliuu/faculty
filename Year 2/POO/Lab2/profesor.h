
#include<string>

class Profesor
{
	private:
		std::string m_nume,m_dep,m_grad;
		unsigned short m_vechime;
	public:
		Profesor()
		{
			m_nume="Necunoscut";
			m_dep="Necunoscut";
			m_grad="Necunoscut";
			m_vechime = 0;	
		}
		Profesor(std::string nume, std::string dep, std::string grad, unsigned short vechime)
		{
			m_nume=nume;
			m_dep=dep;
			m_grad=grad;
			m_vechime=vechime;
		}
		~Profesor()
		{
			std::cout<<std::endl<<"Destructorul a fost apelat!Memorie eliberata!";
		}
		void Display()
		{
			std::cout<<std::endl<<"Informatii profesor"<<std::endl<<"Nue: "<<m_nume<<std::endl<<"Departament: "<<m_dep<<std::endl<<"Grad: "<<m_grad<<std::endl<<"Vechime: "<<m_vechime<<std::endl;
		}
};
