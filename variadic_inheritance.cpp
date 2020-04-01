template<typename... Mixins>
class Point : public Mixins...{
    public:
    Point() : Mixins()... {}
};

struct Color {};
struct Label {};

int main() {
    Point<Label, Color> p;
    
}
