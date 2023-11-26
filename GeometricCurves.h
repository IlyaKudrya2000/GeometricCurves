#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <parallel/algorithm>
#include <vector>
using namespace std;
struct Point {
  double x, y, z;
};

struct Derivative {
  Point direction;
};

class GeometricCurves {
public:
  virtual Point GetPoint(double t) = 0;
  virtual ~GeometricCurves() = default;
  virtual Derivative GetDerivative(double t) = 0;
  void SetRadius1(double radius);
  double GetRadius1();

protected:
  double r_1;
};

class Circle : public GeometricCurves {
public:
  Point GetPoint(double t) override;
  Derivative GetDerivative(double t) override;
};

class Ellipse : public GeometricCurves {
public:
  Point GetPoint(double t) override;
  Derivative GetDerivative(double t) override;
  void SetRadius2(double radius);
  double GetRadius2();

protected:
  double r_2;
};

class Helix : public GeometricCurves {
public:
  Point GetPoint(double t) override;
  Derivative GetDerivative(double t) override;
  void SetStep(double StepImput);
  double GetStep();

protected:
  double step;
};

bool LessByRadius(shared_ptr<GeometricCurves> A, shared_ptr<GeometricCurves> B);