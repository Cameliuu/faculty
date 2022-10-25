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
		ls -l /proc | awk ' $9~/^[a-z]/ && $0~/^d/{print $0}' 
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
