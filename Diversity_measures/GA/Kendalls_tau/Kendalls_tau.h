/**
 * @file Kendalls_tau.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef KENDALS_TAU_DISTANCE_HEADER
#define KENDALS_TAU_DISTANCE_HEADER

#include <algorithm>
#include <vector>
#include <stdexcept>

template<typename Chromosome>

/**
 * @brief Metoda pro výpočet Kendalls tau vzdálenosti mezi dvěma chromozomy
 *
 * @param chromosomeOne - konteiner prvního chromozomu, musí mít definovanou metodu size a operátor []
 * @param chromosomeTwo - konteiner druhého chromozomu, musí mít definovanou metodu size a operátor []
 *
 * @return double hodnota - Výsledek vzdáelenosti mezi chromosomeOne a chromosomeTwo
 *
 * @throws runtime_error - pokud mají chromozomy jiný počet genů
 */
double kendalls_tau( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo );

#endif
