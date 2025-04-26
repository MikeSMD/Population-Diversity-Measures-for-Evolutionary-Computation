/**
 * @file shannon_entropy.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */
#include <vector>
#include <cmath>
#include <stdexcept>
#include <unordered_map>

template< typename Individual >

/**
	 * @brief metoda pro výpočet shanonovy entropie
	 * @param[in] population - populace
	 * @param[in] bounds - rozsahy dimenzí 
	 * @param[in]  m - počet binů
	 * @throws runtime_error - pokud bude populace příliš malá či nebude odpovídat počet dimenzí jedinců
	 * 
	 * @return hodnota shanonovy entropie
	 *
	*/
double shannon_entropy( const std::vector< Individual >& population, const std::vector < std::pair < double, double > >& bounds, const unsigned int m = 10) ;
