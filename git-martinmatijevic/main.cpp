#include <iostream>
#include <vector>

using namespace std;

int main()
{
   int x =0;
   int y(0);
   int z{0};
   vector<int> vec{10, 3};

   for(auto x : vec)
         cout << x << ",";
    cout << "\n";
    std::cout << "Hello world!\n";

  return 0;
}
