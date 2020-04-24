#include "../include/Huffman.h"

HuffmanTree::HuffmanTree() {
    root = std::make_shared<HuffmanNode>();
}

HuffmanTree::HuffmanTree(const std::map<char, int>& frequency_table) {
    auto comp = [](const std::pair<int, std::shared_ptr<HuffmanNode>> &o1, const std::pair<int, std::shared_ptr<HuffmanNode>> &o2)->bool {
        if (o1.first != o2.first)
            return o1.first < o2.first;
        return *o1.second < *o2.second;
    };
    std::set<std::pair<int, std::shared_ptr<HuffmanNode>>, decltype(comp) > buffer(comp);
    for (auto& symbol : frequency_table) {
        auto *_node =  new HuffmanNode(symbol.first, nullptr, nullptr, nullptr);
        std::shared_ptr<HuffmanNode> node(_node);
        pos[node->value] = node;
        buffer.insert(std::make_pair(symbol.second, node));
    }
    if (buffer.empty()) {
        root = std::make_shared<HuffmanNode>();
        return;
    }
    if (buffer.size() == 1) {
        root = std::make_shared<HuffmanNode>();
        root->left = buffer.begin()->second;
        root->left->parent = root;
        return;
    }
    while (buffer.size() > 1) {
        std::pair<int, std::shared_ptr<HuffmanNode>> l = *buffer.begin();
        buffer.erase(buffer.begin());
        std::pair<int, std::shared_ptr<HuffmanNode>> r = *buffer.begin();
        buffer.erase(buffer.begin());
        auto* _node = new HuffmanNode(0, l.second, r.second, nullptr);
        std::shared_ptr<HuffmanNode> node(_node);
        buffer.insert(std::make_pair(l.first + r.first, node));
    }
    root = buffer.begin()->second;
}

HuffmanTree::~HuffmanTree() = default;

std::shared_ptr<HuffmanNode> HuffmanTree::get_node(char symbol) {
    return pos[symbol];
}

std::shared_ptr<HuffmanNode> HuffmanTree::get_root() {
    return root;
}

HuffmanNode::HuffmanNode() :
        value(0), left(nullptr), right(nullptr), parent(nullptr) {
    id = next_id();
}

HuffmanNode::HuffmanNode(char _value, std::shared_ptr<HuffmanNode> lt, std::shared_ptr<HuffmanNode> rt, std::shared_ptr<HuffmanNode> pt) :
        value(_value), left(std::move(lt)), right(std::move(rt)), parent(std::move(pt)) {
    if (left != nullptr)
        left->parent = std::shared_ptr<HuffmanNode>(this);
    if (right != nullptr)
        right->parent = std::shared_ptr<HuffmanNode>(this);
    id = next_id();
}

int HuffmanNode::next_id() {
    static int GLOBAL_ID = 0;
    return GLOBAL_ID++;
}

std::shared_ptr<HuffmanNode> HuffmanNode::move_down(int edge) const {
    return edge == 0 ? left : right;
}

bool HuffmanNode::can_move_down(int edge) const {
    return edge == 0 ? left != nullptr : right != nullptr;
}

std::shared_ptr<HuffmanNode> HuffmanNode::move_up() const {
    return parent;
}

bool HuffmanNode::can_move_up() const {
    return parent != nullptr;
}

bool HuffmanNode::is_leaf() const {
    return left == nullptr && right == nullptr;
}

char HuffmanNode::get_value() const {
    return value;
}

bool HuffmanNode::operator<(const HuffmanNode& other) const {
    return id < other.id;
}

HuffmanNode::~HuffmanNode() = default;