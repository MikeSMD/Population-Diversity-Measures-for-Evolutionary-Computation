/**
 * @file kmeans.h
 * @author Michal Schmidt
 * @date Naposledy upraveno: 26.04.2025
 */
#ifndef KMEANS_DIVERSITY_HEADER
#define KMEANS_DIVERSITY_HEADER




#include <vector>


#include <functional>
#include <stdexcept>
#include <random>
#include <unordered_set>

template<typename Container, typename Chromosome>
/**
 * @brief funkce pro shlukování populace
 *
 * @param[in] population - Konteiner populace, musí implementovat metodu size a operátor []
 * @param[in] cluster_count - počet shluků do kterých se má populace rozdělit
 * @param[out] centroids - vektor, do něhož se uloží centroidy jednotlivých shluků. Původní data nebudou zachována.
 * @param[out] labels - vektor, do něhož se uloží index shluku ke konkrétnímu indexu chromozomu populace. Původní data nebudou zachována.
 * @param[in] distance_method - metoda porovnávající dva jedince z populace
 * @param[in] seed - hodnota ovlivňující náhodnou generaci čísel při incializaci centroidů jednotlivých shluků ( nemusí být zadán )
 *
 * @throws runtime_error - pokud bude nesprávně zadán cluster_count či dle zadané distance_method
 *
 * @return - samotná funkce nevrací žádnou hodnotu
 */
void k_means_clustering( const Container& population, const unsigned int cluster_count, std::vector< Chromosome >& centroids, std::vector< unsigned int >& labels, std::function< double( const Chromosome&, const Chromosome& ) > distance_method, const unsigned int seed = 12 );

template<typename Container, typename Chromosome>
/**
 * @brief funkce pro určení ideálního počtu shluků v populaci pomocí elbow metody
 *
 * @param[in] population - Konteiner populace, musí implementovat metodu size a operátor []
 * @param[in] cluster_count - počet shluků do kterých se má populace rozdělit
 * @param[in] distance_method - odkaz na metodu porovnávající dva jedince z populace
 * 
 * @throws runtime_error - pokud bude nesprávně zadán cluster_count či dle k_means_clustering
 *
 * @return - celočíselná hodnota korespondující s navrhovaným počtem shluků v poskytnuté populaci.
 */

int cluster_count_determiner( const Container& population, const unsigned int max_cluster_count, std::function< double( const Chromosome&, const Chromosome& ) > distance_method, const unsigned int seed = 12 );

template<typename Container, typename Chromosome>
/**
 * @brief funkce pro výpočet vnitřní diverzity jednotlivých shluků
 *
 * @param[in] population - Konteiner populace, musí implementovat metodu size a operátor []
 * @param[in] centroids - vektor s centroidy jednotlivých shluků
 * @param[in] labels - vektor určující jaký index shluku patří ke konkrétnímu indexu chromozomu populace
 * @param[in] distance_method - odkaz na metodu porovnávající dva jedince z populace
 *
 * @return[in] - vektor double hodnot označujících diverzitu jednotkivých shluků
 */
std::vector< double > centroid_diversity( const Container& population, const std::vector< Chromosome >& centroids,const std::vector< unsigned int >& labels, std::function< double( const Chromosome&, const Chromosome& ) > distance_method );

#endif
