# -*- coding: utf-8 -*-

import numpy as np
#import pylab as plt

# Parameters of the problem
n_iter = 1000000
n_rejected = 0

rho = 1.
mu = 1.

arrival_time = 0.
departure_time = 0.

#print("arrival_time = ", arrival_time)
#print("departure_time = ", departure_time)

for _ in range(n_iter):
    rejected = True
    while rejected:
        arrival_time += np.random.exponential(1./rho)
        #print("arrival_time = ", arrival_time)
        if departure_time <= arrival_time:
            rejected = False
        else:
            n_rejected += 1
    departure_time = arrival_time + np.random.exponential(1./mu)
    #print("departure_time = ", departure_time)

n_particles = n_iter + n_rejected
print("n_rejected = ", n_rejected)
print("n_particles = ", n_particles)
print("ratio = ", n_rejected/n_particles)