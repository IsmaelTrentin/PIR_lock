# Specifications

Realizzare su BasysMX3 il programma "Serratura automatica con riconoscimento PIR SR602" descritto di seguito. L'Hardware disponibile è la board BasysMX3, il sensore di prossimità Parallax PIR e un miniservo motore.

**Le funzionalità sono:**

- Attivazione
- Disattivazione
- Rilevamento e registrazione accessi
- Setup Password
- Visualizzazione e cancellazione LOG

All'accensione il sistema si trova nello stato "Disattivato" segnalato con il led RGB al colore rosso. La password di default di accesso è "0000". La pressione di un pulsante (per es. BTNC) fa inviare tramite UART al terminale il messaggio "Inserisci password: ". Se dal terminale non c'è reazione entro 5 s  il sistema ritorna allo stato precedente (attende il BTNC).

Se la password inserita è errata, manda un messaggio conforme alla situazione e ripropone "Inserisci password: ". Se viene inserita la password corretta, appare il seguente menu:

1. Attiva
1. Cambia password
1. Vedi Log
1. Cancella Log

Digitando uno dei numeri associati alle funzioni (per es. '1' per Attiva, '2' per Cambia password , ecc.) si entra nella funzione selezionata. Se per un certo intervallo di tempo (per es. 5 s) non viene eseguita alcuna scelta il sistema va in timeout e ritorna allo stato precedente.

**Scelta di 1. Attiva:**

- il led RGB passa allo stato "BLUE";
- viene avviata la funzione di apertura serratura con la lettura del sensore PIR.
    Se il valore letto dal sensore è '1' (rilevazione di movimento nel suo cono di misura), la serratura (simulata dal servomotore) deve aprirsi (per es. muove il cursore dalla posizione 90 gradi alla posizione -90gradi).
    L'accesso viene registrato in una array con:
    - numero progressivo e istante di accesso relativo a quello di attivazione (p.e. 1, 3 per il primo evento registrato dopo 3 secondi. 2, 8 per il secondo evento registrato dopo ulteriori 5 secondi, ecc.) e
    - dare un segnale acustico (2 secondi) sullo speaker di BasysMX3 (generato con PWM).

    Per tener traccia dell'istante in cui avviene l'evento di accesso, usare un timer.

- Con la registrazione attivata (continua a misurare!), in mancanza di attività da UART per 5 sec, il sistema ritorna in uno stato in cui chiederà ancora la password prima di qualsiasi altra azione.
- La pressione di un secondo pulsante (scegliere a piacere tra quelli disponibili) chiude nuovamente la serratura portando il servomotore alla posizione iniziale

Se il sistema è attivo, alla pressione del pulsante BTNC, dopo aver chiesto e verificato la password come sopra, si otterrà il seguente menu:

1. Disattiva
1. Cambia password
1. Vedi Log
1. Cancella Log

**Scelta di 1. Disattiva:**

- il led RGB diventa rosso;
- la lettura del PIR viene interrotta e il servomotore ritorna alla posizione di partenza (serratura chiusa).

**Scelta di 2. Cambia password:** solo se il sistema si trova nello stato "Disattivato", in sequenza su UART, vengono richieste le seguenti operazioni

- inserimento password
- inserimento nuova password
- conferma nuova password

**Scelta di 3. Vedi Log:** stampa su UART il log array 

**Scelta di 4. Cancella Log:** cancella il contenuto del log array

Periferiche principali

- UART - pin RF12 (UART4TX) e RF13 (UART4RX)
- OUTPUT COMPARE - OC1, pin RB14
- PMP (per LCD)
- TIMER (scegliere i timer necessari, per esempio T3 per PWM e T2 per funzioni di Delay)
- SPI (per memoria Flash)
- GPIO (per BTNC e led RGB e sensore PIR)

[Note utlili](https://www.icorsi.ch/mod/assign/view.php?id=1159837) da datasheet sensore PIR.

## Da consegnare:

- tutti i file sorgente (".c" e ".h")
- rapporto (max 2/3 pagine) con flowchart e descrizione del programma (immaginate di dover far capire ad un utente esterno il vostro lavoro).

