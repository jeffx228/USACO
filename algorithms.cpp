#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

int N = 0;

int M = 0;


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]

void merge(long long arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(long long arr[],int l,int r){
    if(l >= r){
        return; //returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}




bool simulate(long long cDistance, long long cArr [], long long s [], long long f[])
{
    int cInt = 0;
    int position = cArr[0];
    int copyArr[N];
    for (int i = 0; i < N; i++)
    {
        copyArr[i] = cArr[i];
    }
    for (int i = 1; i < N-1; i++)
    {
        position += cDistance;
        while (position > f[cInt])
        {
            cInt++;
        }
        if(position < s[cInt])
        {
            position =  s[cInt];
        }
        if (cDistance == 78)
        {
            cout<<"cDistance: "<< cDistance << endl;
            cout<< "Position " << position << endl;
        }
        

        if (position > copyArr[i+1] - cDistance)
        {
            return false;
        }
    }
    return true;

}

int main () 
{
    int answer = 1;
    string line;
    string word = "";
    ifstream myfile ("socdist.in");
    int n = 0;

    long long start [100000];
    long long finish [100000];

    if (myfile.is_open())
    {
        getline (myfile,line);

        istringstream ss(line);

        //reads the first two numbers inputted
        ss >> word;
        istringstream(word) >> N;
        ss >> word;
        istringstream(word) >> M;
        
        while (getline (myfile,line))
        {
            istringstream ss(line);
            ss >> word;
            istringstream(word) >> start[n];
            ss >> word;
            istringstream(word) >> finish[n];
            n++;
        }

        myfile.close();
    }

    else cout << "Unable to open file"; 

    long long begin [M];
    long long close [M];

    for (int i = 0; i < M; i++)
    {
        begin[i] = start[i];
        close[i] = finish[i];
    }

    mergeSort(begin,0,M-1);
    mergeSort(close,0,M-1);

    /*for (int i = 0; i < 3; i++)
    {
        cout << "Start: " << begin[i] << endl;
        cout << "End: " << close[i] << endl; 
    }*/

    long long cowArr [N];

    cowArr[0] = begin[0];

    for (int i = 1; i < N; i++)
    {
        cowArr[i] = close[M-1];
    }

    /*for (int i = 0; i < M; i++)
    {
        cout << "Start: " << begin[i] << endl;
        cout << "End: " << close[i] << endl;
    }*/

    //cout << "Start " << begin[0] << endl;

    //cout << "End " << close[M-1] << endl;
    

    long long totalDistance = close[M-1] - begin[0];

    //cout << totalDistance;


    long long currentDistance = totalDistance/(N-1);

    long long testingDistance = currentDistance + 1;

    long long sizes [M];

    long long distances [M];

    for (int i = 0; i < M-1; i++)
    {
        sizes[i] = close[i] - begin[i];
        distances[i] = begin[i+1] - close[i];
    }

    distances[M-1] = 0;
    sizes[M-1] = close[M-1] - begin[M-1];

    
    int i = 0;

    long long upper = testingDistance;

    long long lower = 1;

    cout << "testingdistance: " << testingDistance << endl;

    while (lower + 1 < upper)
    {   
        cout << "Hi" << endl; 
        if (!simulate(testingDistance, cowArr, begin, close))
        {
            upper = testingDistance;
        }
        else
        {
            lower = testingDistance;
        }
        testingDistance = (lower + upper)/2;
        cout << "lower: " << lower << endl;
        cout << "upper: " << upper << endl;
    }

    answer = lower;


    ofstream yourfile ("socdist.out");
    if (yourfile.is_open())
    {
        yourfile << answer;
    }
    yourfile.close();

}