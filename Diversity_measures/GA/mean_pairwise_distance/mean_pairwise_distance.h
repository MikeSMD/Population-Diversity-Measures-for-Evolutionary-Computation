/**
 * @file mean_pairwise_distance.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef MPD_HEADER
#define MPD_HEADER

#include <iostream>
#include <functional>
#include <vector>

template<typename Container, typename Chromosome>

/**
 * @brief Metoda pro výpočet průměrné vzdálenosti všech párů v populaci na základě poskytnuté funkce
 *
 * @param population - Kontejner chromozomů patřících do jedné generace - musí obsahovat metody begin() a end().
 * 
 * @param distance_method - Metoda pro výpočet vzdálenosti mezi dvěma chromozomy (např. Levenshteinova / Hammingova vzdálenost).
 * @throw runtime_error - pokud je populace malá či dle distance_method
 * 
 * @return double hodnota celkové průměrné vzdálenosti v rámci jedné generace
 */
    double mean_pairwise_distance(const Container& population, std::function< double( const Chromosome&, const Chromosome& ) > distance_method);

#endif
