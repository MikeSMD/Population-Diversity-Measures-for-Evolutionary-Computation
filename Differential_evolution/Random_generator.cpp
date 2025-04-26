#include "Random_generator.h"

Random_generator::Random_generator()
{

    std::random_device rd;
    unsigned long seed_value = rd();
    this->generator.seed(seed_value);
}

Random_generator& Random_generator::get_instance()
{
    static Random_generator random_generator;
    return random_generator;
}
 
int Random_generator::generate_int( int minimum, int maximum )
{
   std::uniform_int_distribution< int > distribution( minimum, maximum );
    int q = distribution( this->generator );
    return q;
}

void Random_generator::change_seed( unsigned long new_seed )
{
	if ( new_seed == 0 )
	{
		std::random_device rd;
		unsigned long seed_value = rd();
		this->generator.seed(seed_value);	
	}
	else
    		this->generator.seed( new_seed );	
}

double Random_generator::generate_double ( double minimum, double maximum )
{
    std::uniform_real_distribution< double > distribution( minimum, maximum );
    double q = distribution( this->generator );
    return q;
}
