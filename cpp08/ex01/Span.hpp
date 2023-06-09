#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{

private:
	std::vector<int> vec;
	unsigned int max_len;
	bool isSorted;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	Span& operator=(const Span &copy);
	~Span();

	void addNumber(int n);

	long long  shortestSpan();
	long long longestSpan();
	unsigned int size() const ;
	int getNum(unsigned int idx) const;
	unsigned int getMaxSize() const;
	void changeNum(unsigned int idx, int value);
	template <typename C, typename C>	void insert(std::iterator<C, T> begin, std::iterator<T, C> end);
	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();

};

template <typename C, typename T>
void Span::insert(std::iterator<C, T> begin, std::iterator<T, C> end){
	for(std::iterator<C, T> it = begin; it != end; it++){
		addNumber(*it);
	}
}

#endif
