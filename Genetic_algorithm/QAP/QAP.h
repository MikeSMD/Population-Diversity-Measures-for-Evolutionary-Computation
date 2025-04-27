#include "../Random_generator.h"
#include <unordered_set>

std::vector< int > QAP_generate_chromosome( int genes_count );

void mutation_exchange_three( std::vector< int >& chromosome );

double QAP_fitness_evaluator( const std::vector< std::vector< int > >& flow, const std::vector< std::vector< int > >& distance, std::vector< int >& chromosome );

