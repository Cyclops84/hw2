#include <cmath>
#include <cstdlib>
#include <ctime>  // for trigger the seed of random number generator
#include <iostream>

static void genPointsOnUnitSphere(const int N, float *x, float *y, float *z);

int main(int argc, char *argv[]) {
  // parse input argc/argv
  if (argc == 2) {
  int min=0,max=0,arc=0;
  int N = std::atoi(argv[1]);
  // get the size of N

  //float *x = nullptr, *y = nullptr, *z = nullptr;
  float *x = new float(N);
  float *y = new float(N);
  float *z = new float(N);
  // allocate memory for x, y, z

  genPointsOnUnitSphere(N, x, y, z);

  int j = 0;
  for (; j < N; ++j) {
    arc= acos(x[0]*x[j]+y[0]*y[j]+z[0]*z[j]);
      if(max < arc){
        max = arc;
      }
      else if(min > arc){
        min = arc;
      }
  }
  std::cout << "The max arc length is: " << max << "\n";
  std::cout << "The min arc length is: " << min << "\n";
  // determine the extreme arc lengths
  delete [] x;
  delete [] y;
  delete [] z;
  // relax memory
  }
  return 0;
}

// black-box function to generate a collection of random points
void genPointsOnUnitSphere(const int N, float *x, float *y, float *z) {
  if (x == nullptr || y == nullptr || z == nullptr || N <= 0) {
    std::cerr << "invalid pointers or size, aborting...\n";
    std::exit(1);
  }
  std::srand(std::time(0));  // trigger the seed
  const int BD = 10000000, BD2 = 2 * BD;
  const float inv_bd = 1.0f / BD;  // not integer division
  for (int i = 0; i < N; ++i) {
    x[i] = (std::rand() % BD2 - BD) * inv_bd;
    y[i] = (std::rand() % BD2 - BD) * inv_bd;
    z[i] = (std::rand() % BD2 - BD) * inv_bd;
    const float len = std::sqrt(x[i] * x[i] + y[i] * y[i] + z[i] * z[i]);
    if (len > 1e-5f) {
      // project on to unit sphere
      x[i] /= len;
      y[i] /= len;
      z[i] /= len;
    } else {
      // too close to zero
      // directly set the point to be (1,0,0)
      x[i] = 1.0f;
      y[i] = z[i] = 0.0f;
    }
  }
}
