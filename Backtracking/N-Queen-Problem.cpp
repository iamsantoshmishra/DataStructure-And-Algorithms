/*
 * N-Queen-Problem.cpp
 *
 *  Created on: 13-Feb-2020
 *      Author: Santosh Kumar Mishra
 *      E-mail: 93mishra@gmail.com
 */


#include <iostream>
#include <bits/stdc++.h>
#define N 4

using namespace std;

void printSol(bool sol[N][N]){
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout<<sol[i][j]<<" ";
		}
		cout<<"\n";
	}
}

bool isSafe(bool sol[N][N], int row, int col){
	  int i,j;
    //boundary case
    if(row >= N || col >= N || sol[row][col] == true){
			return false;
		}
		//check for row
		for(int i=0;i<=row;++i){
			if(sol[i][col] == true){
				return false;
			}
		}
		//check for col
		for(int i=0;i<=col;++i){
			if(sol[row][i] == true){
				return false;
			}
		}
		//check for left diagonal
		i = row, j = col;
		while(i>=0 && j>=0){
			if(sol[i][j] == true){
				return false;
			}
			--i,--j;
		}
		//check for right diagonal
		i = row, j = col;
		while(i<N && j<N){
			if(sol[i][j] == true){
				return false;
			}
			++i,++j;
		}
	return true;
}

bool nQeenUtil(bool sol[N][N], int row){
	if (row >= N){
		return true;
	}

	for(int col=0; col<N; ++col){
		if(isSafe(sol,row,col) == true){
			sol[row][col] = true;

			if(nQeenUtil(sol,row+1) == true){
				return true;
			}else{
				sol[row][col] = false;
			}
		}
	}
	return false;
}

void nQueen(){

	bool sol[N][N] = { { false, false, false, false },
					   { false, false, false, false },
					   { false, false, false, false },
					   { false, false, false, false } };

   if(nQeenUtil(sol, 0) == true){
		 printSol(sol);
	 } else {
		 cout<<"Solution does not exist";
	 }
}

int main() {
  nQueen();
  return 0;
}
