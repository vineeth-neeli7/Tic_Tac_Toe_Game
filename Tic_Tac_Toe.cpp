#include<iostream>
#include<stdlib.h>
#include<fstream>

using namespace std;

class tic_tac_toe {
public:
    char a[3][3];  // Fixed from [2][2] to [3][3]

    void disp() {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i==0)
                    cout << a[i][j] << ends << "|";
                if(i==1)
                    cout << ends << a[i][j] << ends << "|";
                if(i==2) {
                    cout << endl;
                    cout << ends << a[i][j] << ends << "|";
                }
            }
            cout << endl;
        }
    }

    void ans(int player) {
        // Check win conditions
        if(a[0][0]==a[0][1] && a[0][0]==a[0][2]) goto WIN;
        if(a[1][0]==a[1][1] && a[1][0]==a[1][2]) goto WIN;
        if(a[2][0]==a[2][1] && a[2][0]==a[2][2]) goto WIN;
        if(a[0][0]==a[1][0] && a[0][0]==a[2][0]) goto WIN;
        if(a[0][1]==a[1][1] && a[0][1]==a[2][1]) goto WIN;
        if(a[0][2]==a[1][2] && a[0][2]==a[2][2]) goto WIN;
        if(a[0][0]==a[1][1] && a[0][0]==a[2][2]) goto WIN;
        if(a[0][2]==a[1][1] && a[0][2]==a[2][0]) goto WIN;
        return;

    WIN:
        cout << player << " hurry ! you won the match " << endl;

        // File logging the winner and board
        ofstream history("t_t_o_history.txt", ios::app);
        history << "Winner: Player " << player << "\n";
        history << "Final Board:\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                history << a[i][j] << " ";
            }
            history << "\n";
        }
        history << "--------------------------\n";
        history.close();

        exit(0);
    }
};

int main() {
    int a, b, f = 1, i, j;
    int player;
    tic_tac_toe tto;
    fstream fp;
    fp.open("t_t_o.txt", ios::out);  // This isn't used further, retained as per structure

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> tto.a[i][j];
        }
    }

    fp.close();

    fstream fs;
    fs.open("t_t_o.txt", ios::in | ios::app);

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(i == 0)
                cout << tto.a[i][j] << ends << "|";
            if(i == 1) {
                cout << endl;
                cout << "|" << ends << tto.a[i][j] << ends << "|";
            }
            if(i == 2) {
                cout << endl;
                cout << "|" << ends << tto.a[i][j] << ends << "|";
            }
        }
    }

    fstream fk;
    fk.open("t_t_o.txt", ios::out);  // unused, kept for structure

    while(f != 0) {
        cout << "enter the turn" << endl;
        cin >> player;

        if(player == 1) {
            cout << "select the place u want to put \"X\" player 1" << endl;
            cin >> a >> b;
            i = a;
            j = b;
            cout << "enter \"x\" " << endl;
            cin >> tto.a[i][j];
            tto.disp();
            tto.ans(1);
        }

        if(player == 2) {
            cout << "select the place u want to put \"O\" player 2" << endl;
            cin >> a >> b;
            i = a;
            j = b;
            cout << "enter \"x\" " << endl;
            cin >> tto.a[i][j];
            tto.disp();
            tto.ans(2);
        }
    }

    fp.close();
    fs.close();
}
