#!/bin/sh

#Controllo del numero di parametri
if test $# -ne 1
then
	echo ERRORE: numero parametri errato: richiesti 1, passati $#
	exit 1
fi

#Controllo sul primo parametro (nome assoluto)
case $1 in
/*)
	echo "DEBUG-OK nome assoluto";;
*)
	echo ERRORE: $1 non è nome assoluto
	exit 2;;
esac

#Controlli superati - path setting
PATH=`pwd`:$PATH
export PATH

#FASE A: conteggio dei livelli della gerarchia

#Invocazione ricorsiva per conteggio livelli
FCR.sh $1

#FASE B: Ricerca delle directory al livello scelto