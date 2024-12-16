#ifndef MPD_HEADER
#define MPD_HEADER

#include <iostream>
#include <functional>

template<typename Container, typename Chromosome, typename ReturnType>

/**
 * @brief Metoda pro výpočet průměrné vzdálenosti všech párů v populaci na základě poskytnuté funkce
 *
 * @param population - Kontejner chromozomů patřících do jedné generace - musí obsahovat metody begin() a end().
 * 
 * @param distance_method - Metoda pro výpočet vzdálenosti mezi dvěma chromozomy (např. Levenshteinova / Hammingova vzdálenost).
 * 
 * @return double hodnota celkové průměrné vzdálenosti v rámci jedné generace
 */
    double mean_pairwise_distance(const Container& population, std::function< ReturnType( const Chromosome&, const Chromosome& ) > distance_method);

#endif
