#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void print_vector(vi& v)
{
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n";
}

void print_vector2D(vvi& v)
{
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";

            if(j == v[i].size()-1) 
                cout << endl;
        }
    }
}

void try_next_bit_string(int i) 
{
    int n = 5;
    vector<int> v(5);
    for(int j = 0; j <= 1; ++j) {
        v[i] = j;
        if(i == n-1) {
            print_vector(v);
            cout << "\n";
            return;
        } else {
            try_next_bit_string(i+1);
        }
    }
}

int n = 5;
int col[100];
int main_diag[2*100+1];
int anti_diag[2*100+1];
vi tmp(n, 0);
vvi board(n, tmp);

int solution_cnt = 0;

void n_queens(int i)
{
    for(int j = 0; j < n; ++j) {
        if(col[j] == 0 && anti_diag[i+j] == 0 && main_diag[i-j+n-1] == 0) {
            board[i][j] = 1;
            col[j] = 1;
            anti_diag[i+j] = 1;
            main_diag[i-j+n-1] = 1;
            if(i == n-1) {                
                cout << "Loi giai " << solution_cnt++ << ":\n";
                print_vector2D(board);
            } else n_queens(i+1);

            board[i][j] = 0;
            col[j] = 0;
            anti_diag[i+j] = 0;
            main_diag[i-j+n-1] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    // try_next_bit_string(0);
    n_queens(0);

    return 0;
}



