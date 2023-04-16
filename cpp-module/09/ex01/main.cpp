#include "RPN.hpp"

void exitWithMessage()
{
  cerr << "Error" << endl;
  exit(1);
}

int main(int ac, char **args)
{
  RPN rpn;

  if (ac != 2)
    return 0;

  for (int i = 0; args[1][i]; i++)
  {
    char arg = args[1][i];

    if (arg == ' ')
      continue;
    else if (isdigit(arg))
      rpn.insert_number(arg - 48);
    else if (arg == '+' || arg == '-' || arg == '*' || arg == '/')
      rpn.insert_token(arg);
    else
      exitWithMessage();
  }

  int result = rpn.get_number();
  size_t len = rpn.get_numbers_size();

  for (size_t i = 0; i < len; i++)
  {
    char c = rpn.get_token();
    int value = rpn.get_number();

    if (c == '+')
      result += value;
    else if (c == '-')
      result -= value;
    else if (c == '*')
      result *= value;
    else if (c == '/')
    {
      if (value == 0)
      {
        cout << "Wrong arguments !" << endl;
        exit(1);
      }
      result /= value;
    }
  }
  cout << result << endl;
}