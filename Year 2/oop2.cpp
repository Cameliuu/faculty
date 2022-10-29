#include<iostream>
#include<string>
class Mother{
	public:
		
		void display(){
			std::cout<<"Mother\n";
		}
};

class Daughter : public Mother
{
	public:
		void display(){
			std::cout<<"Daughter";
		}
};

int main(){
	Mother m;
	Daughter d;
	m.display();
	d.display();
}
