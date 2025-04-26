#ifndef DE_MPD_HEADER
#define DE_MPD_HEADER

#include <functional>
#include <vector>
#include <stdexcept>
template<typename Container, typename Individual >

/**
 * @brief Metoda pro výpočet průměrné vzdálenosti všech párů v populaci na základě poskytnuté funkce
 *
 * @param population - Kontejner chromozomů patřících do jedné generace - musí obsahovat metody begin() a end().
 * 
 * @param distance_method - Metoda pro výpočet vzdálenosti mezi dvěma  jedinci
 *
 * @throw runtime_error - pokud je populace malá či dle distance_method
 * @return double hodnota celkové průměrné vzdálenosti v rámci jedné generace
 */

double mean_pairwise_distance(const Container& population, std::function< double( const Individual&, const Individual& ) > distance_method);

#endif
