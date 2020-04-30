#ifndef C___HUFFMAN_H
#define C___HUFFMAN_H

#include <fstream>
#include <exception>
#include <memory> 
#include <map>
#include <iostream>
#include <set>

namespace Huffman {

    class HuffmanNode {
    public:
        HuffmanNode();

        ~HuffmanNode();

        std::shared_ptr<HuffmanNode> move_down(int edge) const;

        std::shared_ptr<HuffmanNode> move_up() const;

        bool can_move_down(int edge) const;

        bool can_move_up() const;

        bool is_leaf() const;

        char get_value() const;

        bool operator<(const HuffmanNode &other) const;

    private:
        HuffmanNode(char value, std::shared_ptr<HuffmanNode> left,
                    std::shared_ptr<HuffmanNode> right,
                    std::shared_ptr<HuffmanNode> parent);

        static int next_id();

        friend class HuffmanTree;

        char value;
        int id;
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right;
        std::shared_ptr<HuffmanNode> parent;
    };

    class HuffmanTree {
    public:
        HuffmanTree();

        HuffmanTree(const std::map<char, int> &frequency_table);

        ~HuffmanTree();

        std::shared_ptr<HuffmanNode> get_node(char symbol);

        std::shared_ptr<HuffmanNode> get_root();

    private:
        HuffmanTree(const HuffmanTree &tree);

        HuffmanTree operator=(const HuffmanTree &tree);

        std::shared_ptr<HuffmanNode> root;

        std::map<char, std::shared_ptr<HuffmanNode>> pos;
    };
}
#endif //C___HUFFMAN_H
