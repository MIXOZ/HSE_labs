#ifndef C___HUFFMANARCHIVER_H
#define C___HUFFMANARCHIVER_H

#include "Huffman.h"
#include <sstream>

enum { 
    HALF_BAIT = 4, 
    TABLE_SCALE = 5,
    UNIQ = 1
};

class ZipException : public std::exception {
public:
    const char* what() const throw();
};

class HuffmanArchiver {
public:
    HuffmanArchiver();
    ~HuffmanArchiver();
    void print_time() const;
    void archive(std::ifstream& fin, std::ofstream& fout);
    void unarchive(std::ifstream& fin, std::ofstream& fout);
private:
    void set_table(std::ofstream& fout, const std::map<char, int>& frequency_table);
    void set_bit(std::ofstream& fout, int bit, bool flush);
    void set_value(std::ofstream& fout, const std::shared_ptr<HuffmanNode>& node);
    void get_table(std::ifstream& fin, std::map<char, int>& frequency_table);
    int size_init;
    int size_fin;
    int size_table;
};

#endif //C___HUFFMANARCHIVER_H
