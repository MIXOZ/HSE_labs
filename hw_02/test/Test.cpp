#include <Test.h>
#include <BoardTest.h>

void Test::check(bool expr, const char *func, const char  *filename, size_t line_num) {
    if (!expr) {
        std::cout << "Error in function: " << func 
                  << ", in file: " << filename << ", in line: " << line_num << "\n";
        failed_num++;
    }
    total_num++;
}


bool Test::show_final_result() {
    if (failed_num == 1) {
        std::cout << failed_num << " test failed from " << total_num << "\n";
        return false;   
    }
    std::cout << failed_num << " tests failed from " << total_num << "\n";
    if (!failed_num) return false;
    return true;
}


int main() {
    BoardTest bt;
    bt.run_all_tests();
    bt.show_final_result();
    return 0;
}