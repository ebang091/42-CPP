#include "Span.hpp"

Span::Span(unsigned int N):idx(0), max_len(N), isSorted(false)
{}

Span::Span(const Span &copy): vec(copy.vec), idx(copy.idx), max_len(copy.max_len), isSorted(false){

}

Span &Span::operator=(const Span &copy){
	if(this == &copy)
		return *this;
	vec = copy.vec;
	idx = copy.idx;
	max_len = copy.max_len;
	return *this;
}

Span::~Span(){

}

void Span::addNumber(int n){
	if(this->idx >= max_len)
		throw std::runtime_error("error: maximum storage of integers.\n");
	vec.push_back(n);
	this->idx++;
	isSorted = false;
}

long long  Span::shortestSpan(){
	if(idx == 0 || idx == 1)
		throw std::runtime_error("error: more than 2 elements required.\n");
	if(isSorted == false){
		sort(vec.begin(), vec.end());
		isSorted = true;
	}
	long long shortest_span = vec[1] - vec[0];
	for(std::vector<int>::iterator iter = vec.begin() + 1; iter < vec.end() -1; iter++){
		long long cmp = *(iter + 1) - *iter;
		if(cmp < shortest_span)
			shortest_span = cmp;
	}
	return shortest_span;
}

long long Span::longestSpan(){
	if(idx == 0 || idx == 1)
		throw std::runtime_error("error: more than 2 elements required.\n");
	if(isSorted == false){
		sort(vec.begin(), vec.end());
		isSorted = true;
	}
	long long longest_span = vec[max_len - 1] - vec[0];
	return longest_span;	
}

int Span::getNum(unsigned int idx) const {
	if (idx >= max_len)
		throw std::runtime_error("Invalid index\n");
	return vec[idx];
}

unsigned int Span::size() const {
	return this->idx;
}
