#ifndef POINCARE_COMPLEX_H
#define POINCARE_COMPLEX_H

#include <poincare/evaluation.h>

namespace Poincare {

template<typename T>
class Complex;

template<typename T>
class ComplexNode : public std::complex<T>, public EvaluationNode<T> {
public:
  // TreeNode
  size_t size() const override { return sizeof(ComplexNode<T>); }
#if TREE_LOG
  const char * description() const override { return "Evaluation complex";  }
#endif
  int numberOfChildren() const override { return 0; }

  void setComplex(std::complex<T> c);
  typename Poincare::EvaluationNode<T>::Type type() const override { return Poincare::EvaluationNode<T>::Type::Complex; }
  bool isUndefined() const override {
    return (std::isnan(this->real()) && std::isnan(this->imag()));
  }
  T toScalar() const override;
  Expression complexToExpression(Preferences::Preferences::ComplexFormat complexFormat) const override;
  std::complex<T> trace() const override { return *this; }
  std::complex<T> determinant() const override { return *this; }
  Evaluation<T> inverse() const override;
  Evaluation<T> transpose() const override { return Complex<T>(*this); }
};

template<typename T>
class Complex : public std::complex<T>, public Evaluation<T> {
public:
  Complex(T a, T b = 0.0) : Complex(std::complex<T>(a, b)) {}
  Complex(std::complex<T> c);
  static Complex<T> Undefined() {
    return Complex<T>(NAN, NAN);
  }
};


}

#endif