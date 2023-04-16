#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(){};

Bitcoin::Bitcoin(const Bitcoin &btc) { *this = btc; };

Bitcoin Bitcoin::operator=(const Bitcoin &btc)
{
  (void)btc;
  return *this;
}

template <typename T>
void Bitcoin::calculate(const vector<string> date_arr, T number)
{
  if (number < 0)
    throw invalid_argument("stoi");
  if (number > 1000)
    throw out_of_range("stoi");

  string merge_date = date_arr[0] + date_arr[1] + date_arr[2];
  for (size_t i = 0; i < date_num_arr.size(); i++)
  {
    if (date_num_arr[i] - (stoi(merge_date)) >= 0)
    {
      cout << date_arr[0] << "-" << date_arr[1] << "-" << date_arr[2] << " => ";
      if (value_arr[i].find(".") != string::npos)
        cout << number * stof(value_arr[i]) << endl;
      else
        cout << number * stoi(value_arr[i]) << endl;
      return;
    }
  }

  int i = value_arr.size() - 1;

  cout << date_arr[0] << "-" << date_arr[1] << "-" << date_arr[2] << " => ";
  if (value_arr[i].find(".") != string::npos)
    cout << number * stof(value_arr[i]) << endl;
  else
    cout << number * stoi(value_arr[i]) << endl;
}

void Bitcoin::parse_csv(const string &file_name)
{
  ifstream file(file_name);
  if (!file.is_open())
  {
    cout << "Invalid file or require permissions for data.csv" << endl;
    exit(1);
  }

  string date;
  string line;
  string num_str;
  vector<string> split_line;

  while (getline(file, line))
  {
    if (!isdigit(line[0]))
      continue;

    split_line = split(line, ",");
    date = split_line[0];
    for (size_t i = 0; i < date.length(); ++i)
      if (isdigit(date[i]))
        num_str += date[i];

    date_num_arr.push_back(stoi(num_str));
    value_arr.push_back(split_line[1]);
    num_str.clear();
  }
}

void Bitcoin::start(const string &file_name)
{
  ifstream file(file_name);
  if (!file.is_open())
  {
    cout << "Invalid file or require permissions for input.txt" << endl;
    exit(1);
  }

  string line;
  int i_number;
  float f_number;
  vector<string> split_line;
  vector<string> split_date;

  while (getline(file, line))
  {
    try
    {
      if (!isdigit(line[0]))
        continue;

      split_line = split(line, "|");
      split_date = split(split_line[0], "-");

      if (!is_valid_date(split_date))
        throw invalid_argument("date");

      if (split_line.size() != 2)
        throw invalid_argument("stoi");

      if (split_line[1].find(".") != string::npos)
      {
        f_number = stof(split_line[1]);
        calculate<float>(split_date, f_number);
      }
      else
      {
        i_number = stoi(split_line[1]);
        calculate<int>(split_date, i_number);
      }
    }
    catch (const invalid_argument &e)
    {
      if (!strcmp(e.what(), "stoi"))
        cout << "Error: not a positive number." << endl;
      else if (!strcmp(e.what(), "date"))
        cout << "Error: bad input => " << split_line[0] << endl;
    }
    catch (const out_of_range &e)
    {
      cout << "Error: too large a number." << endl;
    }
  }
}

Bitcoin::~Bitcoin(){};