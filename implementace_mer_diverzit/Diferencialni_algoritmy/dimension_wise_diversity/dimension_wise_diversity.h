#ifndef DIMENSION_WISE_DIVERSITY_HEADER
#define DIMENSION_WISE_DIVERSITY_HEADER


#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

template<typename Container, typename Chromosome, typename Item>
/**
 * @brief Metoda pro výpočet diverzity v konkrétní dimenzi
 *
 * @param population- Konteiner populace, musí implementovat metodu size a operátor []
 * @param dimension - int - konkrétní dimenze, ve které je třeba počítat diverzitu
 *
 * @return - double hodnota diverzity v komkrétní dimenze
 * @note - předpokládá se, že všichni předaní jedinci mají stejný počet dimenzí
 * @version 1.0
 * @author SCH0414
 */
double dimension_wise_diversity(const Container& population, const unsigned int dimension);


template<typename Container, typename Chromosome, typename Item>

/**
 * @brief Metoda pro výpočet diverzity ve všech dimenzích
 *
 * @param population - Konteiner population, musí implementovat metodu size a operátor []
 *
 * @return - double hodnota diverzity ve všech dimenzích
 * @note - předpokládá se, že všichni předaní jedinci mají stejný počet dimenzí
 * @version 1.0
 * @author SCH0414
 */
double all_dimensions_wise_diversity(const Container& population);

#endif
