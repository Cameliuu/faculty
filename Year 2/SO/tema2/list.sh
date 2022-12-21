#!/bin/bash
function list
{
	echo -e "-----------------------------------Listez $1-------------------------------"
	ls -alR $1;
}

	list $1;
	list $2
