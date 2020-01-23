#ifndef LAB11_EMPLOYEES_H_INCLUDED
#define LAB11_EMPLOYEES_H_INCLUDED

#include <vector>
#include <string>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <bin_manip.hpp>


class Employee {
public:
  virtual int salary() const = 0;
  virtual void write_out(std::ostream &out) = 0;
  virtual void read_in(std::istream &out) = 0;
  virtual void write_out_file(std::ofstream &out) = 0;
  virtual void read_in_file(std::ifstream &out) = 0;
  virtual ~Employee();
protected:
  char*  _name = new char(100);
  int32_t _base_salary = 0;
};

std::ostream &operator <<(std::ostream &out, Employee const &data);

std::istream &operator >>(std::istream &in, Employee &data);

std::ofstream &operator <<(std::ofstream &out, Employee const &data);

std::ifstream &operator >>(std::ifstream &in, Employee &data);


class Developer : public Employee {
public:
  int salary() const {
    int salary = _base_salary;
    if (_has_bonus) { salary += 1000; }
    return salary;
  }
  void write_out(std::ostream &out) override;
  void read_in(std::istream &out) override;
  void write_out_file(std::ofstream &out) override;
  void read_in_file(std::ifstream &out) override;
private:
  bool _has_bonus = 0;
};



class SalesManager : public Employee {
public:
  int salary() const {
    return _base_salary + _sold_nm * _price * 0.01;
  }
  void write_out(std::ostream &out) override;
  void read_in(std::istream &out) override;
  void write_out_file(std::ofstream &out) override;
  void read_in_file(std::ifstream &out) override;
private:
  int32_t _sold_nm = 0, _price = 0;
};


class EmployeesArray {
public:
  void add( Employee *data);
  int total_salary();
  void write_out(std::ostream &out);
  void read_in(std::istream &out);
  void write_out_file(std::ofstream &out);
  void read_in_file(std::ifstream &out);
  void add_self_in_array(EmployeesArray &arr);
  ~EmployeesArray();
private: 
  std::vector <Employee*> _employees; 
  int _total_salary = 0;
};

std::ostream &operator <<(std::ostream &out, EmployeesArray &data);

std::ofstream &operator <<(std::ofstream &out, EmployeesArray &data);

std::ifstream &operator >>(std::ifstream &out, EmployeesArray &data);

#endif