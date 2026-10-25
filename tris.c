
/*
  Autore: Stortiero Danny
  Titolo: Gioco del Tris
*/

#include <stdio.h>

void colonne(int *n1, int *n2);
void spazio(int n1, int n2, int *spazio);
void tabellone(int *n, int riga, int *b, int lettera[]);
void risultato(int lettera[], int *n, int *b);
int menu_rivincita(void);


void tabellone(int *n, int riga, int *b, int lettera[])
{
    int i;

    if(*n == 1)        //se n == 1 allora si andra' a stampare x
        lettera[riga - 1] = 1;

    if(*n == 2)        //se n == 2 allora si andra' a stampare o
        lettera[riga - 1] = 2;


    printf("\nTabellone:");

    for(i = 0; i < 9; i++)
    {
        if(i % 3 == 0)
            printf("\n");

        if(lettera[i] == 0)
            printf("\t-");
        else
        {
            if(lettera[i] == 1)
                printf("\tx");

            if(lettera[i] == 2)
                printf("\to");
        }
    }
}


void colonne(int *n1, int *n2)    //chiede di inserire le coordinate
{
    do
    {
        printf("\nInserisci il numero della riga(1-3): ");
        scanf("%d", n1);

        if(*n1 < 1 || *n1 > 3)
            printf("\nPuoi inserire solo numeri tra 1 e 3!");

    } while(*n1 < 1 || *n1 > 3);


    do
    {
        printf("\nInserisci il numero della colonna(1-3): ");
        scanf("%d", n2);

        if(*n2 < 1 || *n2 > 3)
            printf("\nPuoi inserire solo numeri tra 1 e 3!");

    } while(*n2 < 1 || *n2 > 3);
}


void spazio(int n1, int n2, int *riga)    //analizza le coordinate e salva il punto giusto
{
    if(n1 == 1)
        *riga = n2;

    if(n1 == 2)
        *riga = n2 + 3;

    if(n1 == 3)
        *riga = n2 + 6;
}


// MODIFICATA: restituisce 1 per ricominciare, 2 per uscire
int menu_rivincita(void)
{
    int scelta = 0;

    printf("\nVuoi fare un'altra partita?\nRestart = 1\tExit = 2");

    do
    {
        printf("\ninserisci scelta:");
        scanf("%d", &scelta);

        if(scelta < 1 || scelta > 2)
        {
            printf("ERRORE! INPUT ERRATO!");
        }

    } while(scelta < 1 || scelta > 2);

    if(scelta == 2)
    {
        printf("Gioco finito");
    }

    return scelta;
}


int main()
{
    int i, c1, c2, riga = 0, n = 0, a = 0, lettera[9], b = 0;
    int scelta_rivincita;

    // CICLO AGGIUNTO PER GESTIRE IL RIAVVIO
    do
    {
        riga = 0;
        n = 0;
        a = 0;
        b = 0;

        for(i = 0; i < 9; i++)
        {
            lettera[i] = 0;    //riempie tutto l'array di zeri
        }

        printf("\nBenvenuto nel gioco del tris!");

        tabellone(&n, riga, &b, lettera);

        while(1) //ciclo infinito fino a quando il gioco non finisce
        {
            printf("\nTurno di x");

            do    //controlla se la casella e' gia' occupata
            {
                colonne(&c1, &c2);

                printf("\nRiga: %d", c1);
                printf("\nColonna: %d", c2);

                spazio(c1, c2, &riga);

                if(lettera[riga - 1] != 0)
                    printf("\nLa casella e' gia' occupata!");

            } while(lettera[riga - 1] != 0);

            n = 1;

            tabellone(&n, riga, &b, lettera);

            risultato(lettera, &n, &b);

            if(b > 0)
                break;

            //inizio controllo delle caselle piene
            a = 0;

            for(i = 0; i < 9; i++)
            {
                if(lettera[i] != 0)
                    a++;
            }

            if(a == 9)
            {
                printf("\nLe caselle sono piene!\nGioco finito in pareggio.");
                break;
            }
            //fine controllo delle caselle piene


            printf("\nTurno di O");

            do    //controlla se la casella e' gia' occupata
            {
                colonne(&c1, &c2);

                printf("\nColonna verticale: %d", c1);
                printf("\nColonna orizzontale: %d", c2);

                spazio(c1, c2, &riga);

                if(lettera[riga - 1] != 0)
                    printf("\nLa casella e' gia' occupata!");

            } while(lettera[riga - 1] != 0);

            n = 2;

            tabellone(&n, riga, &b, lettera);

            risultato(lettera, &n, &b);

            if(b > 0)
                break;

            //inizio controllo delle caselle piene
            a = 0;

            for(i = 0; i < 9; i++)
            {
                if(lettera[i] != 0)
                    a++;
            }

            if(a == 9)
            {
                printf("\nLe caselle sono piene!\nGioco finito in pareggio.");
                break;
            }
            //fine controllo delle caselle piene
        }

        // MENU RIVINCITA DOPO LA FINE DELLA PARTITA
        scelta_rivincita = menu_rivincita();

    } while(scelta_rivincita == 1);

    return 0;
}


void risultato(int lettera[], int *n, int *b)
{
    int i;

    for(i = 0; i < 9; i++)
    {

        //inizio controllo delle righe orizzontali
        if(i == 0 || i == 3 || i == 6)
        {
            if(lettera[i] == *n && lettera[i + 1] == *n && lettera[i + 2] == *n)
            {
                if(*n == 1)
                    printf("\nvittoria di X!");
                else
                    printf("\nvittoria di O!");

                *b = 1;
            }
        }
        //fine controllo delle righe orizzontali


        //inizio controllo delle righe verticali
        if(i == 0 || i == 1 || i == 2)
        {
            if(lettera[i] == *n && lettera[i + 3] == *n && lettera[i + 6] == *n)
            {
                if(*n == 1)
                    printf("\nvittoria di X!");
                else
                    printf("\nvittoria di O!");

                *b = 1;
            }
        }
        //fine controllo delle righe verticali


        //inizio controllo delle righe diagonali
        if(i == 0)    //controllo diagonale 1
        {
            if(lettera[i] == *n && lettera[4] == *n && lettera[i + 8] == *n)
            {
                if(*n == 1)
                    printf("\nvittoria di X!");
                else
                    printf("\nvittoria di O!");

                *b = 1;
            }
        }

        if(i == 2)    //controllo diagonale 2
        {
            if(lettera[i] == *n && lettera[4] == *n && lettera[i + 4] == *n)
            {
                if(*n == 1)
                    printf("\nvittoria di X!");
                else
                    printf("\nvittoria di O!");

                *b = 1;
            }
        }
    }
    //fine controllo delle righe diagonali
}
