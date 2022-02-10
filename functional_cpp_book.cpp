// https://www.manning.com/books/functional-programming-in-c-plus-plus

// 3.3 Writing function objects that are even terser than lambdas

class error_test_t {
public:
    error_test_t(bool error = true)
        : m_error(error)  {   }

    template <typename T>
	bool operator()(T&& value) const  {
        return m_error ==    
                (bool)std::forward<T>(value).error();    
    }

error_test_t operator==(bool test) const  {
        return error_test_t(    
                test ? m_error : !m_error    
            );    
    }

    error_test_t operator!() const  {
        return error_test_t(!m_error);    
    }

private:
    bool m_error;
};

//error_test_t error(true);
//error_test_t not_error(false);


// 4.1 Partial function application

template <typename Function, typename SecondArgType>
class partial_application_bind2nd_impl {
public:
 partial_application_bind2nd_impl(Function function,
                                     SecondArgType second_arg)
        : m_function(function)
        , m_value(second_arg)   { }

    template <typename FirstArgType>
    auto operator()(FirstArgType&& first_arg) const
        -> decltype(m_function(
                std::forward<FirstArgType>(first_arg),
                m_second_arg))       						// or just  decltype(auto)
    {
        return m_function(
                std::forward<FirstArgType>(first_arg),
                m_second_arg);    
    }

private:
    Function m_function;
    SecondArgType m_second_arg;
};

