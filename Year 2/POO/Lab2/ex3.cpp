#include<iostream>
#include<string>
#include"profesor.h"

int main()
{
	Profesor p1;
	Profesor p2("Cornel","IGO","Sofer",3);
	p1.Display();
	p2.Display();
	p1.~Profesor();
	p2.~Profesor();
}
