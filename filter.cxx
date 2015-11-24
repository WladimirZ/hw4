#include <fstream>
#include <string>
#include <iostream>

using namespace std;

double* read(const int N, const string fname) {
  double* f = new double[N];
  ifstream in(fname.c_str());
  for (int i=0; i<N; i++)
    in >> f[i];
  in.close();
  return f;
}

void filter (double* const f, const int N) {
  double t_a = f[0];
  double t_b;
  const double t_0 = t_a;
  f[0] = (f[N-1]+f[0]+f[1])/3;
  for (int i=1; i<N-1; i++) {
    t_b = f[i];
    f[i] = (t_a+f[i]+f[i+1])/3;
    t_a = t_b;
  }
  f[N-1] = (t_a+f[N-1]+t_0)/3;
}

void write (const double* const f, const int N, const string gname) {
  ofstream out(gname.c_str());
  for (int i=0; i<N; i++)
    out << f[i] << endl;
  out.close();
}

int main() {
  const int N = 237;
  const string fname = "noisy.txt";
  const string gname = "filtered.txt";
  double* f = read(N, fname);
  filter(f,N);
  filter(f,N);
  filter(f,N);
  filter(f,N);
  filter(f,N);
  filter(f,N);
  filter(f,N);
  filter(f,N);
  filter(f,N);
  filter(f,N);
  write(f,N, gname);
  
  delete[] f;
  return 0;
}