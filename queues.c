#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


int main(void){

	/* Seed initialization for generating random numbers */
	const gsl_rng_type* T;
	gsl_rng* r;

	gsl_rng_env_setup();
	T = gsl_rng_mt19937;
	r = gsl_rng_alloc(T);
	gsl_rng_set(r, time(NULL));


	/* Simulation parameters */
	int n_iter = 100000;     // Number of iteration
	int n_rejected = -n_iter; // Total number of rejected particles

	double lambda = 1.;  // Parameter for injected particles
	double mu = 1.;      // Time for service parameter


	/* Arrival time and departure time of the first particle */
	double arrival_time = gsl_ran_exponential(r, 1./lambda);
	double departure_time = gsl_ran_exponential(r, 1./mu) + arrival_time;

	//printf("arrival_time = %g\n", arrival_time);
	//printf("departure_time = %g\n", departure_time);

	for(int i=0;i<n_iter;i++){
		do{
			n_rejected++;  // Because of this line we need to set n_rejected = -n_iter
			arrival_time = arrival_time + gsl_ran_exponential(r, 1./lambda);
			//printf("arrival_time = %g\n", arrival_time);
		}while(arrival_time < departure_time);

		departure_time = gsl_ran_exponential(r, 1./mu) + arrival_time;
		//printf("departure_time = %g\n", departure_time);
	}

	
	/* Results */
	int n_particles = n_iter + n_rejected +1;  // Total number of particles
	printf("n_rejected = %d\n", n_rejected);
	printf("n_particles = %d\n", n_particles);
	printf("ratio = %g\n", (double)n_rejected/(double)n_particles);

	gsl_rng_free(r);

	exit(EXIT_SUCCESS);
}
