#include <iostream>
#include <vector>

template<class base_iterator, typename check_predicate>
class filter_iterator : public base_iterator {
   public:     
    filter_iterator(check_predicate func, base_iterator begin_it, base_iterator end_it) : 
      func_{func}, curr_it_{begin_it}, end_it_ {end_it} {}
    
    auto operator*() {
        search_next();
        return *curr_it_;
    }
    auto operator++() { 
        if (curr_it_ != end_it_)
            curr_it_++;
        search_next();
        return this;
    }
    void search_next() {
        while( curr_it_ != end_it_ && *curr_it_ && !func_(*(curr_it_))) 
                curr_it_++;
    }
    bool is_end() { return curr_it_ == end_it_; }
    auto operator !=(base_iterator some_it) { return curr_it_ != some_it; }

    check_predicate func_;
    base_iterator curr_it_, end_it_;
};


int main() {
    std::vector<char> v = {'1', ' ', '2', ' ', '3'};
    
    auto pred = [] (auto x) {return x != ' ';};
    
    filter_iterator<decltype(v.begin()), decltype(pred)> filter_it(pred, v.begin(), v.end());
    for(; filter_it != v.end(); ++filter_it)
        std::cout << *filter_it << std::endl;
    
    return 0;
}
