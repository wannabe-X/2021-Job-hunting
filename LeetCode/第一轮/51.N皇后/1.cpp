#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void backtrack(vector<string> &, int);
bool isValid(vector<string>&, int, int);

vector<vector<string> > res;

// ��ʼ������
vector<vector<string> > solveNQueen(int n){
	vector<string> board(n,string(n,'X'));
	backtrack(board, 0);
	return res;
}

/* �Ƿ������ board[row][col] ���ûʺ� */
bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // ������Ƿ��лʺ����ͻ
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    // ������Ϸ��Ƿ��лʺ����ͻ
    for (int i = row - 1, j = col + 1;
            i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    // ������Ϸ��Ƿ��лʺ����ͻ
    for (int i = row - 1, j = col - 1;
            i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void PrintBoard(vector<string>& board){
	int row = board.size();
	int col = board[row].size();
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout << board[i][j];
		}
		cout<<endl;
	}
}

void backtrack(vector<string>& board, int row){
	if(row == board.size()){
		res.push_back(board);
		PrintBoard(board);
		return;
	}
	
	int n = board[row].size();
	for(int col=0; col<n; col++){
		if(!isValid(board,row,col)) continue;
		board[row][col] = 'Q';
		backtrack(board, row+1);
		board[row][col] = 'X';
	}
}


int main(void){
	solveNQueen(8);
	return 0;
}
