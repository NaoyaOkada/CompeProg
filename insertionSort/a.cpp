#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

void printDataArray(int dataNum, int dataArray[]) {
    for (size_t i = 0; i < dataNum; i++)
    {
        cout << dataArray[i];
        if(i != dataNum -1)  cout << " ";
    }
}

int main() {
    int dataArray[MAX_SIZE];

    int dataNum;
    cin >> dataNum;

    for (size_t i = 0; i < dataNum; i++)
    {
        cin >> dataArray[i];
    }

    printDataArray(dataNum, dataArray);
    cout << endl;

    for (size_t i = 1; i < dataNum; i++)
    {
        int v = dataArray[i];
        int j = i - 1;

        while(j >= 0 && dataArray[j] > v){
            dataArray[j+1] = dataArray[j];
            j--;
        }
        dataArray[j+1] = v;
        printDataArray(dataNum, dataArray);
        cout << endl;
    }    
    return 0;
}

