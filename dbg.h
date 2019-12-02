#include <iostream>
#ifdef _DBG
#define DBG(x) std::cout<<"DEBUG LOG: "<<x<<std::endl;
#else
#define DBG(x)
#endif
