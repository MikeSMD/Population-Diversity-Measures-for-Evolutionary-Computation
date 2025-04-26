/**
 * @file Ackley.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */
#ifndef DE_ACKLEY
#define DE_ACKLEY
#include <vector>
#include <cmath>
/**
	 * @brief funkce pro evaluaci jedince dle Ackleyho funkce
	 * @param[in] a - parametr ackleyho funkce
	 * @param[in] b - parametr ackleyho funkce
	 * @param[in] c - parametr ackleyho funkce
	 * @param[in] individual - evaluovaný jedinec
	 * @return hodnota jedince
	*/
double ackley_fitness_function( const double a, const double b, double const c, std::vector< double > individual );

#endif

