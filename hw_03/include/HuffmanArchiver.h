#ifndef C___HUFFMANARCHIVER_H
#define C___HUFFMANARCHIVER_H

#include "Huffman.h"
#include <sstream>
#include <climits>

namespace HuffmanArchiver {
    constexpr int TABLE_SCALE = 5;
    constexpr int UNIQ = 1;


    class ArchiverException : public std::exception {
    public:
        const char *what() const throw();
    };

    class HuffmanArchiver {
    public:
        HuffmanArchiver();

        ~HuffmanArchiver();

        void archive(std::istream &fin, std::ostream &fout);

        void unarchive(std::istream &fin, std::ostream &fout);

    private:
        void set_table(std::ostream &fout, const std::map<char, int> &frequency_table);

        void set_bit(std::ostream &fout, int bit, bool flush);

        void set_value(std::ostream &fout, const std::shared_ptr<Huffman::HuffmanNode> &node);

        void get_table(std::istream &fin, std::map<char, int> &frequency_table);

        void print_time() const;

        int size_init;

        int size_fin;

        int size_table;
    };
}
#endif //C___HUFFMANARCHIVER_H
