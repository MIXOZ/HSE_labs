#include <iostream>

#include "my_vector.h"
#include <assert.h>

namespace product {

class Product {
public:
	Product(): quantity_(0), price_(0) {
		name_ = new char[1];
		name_[0] = '\0';
	}

	Product(const char* name, int quantity, double price): quantity_(quantity), price_(price) {
		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);
	}

	Product(const Product& other): quantity_(other.quantity_), price_(other.price_) {
		name_ = new char[strlen(other.name_) + 1];
		strcpy(name_, other.name_);
	}

	Product& operator=(const Product& other) {
		delete[] name_;
		name_ = new char[strlen(other.name_) + 1];
		strcpy(name_, other.name_);
		quantity_ = other.quantity_;
		price_ = other.price_;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Product& p) {
		return out << p.name_ << " " << p.quantity_ << " " << p.price_;
	}

	~Product() {
		delete[] name_;
	}

	
private:
	char *name_;
	int quantity_;
	double price_;
};

void print(const my_vector::my_vector<Product>& v) {
    std::cout << v << '\n';
}
}


namespace test {
	template <class T>
	void test_reserve(size_t n) {
		std::cout << "reserve:\n";
		my_vector::my_vector<T> v;
		v.reserve(n);
		assert(v.size() == 0);
		assert(v.capacity() >= n);
	}

	template <class T>
	void test_resize(size_t n) {
		std::cout << "resize:\n";
		my_vector::my_vector<T> v;
		v.resize(n);
		assert(v.size() == n);
		assert(v.capacity() >= n);
	}

	template <class T>
	void test_push_back(const T& obj, size_t n) {
		std::cout << "push_back:\n";
		my_vector::my_vector<T> v;
		for (size_t i = 0; i < n; i++) {
			v.push_back(obj);
		}
		assert(v.size() == n);
		assert(v.capacity() >= n);
	}

	template <class T>
	void test_constructor(size_t n) {
		std::cout << "constructor:\n";
		my_vector::my_vector<T> v(n);
		assert(v.size() == n);
		assert(v.capacity() >= n);
	}

	template <class T>
	void test_copy_constructor(const T& obj, size_t n) {
		std::cout << "copy constructor:\n";
		my_vector::my_vector<T> v(n);
		assert(v.size() == n);
		assert(v.capacity() >= n);
		v.push_back(obj);
		assert(v.size() == ++n);
		assert(v.capacity() >= n);
		my_vector::my_vector<T> u(v);
		assert(u.size() == n);
		assert(u.capacity() >= n);
	}

	template <class T>
	void test_assignment_operator(size_t n) {
		std::cout << "assignment operator:\n";
		my_vector::my_vector<T> v(n);
		assert(v.size() == n);
		assert(v.capacity() >= n);
		my_vector::my_vector<T> u = v;
		assert(u.size() == n);
		assert(u.capacity() >= n);
	}

	template <class T>
	void test_size_capacity(size_t n) {
		std::cout << "size:\n";
		my_vector::my_vector<T> v;
		assert(v.size() == 0);
		assert(v.capacity() >= 0);
		my_vector::my_vector<T> u(n);
		assert(u.size() == n);
		assert(u.capacity() >= n);
	}

	template <class T>
	void test_empty(size_t n) {
		std::cout << "empty:\n";
		my_vector::my_vector<T> v;
		if (v.empty()) std::cout << "OK\n";
		else std::cout << "ERROR\n";
		my_vector::my_vector<T> u(n);
		if (n != 0 && !u.empty()) std::cout << "OK\n";
		else {
			std::cout << "ERROR\n";
		}
	}

	template <class T>
	void test_pop_back(size_t n) {
		std::cout << "pop_back:\n";
		my_vector::my_vector<T> v(n);
		size_t k = n;
		for (size_t i = 0; i < n; i++) {
			v.pop_back();
			assert(v.size() == --k);
		}
	}

	template <class T>
	void test_get_set(const T& obj, size_t n) {
		std::cout << "operator[]:\n";
		my_vector::my_vector<T> v(n);
		v[0] = obj;
	}

	template <class T>
	void test_clear(size_t n) {
		std::cout << "clear:\n";
		my_vector::my_vector<T> v(n);
		v.clear();
		assert(v.size() == 0);
	}

	template <class T>
	void test_destructor(size_t n) {
		std::cout << "destructor:\n";
		my_vector::my_vector<T>* v = new my_vector::my_vector<T>(n);
		delete v;
	}
	template <class T>
	void test_my_vector(const T& obj, size_t n) {
		test_reserve<T>(n);
		test_resize<T>(n);
		test_push_back<T>(obj, n);
		test_copy_constructor<T>(obj, n);
		test_constructor<T>(n);
		test_assignment_operator<T>(n);
		test_size_capacity<T>(n);
		test_empty<T>(n);
		test_pop_back<T>(n);
		test_get_set<T>(obj, n);
		test_clear<T>(n);
		test_destructor<T>(n);
	}
}
int main() {
	test::test_my_vector<int>(10, 5);
	test::test_my_vector<product::Product>(product::Product("asdf", 4, 12.0), 3);
    return 0;
}