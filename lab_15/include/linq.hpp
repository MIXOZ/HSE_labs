#ifndef LINQ_H_
#define LINQ_H_

#include <utility>
#include <vector>

namespace linq {
namespace impl {

template<typename T, typename Iter>
class range_enumerator;
template<typename T>
class drop_enumerator;
template<typename T, typename U, typename F>
class select_enumerator;
template<typename T, typename F>
class until_enumerator;
template<typename T, typename F>
class where_enumerator;
template<typename T>
class take_enumerator;


template<typename T>
class enumerator {
public:
  virtual const T& operator*() = 0; // Получает текущий элемент.
  virtual enumerator& operator++() = 0;  // Переход к следующему элементу
  virtual operator bool() const = 0;  // Возвращает true, если есть текущий элемент

  auto drop(int count) {
    return drop_enumerator<T>(*this, count);
  }

  template<typename U = T, typename F>
  auto select(F func) {
    return select_enumerator<U, T, F>(*this, func);
  }

  template<typename F>
  auto until(F func) {
    return until_enumerator<T, F>(*this, func);
  }

  auto until_eq(const T& x) {
    auto pred = [x](const T& y) {
      return x == y;
    };
    return until(pred);
  }

  std::vector<T> to_vector() {
    std::vector<T> result;
    while (*this) {
      result.push_back(**this);
      ++*this;
    }
    return result;
  }

  template<typename Iter>
  void copy_to(Iter it) {
    while (*this) {
      *it = **this;
      ++it;
      ++*this;
    }
  }

  template <typename F>
  auto where(F func) {
    return where_enumerator<T, F>(*this, func);
  }
  
  auto where_neq(const T& x) {
    auto pred = [x](const T& y) {
      return x != y;
    };
    return where(pred);
  }

  auto take(int count) {
    return take_enumerator<T>(*this, count);
  }
  
};

template<typename T, typename Iter>
class range_enumerator : public enumerator<T> {
public:
  range_enumerator(Iter begin, Iter end) : begin_(begin), end_(end) {
  }

  const T& operator*() {
    return *begin_;
  }

  range_enumerator& operator++() {
    begin_++;
    return *this;
  }

  operator bool() const {
    return begin_ != end_;
  }
  
private:
  Iter begin_, end_;
};

template<typename T>
class drop_enumerator : public enumerator<T> {
public:
  drop_enumerator(enumerator<T>& parent, int count) : parent_(parent) {
    while(parent_ && count > 0) {
      ++parent_;
      count--;
    }
  }

  const T& operator*() {
    return *parent_;
  }

  drop_enumerator& operator++() {
    ++parent_;
    return *this;
  }

  operator bool() const {
    return parent_;
  }

private:
  enumerator<T>& parent_;
};

template<typename T, typename U, typename F>
class select_enumerator : public enumerator<T> {
public:
  select_enumerator(enumerator<U> &parent, F func) : parent_(parent), func_(func) {
  }

  const T& operator*() {
    return last_ = func_(*parent_);
  }

  select_enumerator& operator++() {
    ++parent_;
    return *this;
  }

  operator bool() const {
    return parent_;
  }

private:
  T last_;
  enumerator<U>& parent_;
  F func_;
};

template<typename T, typename F>
class until_enumerator : public enumerator<T> {
public:
  until_enumerator(enumerator<T> &parent, F predicate) : parent_(parent), predicate_(predicate) {
  }

  const T& operator*() {
    return *parent_;
  }

  until_enumerator& operator++() {
    ++parent_;
    return *this;
  }

  operator bool() const {
    return parent_ && !predicate_(*parent_);
  }

private:
  enumerator<T>& parent_;
  F predicate_;
};

template<typename T, typename F>
class where_enumerator : public enumerator<T> {
public:
  where_enumerator(enumerator<T>& parent, F predicate) : parent_(parent), predicate_(predicate) {
  }

  const T& operator*() {
    return *parent_;
  }

  where_enumerator& operator++() {
    ++parent_;
    return *this;
  }

  operator bool() const {
    while (parent_ && !predicate_(*parent_))
      ++parent_;
    return parent_ && predicate_(*parent_);
  }

private:
  enumerator<T>& parent_;
  F predicate_;
};

template<typename T>
class take_enumerator : public enumerator<T> {
public:
  take_enumerator(enumerator<T>& parent, int count) : parent_(parent), count_(count) {
  }

  const T& operator*() {
    return *parent_;
  }

  take_enumerator& operator++() {
    ++parent_;
    --count_;
    return *this;
  }

  operator bool() const {
    return parent_ && count_ > 0;
  }


private:
  enumerator<T>& parent_;
  int count_;
};

} // namespace impl

template<typename Iter>
auto from(Iter begin, Iter end) {
  return impl::range_enumerator<typename std::iterator_traits<Iter>::value_type, Iter>(begin, end);
}

} // namespace linzq

#endif