#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <utility>

class S21Matrix {
 private:
  int32_t rows_, cols_;
  double *matrix_;

 public:
  // Constructors and Destructor
  S21Matrix();
  S21Matrix(int32_t rows, int32_t cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix();

  // Operations
  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const;
  double Determinant() const;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;

  // Other
  int32_t get_rows() const noexcept;
  int32_t get_cols() const noexcept;
  void set_rows(const int32_t &new_rows);
  void set_cols(const int32_t &new_cols);

  double *operator[](int32_t row) const;
  double &operator()(int32_t row, int32_t col) const;

  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other) const;

  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other) const;

  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double &value);
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double &value) const;

  bool operator==(const S21Matrix &other) const noexcept;

  S21Matrix &operator=(S21Matrix &&other) noexcept;
  S21Matrix &operator=(const S21Matrix &other);

  friend S21Matrix operator*(const double &value, const S21Matrix &matrix);

  void get_cofactor(const S21Matrix &m, S21Matrix &tmp, int32_t skip_row,
                    int32_t skip_col, int32_t size);
  double det(const S21Matrix &m, int32_t size) const;
  S21Matrix adjoint(const S21Matrix &m) const;
};

#endif  // SRC_S21_MATRIX_H_