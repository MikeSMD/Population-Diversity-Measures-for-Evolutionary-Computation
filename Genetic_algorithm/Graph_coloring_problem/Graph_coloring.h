#ifndef GCP_HEADER
#define GCP_HEADER

#include "../Random_generator.h"
#include <set>

std::vector< int > GCP_generate_chromosome( int genes_count, int max_colors );
void GCP_mutation_gene( std::vector< int >& chromosome, int gene_index, int max_colors ); // jine taktiky?
double GCP_fitness_evaluator( std::vector< std::vector< int > > graph,  std::vector< int >& chromosome );

//void GCP_advanced_mutation_gene( const std::vector< std::vector< int > > graph, std::vector< int >& chromosome, int gene_index, int max_colors );

#endif
