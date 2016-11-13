# numerical_project_MSA

On unix environment, compile the file queues.c using the command :
  gcc -Wall -L/usr/local/include -o name_of_exec queues.c -lgsl -lgslcblas -lm
if the gsl library has been installed in /usr/local/include. Otherwise write the path where it has been installed.
If the gsl library is not installed, use :
  sudo apt-get install libgsl0ldbl
in a terminal.
