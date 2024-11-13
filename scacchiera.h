/**
 * @file scacchiera.h
 * @brief Definizione di tipi, costanti e funzioni per rappresentare
 *        e gestire la scacchiera del gioco.
 */

#ifndef SCACCHIERA_H
#define SCACCHIERA_H

#include <stdbool.h>

/**
 * @brief Dimensione della scacchiera.
 */
#define DIMENSIONE_SCACCHIERA 9

/**
 * @brief Contenuto di una cella della scacchiera.
 *
 * Contenuto di una cella della scacchiera, usato anche
 * per indicare uno dei due giocatori. Il giocatore
 * associato a CELLA_X Ã¨ quello che muove per primo.
 */
typedef enum {
    CELLA_VUOTA,
    CELLA_X,
    CELLA_O
} Cella;

/**
 * @brief Scacchiera del gioco.
 *
 * La scacchiera contiene un array di celle, e l'indicazione
 * del prossimo giocatore a cui tocca muovere se la partita
 * non Ã¨ terminata.
 *
 * @invariant
 * Ogni cella contiene un valore che puÃ² essere solo:
 * CELLA_VUOTA, CELLA_X, CELLA_O.
 * @invariant
 * Il numero di CELLA_X Ã¨ uguale al numero di CELLA_O, 
 * oppure al numero di CELLA_O + 1.
 * @invariant
 * Se il numero di CELLA_X Ã¨ uguale al numero di CELLA_O,
 * allora prossimo Ã¨ uguale a CELLA_X; altrimenti
 * prossimo Ã¨ uguale a CELLA_O.
 */
typedef struct {
    /// @brief Celle della scacchiera.
    ///
    /// Le celle della scacchiera, in ordine di riga
    /// a partire da quella in alto a sinistra.
    Cella cella[DIMENSIONE_SCACCHIERA];
    /// @brief Prossimo giocatore che deve muovere
    Cella prossimo;
} Scacchiera;

/**
 * @brief Inizializza la scacchiera.
 * @param[out] s La scacchiera
 * @post
 * La scacchiera Ã¨ vuota e il prossimo giocatore Ã¨ 'X'.
 */
void inizializza_scacchiera(Scacchiera *s);

/**
 * @brief Verifica se una mossa Ã¨ valida.
 * @param[in] s La scacchiera
 * @param[in] mossa La mossa da verificare, compresa tra 0 e 
 *                  DIMENSIONE_SCACCHIERA-1
 * @return true se la mossa Ã¨ valida
 * @pre
 * La partita non Ã¨ terminata (vedi partita_terminata()).
 */
bool mossa_valida(Scacchiera *s, int mossa);
/**
 * @brief Aggiorna la scacchiera effettuando una
 *        mossa.
 * @param[inout] s La scacchiera
 * @param[in] mossa La mossa da eseguire, compresa tra 0 e
 *                 DIMENSIONE_SCACCHIERA-1.
 * @pre
 * La partita non Ã¨ terminata (vedi partita_terminata()).
 * @pre
 * La mossa Ã¨ valida (vedi mossa_valida()).
 * @post
 * La cella indicata dalla mossa viene occupata dal
 * giocatore che sta muovendo.
 * @post
 * Il prossimo giocatore Ã¨ modificato (se era 'X' diventa 'O' e
 * viceversa).
 */
void aggiorna_scacchiera(Scacchiera *s, int mossa);

/**
 * @brief Verifica se la partita Ã¨ terminata.
 *
 * La partita si considera terminata se uno dei due giocatori ha
 * fatto tris (e in questo caso Ã¨ il vincitore), oppure se non ci
 * sono celle vuote (pareggio).
 * @param[in] s La scacchiera
 * @param[out] vincitore Se uno dei due giocatori ha vinto, riceve
 *          il valore corrispondente (CELLA_X o CELLA_O). In caso di
 *          pareggio, riceve CELLA_VUOTA. Se la partita non Ã¨ terminata
 *          il valore non Ã¨ specificato.
 * @return  true se la partita Ã¨ terminata, false altrimenti.
 */
bool partita_terminata(Scacchiera *s, Cella *vincitore);


#endif
