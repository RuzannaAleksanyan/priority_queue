#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <bits/stdc++.h>

template <typename T>
struct node {
    T value;
	int priority;
};

template <typename T>
class priority_queue 
{
private:
	node<T>* pr;
	int m_size;
	int m_capacity;
public:
	priority_queue(int cap);

	~priority_queue();

    void enqueue(int value, int priority);
    int top();
    void dequeue();
	bool empty() const;
	int size() const;
	void pop();
	void push(const T& value, int priority);
	T at(int index);
};

template <typename T>
priority_queue<T>::priority_queue(int cap) {
	m_size = -1;
	m_capacity = cap;
	pr = new node<T>[m_capacity];
}

template <typename T>
priority_queue<T>::~priority_queue() {
	delete pr;
}

template <typename T>
void priority_queue<T>::enqueue(int value, int priority) {
	++m_size;

	pr[m_size].value = value;
	pr[m_size].priority = priority;
}

template <typename T>
int priority_queue<T>::top() {
	int highest_priority = INT_MIN;
	int index = -1;

	for (int i = 0; i <= m_size; ++i) {

		if (highest_priority == pr[i].priority && index > -1 && pr[index].value < pr[i].value) {
			highest_priority = pr[i].priority;
			index = i;
		}
		else if (highest_priority < pr[i].priority) {
			highest_priority = pr[i].priority;
			index = i;
		}
	}

	return index;
}

template <typename T>
void priority_queue<T>::dequeue() {
	int index = top();

	for (int i = index; i < m_size; ++i) {
		pr[i] = pr[i + 1];
	}

	--m_size;
}

template <typename T>
bool priority_queue<T>::empty() const {
	return (m_size == 0) ? true : false;
}

template <typename T>
int priority_queue<T>::size() const {
	return m_size;
}

template <typename T>
void priority_queue<T>::pop() {
    if (m_size == 0) {
        return;
    }

    int max_iondex = 0;
    int max_priority = pr[0].priority;

    for (int i = 1; i < m_size; ++i) {
        if (pr[i].priority > max_priority) {
            max_priority = pr[i].priority;
            max_iondex = i;
        }
    }

    for (int i = max_iondex; i < m_size - 1; ++i) {
        pr[i] = pr[i + 1];
    }

    --m_size;
}


template <typename T>
void priority_queue<T>::push(const T& value, int priority) {
    if (m_size >= m_capacity) {
        return;
    }

    node<T> new_node;
    new_node.value = value;
    new_node.priority = priority;

    int insert_index = 0;
    while (insert_index < m_size && pr[insert_index].priority >= priority) {
        insert_index++;
    }

    for (int i = m_size; i > insert_index; i--) {
        pr[i] = pr[i - 1];
    }

    pr[insert_index] = new_node;

    
	++m_size;
}

template <typename T>
T priority_queue<T>::at(int index) {
    if (index < 0 || index > m_size) {
        return pr[0].value;
    }

    return pr[index].value;
}

#endif
