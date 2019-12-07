

size_t mem_hash(void*, size_t);


//		before constexpr if:
struct MyHash1 {
template<class T>
size_t operator()(const T& value,
	std::enable_if_t<std::is_integral_v<T>>* = nullptr) const {
		return mem_hash(&value, sizeof(value));
	}
template<class T>
size_t operator()(const T& value,
	std::enable_if_t<!std::is_integral_v<T>>* = nullptr) const {
		return hash_value(value);
	}
};


//		after constexpr if:
struct MyHash2 {
template<class T>
size_t operator()(const T& value) const {
	if constexpr(std::is_integral_v<T>) {
		return mem_hash(&value, sizeof(value));
	} else {
		return hash_value(value);
	}
}
};
