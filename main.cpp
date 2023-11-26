#include "GeometricCurves.h"
void print(GeometricCurves *A, double t);

int main() {
  // task 2
  vector<shared_ptr<GeometricCurves>> v1;
  vector<shared_ptr<GeometricCurves>> v2;
  srand(time(0));
  int size_v1 = 10;   // количество кривых
  int range = 100; // диапазон значений радиусов и шага спирали
  for (int i = 0; i < size_v1; i++) {
    int tmp = rand() % 3;
    if (tmp == 0) {
      shared_ptr<Circle> circle(new Circle);
      circle->SetRadius1(rand() % range + 1);
      v1.push_back(circle);
    } else if (tmp == 1) {
      shared_ptr<Ellipse> ellipse(new Ellipse);
      ellipse->SetRadius1(rand() % range + 1);
      ellipse->SetRadius2(rand() % range + 1);
      v1.push_back(ellipse);
    } else if (tmp == 2) {
      shared_ptr<Helix> helix(new Helix);
      helix->SetRadius1(rand() % range + 1);
      helix->SetStep(rand() % range + 1);
      v1.push_back(helix);
    }
  }
  // task 3
  for (int i = 0; i < v1.size(); i++) {
    // cout << typeid(*(v1[i].get())).name() << "\n"; // отобразить типы кривых
    // в первом списке
    print(v1[i].get(), M_PI_4);
    cout << "\n\n";
    // task 4
    if (typeid(*(v1[i].get())).name() == typeid(Circle).name()) {
      v2.push_back(v1[i]);
    }
  }
  // task 5
  sort(v2.begin(), v2.end(), LessByRadius);
  double sum = 0;
  int i = 0;
  cout << "radius of circle in a second container\n";
// task 6,8
#pragma omp parallel shared(v2, i) reduction(+ : sum) num_threads(12)
  {
#pragma omp for
    for (i = 0; i < v2.size(); i++) {
      cout << v2[i]->GetRadius1() << "\n";
      sum += v2[i]->GetRadius1();
    } // #pragma omp parallel
  }
  cout << "\nsum radius of all circle in a second container: " << sum << "\n";
  return 0;
}

void print(GeometricCurves *A, double t) {
  Point P = A->GetPoint(t);
  Derivative V = A->GetDerivative(t);
  cout << "point:\nx: " << P.x << "\ny: " << P.y << "\nz: " << P.z << "\n\n";
  cout << "derivative:\nx_direction: " << V.direction.x
       << "\ny_direction: " << V.direction.y
       << "\nz_direction: " << V.direction.z << "\n";
}
