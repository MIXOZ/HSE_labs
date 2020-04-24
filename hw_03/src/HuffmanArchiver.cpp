#include "../include/HuffmanArchiver.h"

const char* ZipException::what() const noexcept {
    return "bad archive";
}

HuffmanArchiver::HuffmanArchiver() : size_init(0), size_fin(0), size_table(0) {}

HuffmanArchiver::~HuffmanArchiver() = default;

void HuffmanArchiver::print_time() const {
    std::cout << size_init << '\n' << size_fin << '\n' << size_table << '\n';
}

void HuffmanArchiver::archive(std::ifstream& in, std::ofstream& out) {
    in.seekg(0, in.end);
    int length = in.tellg();
    size_init = in.tellg();
    in.seekg(0, out.beg);
    std::map<char, int> frequency_table;    
    for (int i = 0; i < length; i++) {
        char symbol;
        in.get(symbol);
        frequency_table[symbol]++;
    }
    HuffmanTree tree(frequency_table);
    set_table(out, frequency_table);
    out.write((char*) &length, HALF_BAIT);
    size_table += HALF_BAIT;
    in.seekg(0, in.beg);
    for (int i = 0; i < length; i++) {
        char symbol;
        in.get(symbol);
        set_value(out, tree.get_node(symbol));
    }
    set_bit(out, 0, true);
    print_time();
}

void HuffmanArchiver::unarchive(std::ifstream& in, std::ofstream& out) {
    std::map<char, int> frequency_table;
    get_table(in, frequency_table);
    HuffmanTree tree(frequency_table);
    std::shared_ptr<HuffmanNode> node = tree.get_root();
    int length;
    in.read((char*) &length, HALF_BAIT);
    size_table += HALF_BAIT;
    char byte;
    while (length) {
        if (!in.good())
            throw ZipException();
        size_init++;
        in.read(&byte, UNIQ);
        for (int i = 0; i < 8 && length; i++) {
            int bit = (byte & (UNIQ << i)) > 0;
            if (!node->can_move_down(bit) && !node->is_leaf())
                throw ZipException();
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

void HuffmanArchiver::set_table(std::ofstream& out, const std::map<char, int>& frequency_table) {
    int size = frequency_table.size();
    out.write((char*) &size, HALF_BAIT);
    for (auto& symbol : frequency_table) {
        out.write(&symbol.first, UNIQ);
        out.write((char*) &symbol.second, HALF_BAIT);
    }
    size_table += size * TABLE_SCALE + HALF_BAIT;
}

void HuffmanArchiver::set_bit(std::ofstream& out, int bit, bool flush) {
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

void HuffmanArchiver::set_value(std::ofstream& out, const std::shared_ptr<HuffmanNode>& node) {
    if (!node->can_move_up()) return;
    set_value(out, node->move_up());
    set_bit(out, node->move_up()->move_down(0) == node ? 0 : UNIQ, false);
}

void HuffmanArchiver::get_table(std::ifstream& in, std::map<char, int>& frequency_table) {
    int size;
    in.read((char*) &size, HALF_BAIT);
    for (int i = 0; i < size; i++) {
        char symbol;
        in.read(&symbol, UNIQ);
        int count;
        in.read((char*) &count, HALF_BAIT);
        frequency_table[symbol] = count;
    }
    size_table = size * TABLE_SCALE + HALF_BAIT;
}
