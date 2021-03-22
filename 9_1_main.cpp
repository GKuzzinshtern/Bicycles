#include <iostream>
#include "vector.h"

static int counter{};

class test {
public:
  test() : pointer{new int(counter)} {++counter;}
  test(int a) : pointer{new int{a}}{}
  int* pointer{};
private:


};


int main()
{
//  vector<int> v1(1);

  vector<int> v2{1,2,3,4,5};
//  vector<int> v3{v2};
  vector<int> v4(&v2[1], &v2[3]);

  test t_value(125);
  vector<test> t1(5);
  for (size_t index = 0; index < t1.size(); ++index) {
  std::cout << *(t1[index].pointer) << ", ";
  }
  std::cout << "size: " << t1.size() << " capacity: " << t1.capacity();
  std::cout << std::endl;

//  vector<test> t2{2};
//  for (size_t index = 0; index < v2.size(); ++index) {
//  std::cout << v2[index] << ", ";
//  }
//  std::cout << "size: " << v2.size() << " capacity: " << v2.capacity();
//  std::cout << std::endl;

  t1.emplace_back(3);
  for (size_t index = 0; index < t1.size(); ++index) {
  std::cout << *(t1[index].pointer) << ", ";
  }
  std::cout << "size: " << t1.size() << " capacity: " << t1.capacity();
  std::cout << std::endl;

  t1.insert(&t1[3], t_value);
  for (size_t index = 0; index < t1.size(); ++index) {
  std::cout << *(t1[index].pointer) << ", ";
  }
  std::cout << "size: " << t1.size() << " capacity: " << t1.capacity();
  std::cout << std::endl;

  t1.erase(3);
  for (size_t index = 0; index < t1.size(); ++index) {
  std::cout << *(t1[index].pointer) << ", ";
  }
  std::cout << "size: " << t1.size() << " capacity: " << t1.capacity();
  std::cout << std::endl;

  t1.erase(&t1[4]);
  for (size_t index = 0; index < t1.size(); ++index) {
  std::cout << *(t1[index].pointer) << ", ";
  }
  std::cout << "size: " << t1.size() << " capacity: " << t1.capacity();
  std::cout << std::endl;

  t1.erase(t1.begin(), &t1[2]);
  for (size_t index = 0; index < t1.size(); ++index) {
  std::cout << *(t1[index].pointer) << ", ";
  }
  std::cout << "size: " << t1.size() << " capacity: " << t1.capacity();
  std::cout << std::endl;

  t1.erase(&t1[1], t1.end());
  for (size_t index = 0; index < t1.size(); ++index) {
  std::cout << *(t1[index].pointer) << ", ";
  }
  std::cout << "size: " << t1.size() << " capacity: " << t1.capacity();
  std::cout << std::endl;

  t1.reserve(50);
  for (size_t index = 0; index < t1.size(); ++index) {
  std::cout << *(t1[index].pointer) << ", ";
  }
  std::cout << "size: " << t1.size() << " capacity: " << t1.capacity();
  std::cout << std::endl;

  return 0;
}
