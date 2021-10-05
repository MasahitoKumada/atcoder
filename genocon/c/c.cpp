#include<iostream>
#include<string>

using namespace std;


// 参考: http://biology.love/?p=730

const int INF = 1000;

//function for compare two letter.
int s(char x, char y, int match, int mismatch){
    if(x == y) return match;
    else return mismatch;
}

int show(int sizex, int sizey, int* table){
    for(int j = 0; j < sizey + 1; j++){
        for(int i = 0; i < sizex + 1; i++){
            cout << table[j*(sizex+1)+i] << " ";
        }
        cout << endl;
    }
}

int main(void){
 
    string seqX, seqY;
    cin >> seqX >> seqY;

    //begin: define variables and DP table and TraceBack table.
    int sizex = seqX.length(); 
    int sizey = seqY.length();

    int match = 1; 
    int mismatch = -3; 
    int d = -5;
    int e = 1;

    int* dptM = (int*)malloc(sizeof(int) * (sizex + 1) * (sizey + 1));
    int* dptX = (int*)malloc(sizeof(int) * (sizex + 1) * (sizey + 1));
    int* dptY = (int*)malloc(sizeof(int) * (sizex + 1) * (sizey + 1));
    int* tbtM = (int*)malloc(sizeof(int) * (sizex + 1) * (sizey + 1));
    int* tbtX = (int*)malloc(sizeof(int) * (sizex + 1) * (sizey + 1));
    int* tbtY = (int*)malloc(sizeof(int) * (sizex + 1) * (sizey + 1));
    //end: define variables and DP table and TraceBack table.


    //begin: initialize
    for(int i = 1; i < sizex + 1; i++){
        dptM[i] = -INF;
        dptX[i] = -d-(i-1)*e;
        dptY[i] = -INF;
        tbtX[i] = 1;
    }
    for(int j = 1; j < sizey+1; j++){
        dptM[j * (sizex+1)] = -INF;
        dptX[j * (sizex+1)] = -INF;
        dptY[j * (sizex+1)] = -d-(j-1)*e;
        tbtY[j*(sizex+1)] = 2;
    }
    dptM[0] = 0;
    dptX[0] = -INF; 
    dptY[0] = -INF;

    tbtM[0] = -1; 
    tbtX[0] = -1; 
    tbtY[0] = -1;
    //end : initialize 


    //begin: fill table
    for(int i = 1; i < sizex+1; i++){
        for(int j = 1; j < sizey+1; j++){
            //begin: M(i, j)
            int candidates[3] = {-INF};
            candidates[0] = dptM[(j-1)*(sizex+1)+i-1] + s(seqX[i-1], seqY[j-1], match, mismatch);
            candidates[1] = dptX[(j-1)*(sizex+1)+i-1] + s(seqX[i-1], seqY[j-1], match, mismatch);
            candidates[2] = dptY[(j-1)*(sizex+1)+i-1] + s(seqX[i-1], seqY[j-1], match, mismatch);
            int biggest = candidates[0];
            int ori = 0;
            for(int i = 1; i < 3; i++){
                if(candidates[i] > biggest){
                    biggest = candidates[i];
                    ori = i;
                }
            }
            dptM[j*(sizex+1)+i] = biggest;
            tbtM[j*(sizex+1)+i] = ori;
            //end: M(i,j)

            //begin: X(i, j)
            candidates[0] = -INF;
            candidates[1] = -INF;
            candidates[0] = dptM[j*(sizex+1)+i-1]-d;
            candidates[1] = dptX[j*(sizex+1)+i-1]-e;
            ori = 0;
            if(candidates[1] > candidates[0]) ori = 1;
            dptX[j*(sizex+1)+i] = candidates[ori];
            tbtX[j*(sizex+1)+i] = ori;
            //end: X(i, j)

            //begin: Y(i, j)
            candidates[0] = -INF;
            candidates[2] = -INF;
            candidates[0] = dptM[(j-1)*(sizex+1)+i]-d;
            candidates[2] = dptY[(j-1)*(sizex+1)+i]-e;
            ori = 0;
            if(candidates[2] > candidates[0]) ori = 2;
            dptY[j*(sizex+1)+i] = candidates[ori];
            tbtY[j*(sizex+1)+i] = ori;
            //end: Y(i, j)
        }
    }
    //end: fill table

    //begin traceback
    string ansX;
    string ansY;
    string hy ="-";
    int final[3] = {0};
    final[0] = dptM[(sizey+1)*(sizex+1)-1];
    final[1] = dptX[(sizey+1)*(sizex+1)-1];
    final[2] = dptY[(sizey+1)*(sizex+1)-1];
    int ori = 0;
    for(int i = 1; i < 3; i++){
        if(final[i] > final[ori]) ori = i;
    }

    int curr = ori;
    int i = sizex-1; 
    int j = sizey-1;
    int cnt = 0;
    while(curr != -1 && (i >= 0 || j >= 0)){
        if(curr == 0){
            ansX.insert(0, seqX, i, 1);
            ansY.insert(0, seqY, j, 1);
            curr = tbtM[(j+1)*(sizex+1)+(i+1)];
            i--; j--;
        }
        else if(curr == 1){
            ansX.insert(0, seqX, i, 1);
            ansY.insert(0, hy);
            curr = tbtX[(j+1)*(sizex+1)+(i+1)];
            i--;
        }
        else if(curr == 2){
            ansX.insert(0, hy);
            ansY.insert(0, seqY, j, 1);
            curr = tbtY[(j+1)*(sizex+1)+(i+1)];
            j--;
        }
        cnt++;
    }

    int p = 400; //num of letter to show in one line
    for(int k = 0; k*p < cnt; k++){
        for(int l = 0; l < p; l++){
            if(ansX[k*p+l] == 0) break;
            cout << ansX[k*p+l];
        }
        cout << endl;

        for(int l = 0; l < p; l++){
            if(ansY[k*p+l] == 0) break;
            cout << ansY[k*p+l];
        }
        cout << endl;
    }
    //end traceback
    return 0;
}