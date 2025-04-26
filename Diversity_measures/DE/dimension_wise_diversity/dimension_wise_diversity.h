/**
 * @file dimension_wise_diversity.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */

#ifndef DIMENSION_WISE_DIVERSITY_HEADER
#define DIMENSION_WISE_DIVERSITY_HEADER


#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename Container, typename Chromosome>
/**
 * @brief Metoda pro výpočet diverzity v konkrétní dimenzi
 *
 * @param[in] population- Kontejner population, musí implementovat metodu size a operátor []
 * @param[in] dimension - konkrétní dimenze, ve které je třeba počítat diverzitu
 *
 * @throw - runtime_error pokud je populace prádzná
 * @return - double hodnota diverzity v komkrétní dimenzi
 */
double dimension_wise_diversity( const Container& population, const std::size_t dimension);


template<typename Container, typename Chromosome>

/**
 * @brief Metoda pro výpočet diverzity ve všech dimenzích
 *
 * @param[in] population - Kontejner population, musí implementovat metodu size a operátor []
 *
 * @throw runtime_error pokud je populace prázdná
 *
 * @return - double hodnota diverzity ve všech dimenzích
 * 
 */
double all_dimensions_wise_diversity(const Container& population);

#endif
