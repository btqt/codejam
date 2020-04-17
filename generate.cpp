#include <bits/stdc++.h>

using namespace std;

#define MAX_BITSET 100

int n = 4;

void next_bit_string()
{
	bitset<MAX_BITSET> permutation;
	permutation.reset();

	auto print_permutation = [&](){for(int k = 0; k < n; ++k) cout << permutation[k];};
	print_permutation();
	cout << "\n";

	bool stop = false;

	while(!stop) {	
	    int i = n-1;
		for( ; i >= 0; --i) {
			if(permutation[i] == 1) {
				permutation[i] = 0;
			} else {
				permutation[i] = 1;
				print_permutation();
				cout << "\n";

				break;
			}
		}
		
		if(i == -1) {
			stop = true;
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	next_bit_string();

	return 0;
}



