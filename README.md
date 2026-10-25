# Tris – Gioco in C

Gioco del **Tris da console per due giocatori**, con inserimento delle mosse tramite coordinate e alternanza dei turni. Il programma verifica le combinazioni vincenti, impedisce di selezionare caselle già occupate, riconosce i pareggi e permette di iniziare una nuova partita.

## Funzionalità

- Partita tra due giocatori, **X** e **O**.
- Inserimento della posizione attraverso **riga e colonna** (da 1 a 3).
- Visualizzazione del tabellone aggiornato dopo ogni mossa.
- Controllo delle caselle già occupate.
- Rilevamento della vittoria sulle righe, sulle colonne e sulle diagonali.
- Rilevamento del pareggio quando tutte le caselle sono occupate.
- Scelta tra **rivincita** e uscita al termine della partita.

## Prova la demo

**[Avvia il Tris online](https://onlinegdb.com/0bEOXw_kw)**

## Esecuzione in locale

È necessario un compilatore C, ad esempio **GCC**.

```bash
gcc main.c -o tris
```

Su Linux/macOS:

```bash
./tris
```

Su Windows:

```powershell
.\tris.exe
```

## Struttura del progetto

```text
Tris-C/
├── main.c
└── README.md
```

## Dettagli tecnici

Il progetto utilizza **funzioni**, **array**, **puntatori**, **strutture condizionali** e **cicli** per gestire tabellone, mosse e andamento della partita.

## Origine del progetto

Progetto scolastico realizzato il **20 marzo 2024** e successivamente aggiornato nella gestione della rivincita.
