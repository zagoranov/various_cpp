#include <memory>
#include <iostream>

template<typename T>
class Node {
public:
    Node(T value_) : value {value_} {}
    Node(T value_, std::shared_ptr<Node<T>> left_, std::shared_ptr<Node<T>> right_)
        : value {value_}, 
        left{left_}, 
        right{right_} {}
    T value;
    std::shared_ptr<Node<T>> left, right;
};

template<typename T>
void recoursePrint(std::shared_ptr<Node<T>> node) {
    std::cout << "    " << node->value;
    if(node->left) {
        std::cout << std::endl;
        recoursePrint(node->left);
        recoursePrint(node->right);
    }
}

template<typename T>
void invertTree(std::shared_ptr<Node<T>> node) {
    if(node->left) {
        std::swap(node->left, node->right);
        invertTree(node->left);
        invertTree(node->right);
    }
}


int main() {
    auto node12 = std::make_shared<Node<int>>(12, std::make_shared<Node<int>>(1), std::make_shared<Node<int>>(2));
    auto root = std::make_shared<Node<int>>(4, node12, std::make_shared<Node<int>>(3));
    
    recoursePrint(root);
    
    invertTree(root);
    
    std::cout << std::endl;    
    std::cout << std::endl;
    recoursePrint(root);
    
    exit(0);

}
