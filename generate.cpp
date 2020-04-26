#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int>& v)
{
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n";
}

void next_bit_string()
{
    #define MAX_BITSET 100

    int n = 4;

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

void next_combination()
{
    vector<int> v;
    int n = 4;
    int k = 3;

    for(int i = 0; i < k; ++i)
        v.push_back(i);

    print_vector(v);

    bool stop = false;

    while(!stop) {
        int i = k-1;
        while(v[i] == n-k+i) {
            --i;
        }

        if(i >= 0) {
            v[i] += 1;

            for(int j = i+1; j < k; ++j) {
                v[j] = v[i] + j - i;
            }

            print_vector(v);
        } else stop = true;
    }
}

void next_permutation_using_std()
{
    vector<int> v;

    int n = 5;

    for(int i = 0; i < n; ++i)
        v.push_back(i);

    do {
        print_vector(v);
    } while(std::next_permutation(v.begin(), v.end()));
}

void next_permutation_manual()
{
	vector<int> v;
	int n = 5;
	for(int i = 0; i < n; ++i)
		v.push_back(i);

	print_vector(v);

	bool stop = false;
	while(!stop) {
		int i = n-2;
		while(v[i] >= v[i+1]) i--;
	}
}

int main(int argc, char const *argv[])
{
    /* code */
    // next_bit_string();
    next_combination();

    // next_permutation_using_std();

    return 0;
}



