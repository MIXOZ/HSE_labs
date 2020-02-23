#include <matrix.h>

int main() {
    std::vector<Matrix> matr_arr(10);
    std::string command;
    while (std::cin >> command) {
        try {
            if (command == "exit") {
                return 0;
            } else if (command == "load") {
                char x;
                int reg;
                std::string file_name;
                std::cin >> x;
                std::cin >> reg;
                std::cin >> file_name;
                try {
                    matr_arr[reg].matr_load(file_name);
                }
                catch(Matrix_Exception error) {
                    std::cout << error.what() << "\n";
                }
            } else if (command == "print") {
                char x;
                int reg;
                std::cin >> x;
                std::cin >> reg;
                matr_arr[reg].matr_print();
            } else if (command == "add") {
                char x;
                int reg1;
                int reg2;
                std::cin >> x; 
                std::cin >> reg1; 
                std::cin >> x; 
                std::cin >> reg2;
                try {
                    matr_arr[reg1].matr_add(matr_arr[reg2]);
                }
                catch(Matrix_Exception error) {
                    std::cout << error.what() << "\n";
                }
            } else if (command == "mul") {
                char x;
                int reg1;
                int reg2;
                std::cin >> x; 
                std::cin >> reg1; 
                std::cin >> x; 
                std::cin >> reg2;
                try {
                    matr_arr[reg1].matr_mul(matr_arr[reg2]);
                }
                catch(Matrix_Exception error) {
                    std::cout << error.what() << "\n";
                }
            } else if (command == "elem") {
                char x;
                int reg;
                int row;
                int col;
                std::cin >> x;
                std::cin >> reg;
                std::cin >> row;
                std::cin >> col;
                try {
                    matr_arr[reg].matr_elem(row, col);
                }
                catch(Matrix_Exception error) {
                    std::cout << error.what() << "\n";
                }
            }
        }
        catch (std::bad_alloc &ba) {
            std::cout << "Unable to allocate memory." << "\n";
        }
    }
    return 0;
}
