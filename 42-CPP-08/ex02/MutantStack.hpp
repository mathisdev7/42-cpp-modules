/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:28:08 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/27 16:18:52 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <iterator>
#include <exception>

template <typename T>
class MutantStack
{
private:
	std::stack<T> stack;

public:
	MutantStack() {}
	MutantStack(const MutantStack &other) : stack(other.stack) {}
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
		{
			stack = other.stack;
		}
		return *this;
	}

	~MutantStack() {}

	void push(const T &value) { stack.push(value); }
	void pop()
	{
		if (!stack.empty())
			stack.pop();
	}
	T &top()
	{
		if (!stack.empty())
			return stack.top();
	}
	const T &top() const
	{
		if (!stack.empty())
			return stack.top();
	}
	bool empty() const { return stack.empty(); }
	size_t size() const { return stack.size(); }

	class iterator
	{
	private:
		std::deque<T> elements;
		typename std::deque<T>::iterator current;

	public:
		iterator(std::stack<T> &stack)
		{
			std::stack<T> temp = stack;
			while (!temp.empty())
			{
				elements.push_front(temp.top());
				temp.pop();
			}
			current = elements.begin();
		}

		T &operator*() { return *current; }
		T *operator->() { return &(*current); }

		iterator &operator++()
		{
			++current;
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			++(*this);
			return tmp;
		}

		bool operator!=(const iterator &other) const { return current != other.current; }
		bool operator==(const iterator &other) const { return current == other.current; }
	};

	iterator begin() { return iterator(stack); }

	iterator end() { return iterator(stack); }
};
