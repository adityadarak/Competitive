#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif


void main_with_large_stack_space() {
  int n;
  std::cin >> n;
  std::vector<int> arr;
  arr.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    arr[child_index]=parent_index;
  }

  int maxh=0;
  std::vector<int>heights;
  heights.resize(n);
  for(int i=0;i<n;i++){
    heights[i]=0;
  }
  for(int vertex=0;vertex<n;vertex++){
    if (heights[vertex] != 0)
      continue;
    int height = 0;
    for (int i = vertex; i != -1; i = arr[i]) {
      if (heights[i] != 0) {
        height += heights[i];   
        break;
      }
      height++;
    }
    maxh = std::max(maxh, height);
    for (int i = vertex; i != -1; i = arr[i]) {
      if (heights[i] != 0)
        break;
      heights[i] = height--;
    }
  }
  std::cout<<maxh<<std::endl;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  main_with_large_stack_space();
  return 0;
}
