#include "RPN.hpp"

RPN::RPN(){};

RPN::RPN(const RPN &rpn)
{
  *this = rpn;
}

RPN &RPN::operator=(const RPN &rpn)
{
  (void)rpn;
  return *this;
};

void RPN::insert_number(int number)
{
  this->numbers.push(number);
}

void RPN::insert_token(char token)
{
  this->tokens.push(token);
}

size_t RPN::get_numbers_size()
{
  return this->numbers.size();
}

int RPN::get_number()
{
  int value = this->numbers.front();
  this->numbers.pop();
  return value;
}

char RPN::get_token()
{
  char value = this->tokens.front();
  this->tokens.pop();
  return value;
}

void RPN::pop_number()
{
  this->numbers.pop();
}

void RPN::pop_token()
{
  this->tokens.pop();
}

RPN::~RPN() {}