
// all_of()

template<class... Args, class Predicate>
void AllOf(Args&&... args, Predicate predicate) {

	std::all_of(std::forward<Args>(args)..., predicate);

}

// cozy initializer

template<class... Args>
void Log(Args&&... args) {
	(std:cerr << ... << args) << '\n';
}


