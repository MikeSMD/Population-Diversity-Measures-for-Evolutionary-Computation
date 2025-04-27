#include "../Random_generator.h"

std::vector< bool > generate_chromosome( int genes_count );

void mutation_gene( std::vector< bool >& chromosome, int gene_index );

// formule - {1, -2, 3}, {2,3,-1}, uvnitr je disjunkce, venku konjunkce, - je negace, cislo je parametr - index -  3SAT PROBLEM
double fitness_evaluator( std::vector< std::vector< int > > formula,  std::vector< bool >& chromosome );

bool end_criterium( const std::vector< std::pair < std::vector< bool >, double > >& population, bool resetStaticValues );

