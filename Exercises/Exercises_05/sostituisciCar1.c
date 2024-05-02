#include <stdio.h> 	    // Per poter usare printf e altre funzioni di I/O
#include <stdlib.h>	    // Per poter usare la primitiva exit
#include <unistd.h>	    // Per poter usare le primitive
#include <sys/wait.h>	// Per poter usare la primitiva wait
#include <fcntl.h>	    // Per poter usare le costanti per la open (O_RDONLY, O_WRONLY e O_RDWR)
#include <string.h>	    // Utilizzo delle stringhe
#define PERM 0644       // Permessi di default in ottale

int main(int argc, char** argv){

    //Dichiarazione variabili
    int fd, nwrite;
    char c, change;

    //Controllo sul numero di parametri
    if(argc != 4){
        printf("Inserire 3 parametri. Parametri inseriti %d\n", argc-1);
        exit(1);
    }

    //Controllo sul primo parametro
    if((fd = open(argv[1], O_RDWR)) < 0){
        printf("Errore: %s non corrisponde al nome di un file\n", argv[1]);
        exit(2);
    }

    //Controllo sul secondo parametro
    if(argv[2][1] != 0){
        printf("Errore: %s non singolo carattere\n", argv[2]);
        exit(3);
    }
    char Cx = argv[2][0];

    //Controllo sul secondo parametro
    if(argv[3][1] != 0){
        printf("Errore: %s non singolo carattere\n", argv[3]);
        exit(4);
    }
    change = argv[3][0];

    //Stampa delle informazioni iniziali
    printf("Il programma eseguito si chiama %s\n", argv[0]);
    printf("Il numero di parametri inseriti: %d\n", argc-1);

    while(read(fd, &c, 1) != 0){
        if(c == Cx){
            //Sposto il file pointer indietro di una posizione
            lseek(fd, -1L, SEEK_CUR);
            //Inserisco il carattere spazio
            nwrite = write(fd, &change, 1);
            if(nwrite != 1){
                printf("Errore in write: nwrite = %d\n", nwrite);
                exit(4);
            }
        }
    }

    //Termine del programma senza errori
    exit(0);
}