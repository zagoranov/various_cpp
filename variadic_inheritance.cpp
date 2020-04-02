#include <string>


template<typename... Mixins>
class Point : public Mixins...{
    public:
    Point() : Mixins()... {}
};

template<typename... Mixins>
class PointVisit : public Mixins...{
    public:
    PointVisit() : Mixins()... {}
    
    template<typename Visitor>
    void visitMixins(Visitor visitor)
    {
        visitor(static_cast<Mixins&>(*this)...);
    }
};

template<typename... Mixins>
class PointCtor : public Mixins...{
    public:
    PointCtor(Mixins... mixins) : Mixins(mixins)... {}
};


struct Color {
    char red, green, blue;
};
struct Label {
    std::string name;
};


int main() {
    Point<Label, Color> p;
    
    PointCtor<Color, Label> p2({0x7f, 0, 0x7f}, {"center"});
}
