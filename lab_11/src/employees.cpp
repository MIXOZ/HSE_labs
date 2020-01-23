#include <vector>
#include <string>
#include <stdint.h>
#include <employees.hpp>
#include <iostream>
#include <fstream>


std::ostream& operator <<(std::ostream &out, Employee &data){
  data.write_out(out);
  return out;
}

std::istream& operator >>(std::istream &in, Employee &data){
  data.read_in(in);
  return in;
}

std::ofstream& operator <<(std::ofstream &out, Employee &data){
  data.write_out_file(out);
  return out;
}

std::ifstream& operator >>(std::ifstream &in, Employee &data){
  data.read_in_file(in);
  return in;
}



Employee::~Employee() {
    delete _name;
}
//-------------------------Developer---------------------------


void Developer::write_out(std::ostream &out){
  out << "Developer" << "\n";
  out << "Name: " << _name << "\n";
  out << "Base salary: " << _base_salary << "\n";
  if (_has_bonus) out << "Has bonus: " << '+' << "\n";
  else out << "Has bonus: " << '-' << "\n";
}

void Developer::read_in(std::istream &in){
  in >> _name;
  in >> _base_salary;
  in >> _has_bonus;
}

void Developer::write_out_file(std::ofstream &out){
  out << write_le_int32(1) << write_str(_name)
    << write_le_int32(_base_salary) << write_bool(_has_bonus);
}

void Developer::read_in_file(std::ifstream &in){
  in >> read_str(_name) >> read_le_int32(_base_salary) >> read_bool(_has_bonus);
}

//---------------------------SalesManager---------------------------------

void SalesManager::write_out(std::ostream &out){
  out << "SalesManager\n"; 
  out << "Name: " << _name << "\n";
  out << "Base salary: " << _base_salary << "\n";
  out << "Sold items: " << _sold_nm << "\n";
  out << "Item price: " << _price << "\n";
}

void SalesManager::read_in(std::istream &in){
  in >> _name;
  in >> _base_salary;
  in >> _sold_nm;
  in >> _price;
}

void SalesManager::write_out_file(std::ofstream &out){
  out << write_le_int32(2) << write_str(_name) << write_le_int32(_base_salary)
    << write_le_int32(_sold_nm) << write_le_int32(_price);
}

void SalesManager::read_in_file(std::ifstream &in){
  in >> read_str(_name) >> read_le_int32(_base_salary)
    >> read_le_int32(_sold_nm) >> read_le_int32(_price); 
}

//-------------------------EmployeesArray---------------------------

void EmployeesArray::add(Employee *data) {
    _employees.push_back(data);
    _total_salary += data->salary();
}
  
int EmployeesArray::total_salary()  {
    return _total_salary;
}

void EmployeesArray::write_out(std::ostream &out) {
  for (size_t i = 0; i < _employees.size(); i++) {
      out << i + 1 << ". " << *_employees[i];
  }
  out << "== Total salary: " << total_salary() << "\n";
  out << "\n";
}

void EmployeesArray::write_out_file(std::ofstream &out){
  out << write_le_int32(_employees.size());
  for (size_t i = 0; i < _employees.size(); ++i) {
    out << *_employees[i];
  }
}

void EmployeesArray::read_in_file(std::ifstream &in){
  int32_t size_array;
  in >> read_le_int32(size_array);
  _employees = std::vector<Employee*>(size_array);
  for (int i = 0; i < size_array; ++i) {
    int32_t type;
    in >> read_le_int32(type);
    if (type == 1) {
      _employees[i] = new Developer();
    } else {
      _employees[i] = new SalesManager();
    }
    in >> (*_employees[i]);
  }
}

EmployeesArray::~EmployeesArray() {
  for (auto i : _employees) {
    delete i;
  }
}

void EmployeesArray::add_self_in_array(EmployeesArray &arr) {
  for (int i = 0; i < (int)_employees.size(); ++i) {
    assert(_employees[i] != nullptr);
    arr.add(_employees[i]);
  }
}

std::ostream &operator <<(std::ostream &out, EmployeesArray &data) {
    data.write_out(out);
    return out;
}

std::ofstream &operator <<(std::ofstream &out, EmployeesArray &data) {
    data.write_out_file(out);
    return out;
}

std::ifstream &operator >>(std::ifstream &in, EmployeesArray &data) {
    data.read_in_file(in);
    return in;
}
