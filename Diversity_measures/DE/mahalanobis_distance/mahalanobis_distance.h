/**
 * @file mahalanobis_distance.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 25.04.2025
 */



#ifndef MAHALANOBIS_DISTANCE_HEADER
#define MAHALANOBIS_DISTANCE_HEADER


#include <cmath>
#include <vector>
#include <eigen3/Eigen/Dense>
#include<stdexcept>





template<typename Individual, typename Container>
/**
 * @brief Metoda pro vypocet Mahalanobisovi vzdálenosti
 *
 * @param[in] individualOne - Konteiner chromozomu, musí implementovat metodu size a operátor []
 * @param[in] individualTwo - Konteiner chromozomu, musí implementovat metodu size a operátor []
 * @param[in] population - Konteiner population, musí implementovat metodu size a operátor []
 *
 * @throws runtime error - pokud je populace příliš malá 
 * @return double hodnota Mahalanobisovi vzdálenosti
 */
double mahalanobis_distance( const Individual& individualOne, const Individual& individualTwo, const Container& population );

#endif
