#ifndef RPN_HPP
#define RPN_HPP

#include <queue>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::queue;

class RPN
{
private:
  queue<int> numbers;
  queue<char> tokens;

public:
  RPN();
  RPN(const RPN &);
  RPN &operator=(const RPN &);

  void insert_number(int);
  void insert_token(char);

  int get_number();
  char get_token();

  void pop_token();
  void pop_number();

  size_t get_numbers_size();

  ~RPN();
};

#endif