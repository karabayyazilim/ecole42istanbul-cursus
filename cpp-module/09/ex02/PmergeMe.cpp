#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &merge)
{
  *this = merge;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &merge)
{
  (void)merge;
  return *this;
}

void PmergeMe::insert_list(int number)
{
  this->number_list.push_back(number);
}

void PmergeMe::insert_deque(int number)
{
  this->number_deque.push_back(number);
}

void PmergeMe::merge_sort_list()
{
  size_t len = this->get_size();
  list<int>::iterator it = this->number_list.begin();

  for (size_t i = 0; i < len; i++)
  {
    this->sorted_number_list.push_back(*it);
    mergeSort(&(*this->sorted_number_list.begin()), 0, this->sorted_number_list.size() - 1);
    it++;
  }
}

void PmergeMe::merge_sort_deque()
{
  size_t len = this->get_size();
  for (size_t i = 0; i < len; i++)
  {
    int number = this->number_deque[i];
    this->sorted_number_deque.push_back(number);
    mergeSort(&this->sorted_number_deque.begin()[0], 0, this->sorted_number_deque.size() - 1);
  }
}

void PmergeMe::merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void PmergeMe::mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

size_t PmergeMe::get_size()
{
  return this->number_deque.size();
}

int PmergeMe::get_number(size_t i)
{
  return this->sorted_number_deque[i];
}

PmergeMe::~PmergeMe() {}