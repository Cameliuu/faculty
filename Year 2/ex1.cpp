

#include<iostream>
#include<string.h>
using namespace std;
class Person{
	public:
		char nume[20];
		char prenume[20];
		unsigned short varsta;
		char adresa[50];
		char telefon[10];
		void GetInfo(Person);
		void ShowInfo(Person);

};
void Person::GetInfo(Person person)
{
	cout << "Nume:";
        cin>> person.nume;
        cout << "Prenume:";
        cin>> person.prenume;
        cout << "Varsta:";
        cin >> person.varsta;
        cout<< "Adresa:";
        cin >> person.adresa;
        cout << "Telefon:";
	cin >> person.telefon;
}
void Person::ShowInfo(Person person){
        cout << "Nume:";
        cout<< person.nume<<endl;
        cout << "Prenume:";
        cout<< person.prenume<<endl;;
        cout << "Varsta:";
        cout<< person.varsta<<endl;;
        cout<< "Adresa:";
        cout<< person.adresa<<endl;
        cout << "Telefon:";
        cout<< person.telefon<<endl;

}

int main(){
	Person person;
	person.GetInfo(person);
	person.ShowInfo(person);
	return 0;
}
