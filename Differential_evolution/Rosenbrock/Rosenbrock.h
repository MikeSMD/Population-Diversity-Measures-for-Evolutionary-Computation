/**
 * @file Rosenbrock.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */
#ifndef DE_ROSENBROCK
#define DE_ROSENBROCK

#include <vector>
#include <cmath>
/**
 * @brief funkce pro evaluaci jedince dle rosenbrockovi funkce
 * @param[in] individual - evaluovaný jedinec
 * @return hodnota jedince
*/
double rosenbrock_fitness_function( std::vector< double > individual );
#endif
