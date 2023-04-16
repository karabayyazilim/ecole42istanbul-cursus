#include "BitcoinExchange.hpp"

vector<string> split(string str, const string &delimeter)
{
  size_t index;
  vector<string> result;

  while (str.size())
  {
    index = str.find(delimeter);
    if (index != string::npos)
    {
      result.push_back(str.substr(0, index));
      str = str.substr(index + delimeter.size());
      if (str.size() == 0)
        result.push_back(str);
    }
    else
    {
      result.push_back(str);
      str = "";
    }
  }
  return result;
}

bool is_valid_date(const vector<string> &date_arr)
{
  if (date_arr.size() != 3)
    return false;

  if (date_arr[0].size() < 4)
    return false;

  if (date_arr[1].size() < 2)
    return false;

  if (date_arr[2].size() < 2)
    return false;

  int year = stoi(date_arr[0]);
  int month = stoi(date_arr[1]);
  int day = stoi(date_arr[2]);

  if (year < 1 || year > 9999)
    return false;

  if (month < 1 || month > 12)
    return false;

  if (day < 1 || day > 31)
    return false;

  if (month == 2)
  {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
      if (day > 29)
        return false;
    }
    else
    {
      if (day > 28)
        return false;
    }
  }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  return true;
}

int main(int ac, char **av)
{
  if (ac != 2)
  {
    cout << "Require only 2 arguments" << endl;
    exit(1);
  }

  Bitcoin btc;

  btc.parse_csv("data.csv");
  btc.start(av[1]);
}