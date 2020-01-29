#include <iostream>
#include <fstream>
#include <bin_manip.hpp>
#include <employees.hpp>

void load_employees(EmployeesArray &arr, std::string &file_name) {
	std::ifstream in;
	in.open(file_name, std::ios::binary);
	arr.add_self_in_array(in);
	in.close();
}

void save_employees(EmployeesArray &arr, std::string &file_name) {
	std::ofstream out;
	out.open(file_name);
	out << arr;
	out.close();
}

void add_employee(EmployeesArray &arr) {
    int32_t type;
    std::cin >> type;
    Employee *data;
    if (type == 1) {
        data = new Developer;
    } else if (type == 2) {
        data = new SalesManager;
    }
    std::cin >> (*data);
    arr.add(data);
}

int main() {
    std::string command;
    EmployeesArray arr;
    while (std::cin >> command) {
        if (command == "exit") {
            return 0;
        }
        if (command == "load") {
            std::string file_name;
            std::cin >> file_name;
            load_employees(arr, file_name);
        } else if (command == "save") {
            std::string file_name;
            std::cin >> file_name;
            save_employees(arr, file_name);
        } else if (command == "add") {
            add_employee(arr);
        } else if (command == "list") {
            std::cout << arr;
        }
    }
    return 0;
}