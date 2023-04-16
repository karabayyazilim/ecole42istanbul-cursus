#include "PmergeMe.hpp"

bool check_args(char **args)
{
  int i = 1;

  while (args[i])
  {
    int j = 0;
    while (args[i][j])
    {
      if (args[i][j] == '+')
      {
        if (!isdigit(args[i][j + 1]))
          return false;
      }
      else
      {
        if (!isdigit(args[i][j]))
          return false;
      }
      j++;
    }
    i++;
  }
  return true;
}

int main(int ac, char **args)
{

  PmergeMe merge;

  if (ac == 1)
    return 0;

  if (!check_args(args))
  {
    cout << "Wrong arguments !" << endl;
    exit(1);
  }

  clock_t start_list = clock();
  for (int i = 1; i < ac; i++)
    merge.insert_list(atoi(args[i]));
  merge.merge_sort_list();
  clock_t end_list = clock();

  clock_t start_deque = clock();
  for (int i = 1; i < ac; i++)
    merge.insert_deque(atoi(args[i]));
  merge.merge_sort_deque();
  clock_t end_deque = clock();

  cout << "Before: ";
  for (int i = 1; args[i]; i++)
    cout << args[i] << " ";
  cout << endl;

  size_t len = merge.get_size();
  cout << "After: ";
  for (size_t i = 0; i < len; i++)
    cout << merge.get_number(i) << " ";
  cout << endl;

  cout << "Time to process a range of " << len << " elements with list : " << (float)(end_list - start_list) / CLOCKS_PER_SEC * 1000 << " us" << endl;
  cout << "Time to process a range of " << len << " elements with deque : " << (float)(end_deque - start_deque) / CLOCKS_PER_SEC * 1000 << " us" << endl;
}