#include <iostream>
#include <list>

void f( std::list<int> food, std::list<int> bara )
{
  char *del = new char[10];
  std::list<int>::const_iterator it;
  for (it = food.begin(); it != food.end(); ++it)
  {
    bara.push_back( *it );
  }

  delete [] del;
  del[3] = 0;
}