#include "../include/HuffmanArchiver.h"

namespace HuffmanArchiver {

    const char *ArchiverException::what() const noexcept {
        return "bad archive";
    }

    HuffmanArchiver::HuffmanArchiver() : size_init(0), size_fin(0), size_table(0) {}

    HuffmanArchiver::~HuffmanArchiver() = default;

    void HuffmanArchiver::archive(std::istream &in, std::ostream &out) {
        in.seekg(0, std::istream::end);
        int length = in.tellg();
        size_init = in.tellg();
        in.seekg(0, std::ostream::beg);
        std::map<char, int> frequency_table;
        for (int i = 0; i < length; i++) {
            char symbol;
            in.get(symbol);
            frequency_table[symbol]++;
        }
        Huffman::HuffmanTree tree(frequency_table);
        set_table(out, frequency_table);
        out.write((char *) &length, CHAR_BIT / 2);
        size_table += CHAR_BIT / 2;
        in.seekg(0, std::istream::beg);
        for (int i = 0; i < length; i++) {
            char symbol;
            in.get(symbol);
            set_value(out, tree.get_node(symbol));
        }
        set_bit(out, 0, true);
        print_time();
    }

    void HuffmanArchiver::unarchive(std::istream &in, std::ostream &out) {
        std::map<char, int> frequency_table;
        get_table(in, frequency_table);
        Huffman::HuffmanTree tree(frequency_table);
        std::shared_ptr<Huffman::HuffmanNode> node = tree.get_root();
        int length;
        in.read((char *) &length, CHAR_BIT / 2);
        size_table += CHAR_BIT / 2;
        char byte;
        while (length) {
            if (!in.good())
                throw ArchiverException();
            size_init++;
            in.read(&byte, UNIQ);
            for (int i = 0; i < 8 && length; i++) {
                int bit = (byte & (UNIQ << i)) > 0;
                if (!node->can_move_down(bit) && !node->is_leaf())
                    throw ArchiverException();
                if (!node->can_move_down(bit))
                    node = tree.get_root();
                node = node->move_down(bit);
                if (node->is_leaf()) {
                    out.put(node->get_value());
                    size_fin++;
                    length--;
                }
            }
        }
        print_time();
    }

    void HuffmanArchiver::set_table(std::ostream &out, const std::map<char, int> &frequency_table) {
        int size = frequency_table.size();
        out.write((char *) &size, CHAR_BIT / 2);
        for (auto &symbol : frequency_table) {
            out.write(&symbol.first, UNIQ);
            out.write((char *) &symbol.second, CHAR_BIT / 2);
        }
        size_table += size * TABLE_SCALE + CHAR_BIT / 2;
    }

    void HuffmanArchiver::set_bit(std::ostream &out, int bit, bool flush) {
        static char buf = 0;
        static int cur_pos = 0;
        if (flush) {
            if (cur_pos) {
                out.write(&buf, UNIQ);
                size_fin++;
            }
            return;
        }
        buf |= bit << cur_pos;
        cur_pos = (cur_pos + UNIQ) & 7;
        if (!cur_pos) {
            out.write(&buf, UNIQ);
            size_fin++;
            buf = 0;
        }
    }

    void HuffmanArchiver::set_value(std::ostream &out, const std::shared_ptr<Huffman::HuffmanNode> &node) {
        if (!node->can_move_up()) return;
        set_value(out, node->move_up());
        set_bit(out, node->move_up()->move_down(0) == node ? 0 : UNIQ, false);
    }

    void HuffmanArchiver::get_table(std::istream &in, std::map<char, int> &frequency_table) {
        int size;
        in.read((char *) &size, CHAR_BIT / 2);
        for (int i = 0; i < size; i++) {
            char symbol;
            in.read(&symbol, UNIQ);
            int count;
            in.read((char *) &count, CHAR_BIT / 2);
            frequency_table[symbol] = count;
        }
        size_table = size * TABLE_SCALE + CHAR_BIT / 2;
    }

    void HuffmanArchiver::print_time() const {
        std::cout << size_init << '\n'
                  << size_fin << '\n'
                  << size_table<< '\n';
    }
}