#include "GeometricCurves.h"

namespace {
Point GetPointByR(double t, double radius_1, double radius_2) {
  Point result;
  result.x = radius_1 * cos(t);
  result.y = radius_2 * sin(t);
  result.z = 0;
  return result;
}
Derivative GetDerivativeByR(double t, double radius_1, double radius_2) {
  Derivative result;
  result.direction.x = radius_1 * (-sin(t));
  result.direction.y = radius_2 * cos(t);
  result.direction.z = 0;
  return result;
}
} // namespace

void GeometricCurves::SetRadius1(double radius) {
  if (radius > 0) {
    r_1 = radius;
  } else {
    throw std::runtime_error("radius1 must be greater than zero");
  }
}
void Ellipse::SetRadius2(double radius) {
  if (radius > 0) {
    r_2 = radius;
  } else {
    throw std::runtime_error("radius2 must be greater than zero");
  }
}
double GeometricCurves::GetRadius1() { return r_1; }

double Ellipse::GetRadius2() { return r_2; }
void Helix::SetStep(double StepImput) { step = StepImput; }
double Helix::GetStep() { return step; }

Point Circle::GetPoint(double t) {
  Point result = GetPointByR(t, r_1, r_1);
  return result;
}
Derivative Circle::GetDerivative(double t) {
  Derivative result = GetDerivativeByR(t, r_1, r_1);
  return result;
}
Point Ellipse::GetPoint(double t) {
  Point result = GetPointByR(t, r_1, r_2);
  return result;
}
Derivative Ellipse::GetDerivative(double t) {
  Derivative result = GetDerivativeByR(t, r_1, r_2);
  return result;
}
Point Helix::GetPoint(double t) {
  Point result = GetPointByR(t, r_1, r_1);
  result.z = (t * step) / (2 * M_PI);
  return result;
}
Derivative Helix::GetDerivative(double t) {
  Derivative result = GetDerivativeByR(t, r_1, r_1);
  result.direction.z = step / (2 * M_PI);
  return result;
}
bool LessByRadius(shared_ptr<GeometricCurves> A,
                  shared_ptr<GeometricCurves> B) {
  return A->GetRadius1() < B->GetRadius1();
}