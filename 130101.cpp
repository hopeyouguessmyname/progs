#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec(10);
  for(auto it = vec.begin(); it != vec.end(); it++)
    std::cout << *it << std::endl;

  return 0;
}
