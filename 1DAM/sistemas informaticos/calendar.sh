#!/bin/bash
if [ $# == 3]
then 
	echo "correcto"

	ndias=(31 28 31 30 31 30 31 31 30 31 30 31)
	dia=$1;
	mes=$2;
	ano=$3;

	if[[ "$1" =~ ^[0-9]+$]] && [["$2" =~ ^[0-9]+$]] && [["$3" =~ ^[0-9] +$]];
	if (($3 % 4 == 0)); then
		ndias[1]=29
	fi
	if $(test $1 -ge 1) && $(test $1 -le $(ndias[(($2 -1))])); then
		echo "fecha valida"
	else
		echo "pon un dia valido"
	fi
	else 
		echo "debe poner numeros enteros"
	fi
else 
	echo "USO ./ejercicio DD MM YYYY"
fi