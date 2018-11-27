#include <stdio.h>
#include <stdlib.h>

#include <set>

#include <iostream>

int main()
{
  int size = 7;
  int counter = 1;
  std::set<int> zbior;

  printf("Maximum size of a 'set' is: %ld\n", zbior.max_size());
  std::cout << "Maximum size of a 'set' is: " << zbior.max_size() << std::endl;

  if(zbior.empty())
    printf("zbior jest pusty\n");
  else 
    printf("zbior nie jest pusty\n");
 
  if(zbior.begin() == zbior.end())
    printf("zbior jest pusty\n");
  else 
    printf("zbior nie jest pusty\n");

  while(zbior.size() < size)
  {
    int temp = rand() % size;
    if(zbior.insert(temp).second)
    {
      int dist = static_cast<int>(std::distance(zbior.begin(), zbior.end()));
      printf("%d. Number %d has been inserted. Distance: %d\n", counter, temp, dist);
      //printf("%d. Number %d has been inserted.\n", counter, *zbior.insert(temp).first); 
    }
    else
    {
      printf("%d. Number %d is just in set.\n", counter, temp);
      //printf("%d. Number %d is just in set.\n", counter, *zbior.insert(temp).first); 
    }
    counter++;
  }
  
  printf("Set is full !!!\n");

  for(std::set<int>::iterator it = zbior.begin(); it != zbior.end(); it++)
    printf("%d ", *it);
  printf("\n");

  return 0;
}
