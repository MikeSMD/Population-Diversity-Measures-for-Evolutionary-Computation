#include "GA_Selection.h"

template < typename Chromosome >
GA_Selection< Chromosome >::GA_Selection ( ) { }

// explicitní instanciace
template class GA_Selection<std::vector<bool>>;

template class GA_Selection<std::vector<int>>;

