#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <ctime>
#include <deque>
#include <iostream>

using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::sort;

class PmergeMe
{

private:
  list<int> number_list;
  deque<int> number_deque;

  list<int> sorted_number_list;
  deque<int> sorted_number_deque;

public:
  PmergeMe();
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);

  size_t get_size();
  int get_number(size_t);

  // List
  void insert_list(int number);
  void merge_sort_list();

  // deque
  void insert_deque(int number);
  void merge_sort_deque();

  // merhe in sort

  void merge(int arr[], int l, int m, int r);
  void mergeSort(int arr[], int l, int r);

  ~PmergeMe();
};

#endif