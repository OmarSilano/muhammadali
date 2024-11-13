/**
 * @file strategia.h
 * @brief Funzioni per la strategia di gioco del computer.
 */
#ifndef STRATEGIA_H
#define STRATEGIA_H

#include "scacchiera.h"

/**
 * @brief Sceglie la mossa del computer.
 * @param[in] s La scacchiera.
 * @return La mossa del computer, tra 0 e DIMENSIONE_SCACCHIERA-1.
 *         La mossa scelta Ã¨ valida (vedi mossa_valida()).
 * @pre
 * La partita non Ã¨ terminata (vedi partita_terminata()).
 */
int calcola_mossa_computer(Scacchiera *s);

#endif