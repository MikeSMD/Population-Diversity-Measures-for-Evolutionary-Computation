/**
 * @file edit_distance.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef EDIT_DISTANCE_HEADER
#define EDIT_DISTANCE_HEADER

#include <iostream>
#include <vector>

template<typename Chromosome>

/**
 * @brief Metoda pro výpočet Levenshteinvoy vzdálenosti
 *
 * @param chromosomeOne - Konteiner odkazující na první chromozom, musí implementovat metodu size()
 * @param chromosomeTwo - Konteiner odkazující na druhý chromozom, musí implementovat metodu size()
 *
 * @return celé číslo výsledku vzdálenosti mezi chromozomy
 *
 */
unsigned int edit_distance( const Chromosome& chromosomeOne, const Chromosome& chromosomeTwo );

#endif


