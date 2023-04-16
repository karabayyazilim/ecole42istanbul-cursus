#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>
#include <stdexcept>

// Container
using std::vector;
using std::deque;

// Console
using std::cout;
using std::endl;

// Read
using std::getline;
using std::ifstream;

// Errors
using std::invalid_argument;
using std::out_of_range;

// Utils
using std::stof;
using std::strcmp;
using std::string;

class Bitcoin
{
private:
  vector<int> date_num_arr;
  vector<string> value_arr;

public:
  Bitcoin();
  Bitcoin(const Bitcoin &);
  Bitcoin operator=(const Bitcoin &);

  void parse_csv(const string &);
  void start(const string &);

  template <typename T>
  void calculate(const vector<string>, T);

  ~Bitcoin();
};

bool is_valid_date(const vector<string> &);
vector<string> split(string, const string &);

#endif