/* Find range thst have sum of elements = target

elements = [1, -3, 4, 5]
target = 9
result = range(2, 4)  because elements[2] + elements[3] == target */

#include <iostream>
#include <span>
#include <numeric>
#include <vector>

template<class T>
std::pair<int, int> getRange(std::span<T> cont, T sum) {
    for (std::size_t offset{}; offset < cont.size()-1; offset++) {
        for (std::size_t width{2}; offset + width < cont.size() + 1; width++) {
            T nsum = std::accumulate(cont.begin() + offset, cont.begin() + offset + width, T{});
            //std::cout << nsum << " "  << offset << " " << width << "\n"; 
            if (nsum == sum)
                return std::make_pair(offset, offset + width);
            if (nsum > sum)
                break;
        }
    }
    return std::make_pair(-1, -1);
}

int main() {
    
        std::vector<int> a { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
        std::vector<std::string> s { "0", "1", "2", "3" };
   
        //auto res = getRange(std::span{a}, 9);
        auto res = getRange(std::span{s}, std::string{"23"});
      
        if(res.first != -1)
            std::cout << res.first << "\n" << res.second << "\n";
    
}
