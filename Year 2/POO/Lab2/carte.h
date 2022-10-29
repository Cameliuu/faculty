#include<string>


class Carte
{
        private:
                std::string m_titlu,m_autor;
                unsigned int m_an;
        public:
        Carte(std::string titlu, std::string autor, unsigned int an)
        {
                m_titlu=titlu;
                m_autor=autor;
                m_an = an;
        }
        void Display()
        {
                std::cout<<std::endl<<"Informatii carte"<<std::endl<<"Titlu: "<<m_titlu<<std::endl<<"Autor: "<<m_autor<<std::endl<<"An: "<<m_an<<std::endl;
        }

};


