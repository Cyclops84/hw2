#include <cmath>
#include <cstdlib>
#include <iostream>
// using namespace std;
int main(int argc, char *argv[])
{
  const double pi_4 = 0.25 * 3.141592653589793;
  double h = 0.0;
  
  // get h from command line
if (argc == 2) //sanity check
{
  std::cout << "Hello" << std::endl;
  h = std::atof(argv[1]);
  double f = ((sin(pi_4 + h)-sin(pi_4))/h);//forward
  double c = ((sin(pi_4 + h)-sin(pi_4-h))/(2*h)); //central
  double der = cos(pi_4); //derivative
  double error_f = 100*((f - der)/der);//forward error
  double error_c = 100*((c - der)/der);//central error
  //print outs for the calculations above
  std::cout << "The forward finite difference is:" << f << "\n";
  std::cout << "The central finite difference is:" << c << "\n";
  std::cout << "The actual derivative is:" << der << "\n";
  std::cout << "The error in the forward finite is:" << error_f << "%\n";
  std::cout << "The error in the central finite is:" << error_c << "%\n";
}

  return 0;
}
