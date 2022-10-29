#!/bin/sh


function foo {
	if($1 == *.gz)
	then
		zcat /var/log/$1 | grep $2
	else
		cat /var/log/$1 | grep $2
	fi
}
while true
do
echo "Introuceti o optiune!"
echo "1. Ieșire

2. Afișare: ID-ul procesului initiat la executarea scriptului, tipul sistemului de operare, numarul de secunde de cand s-a executat scriptul și calea curentă (vezi variabile de sistem)

3. Afișarea numarului săptămânii din an, si a zilei săptămânii în care va fi Crăciunul în acest an (vezi date)

4. Afișarea primelor 2 shell-urilor instalate în sistem (vezi /etc/shells)

5. Afișarea pentru toți utilizatorii din sistem a numelui de login, a user ID-ului, a numelui complet si a directorului de home (vezi /etc/passwd)

6. Afişare ultimele linii începând cu linia 9 din fișierul /etc/protocols folosind comanda tail.
i
7. Afișare tip procesor şi mărimea cache-ului (vezi /proc/cpuinfo)

8. Scrieți comanda ls care afișează toate numele de directoare din directorul /proc care nu reprezintă imaginea unui proces pe disc (numele directorului care reprezintă imaginea unui proces pe disc este format doar din cifre)

9. Sa se afiseze toate fisierele de log. Sa se creeze o funcție care primește ca si parametrii cititi de la tastatura un nume de fișier de log (ori curent ori arhivat) și un text, si care va căuta si afișa liniile care conțin textul primit ca si parametru."
read OPT
case $OPT in
	1)
		exit;;
	2) 
		echo "ID-ul procesului este $$, Tipul sistemului de operare este $OSTYPE, programul ruleaza de $SECONDS secunde in directorul ${PWD}"
		;;
	3)	
		echo -e "\nCraciunuil va fi in : "
		date -d "2022-12-25" "+%Y-%m-%d"
		echo -e "\n"
		;;
	4)
		echo -e "Primele doua shell-uri sunt\n $(head -n 2 /etc/shells)"

		;;
	5)
		echo -e "\n"
		awk -F : '{print $1,$3,$5,$6}' /etc/passwd;
		echo -e "\n"
		;;
	6)
		nr=$(wc -l < /etc/protocols)
		echo -e "\n"
		tail -n $((nr-9)) /etc/protocols 
		;;
	7)
		echo -e "\n Informatii Procesor\n$(cat /proc/cpuinfo | grep "model name" -m 1 )\n $(cat /proc/cpuinfo | grep "cache" -m 1)"
		;;
	8)
		echo -e "\n Directoarele din /proc care nu reprezita imaginea unui proces pe disc sunt: \n"
		ls -l /proc | awk ' $9~/^[a-z]/ && $0~/^d/{print $9}' 
		echo -e "\n"
		;;
	9)
		ehco -e "\n"
		ls -al /var/log
		echo -e "\n Introduceti numele fisierului:"
		read F
		echo -e "\n Introduceti testul de cautat:"
		read T
		foo $F $T
		;;
esac	
done
