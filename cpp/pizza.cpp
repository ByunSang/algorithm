#include <iostream>
using namespace std;

int main()
{
	int pizza = 41; // 101001(2)
					// 100000	32(10)
					// 001000	8(10)
					// 000001	1(10)
					
					// 001001	9(10)
					// 100001	33(10)
					// 101000	40(10)

					// 101001	41(10)

					
	for (int subset = pizza; subset; subset = ((subset-1) & pizza))
	{
		cout << subset<<endl;
	}

	return 0;
}
