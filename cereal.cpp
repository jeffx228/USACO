#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int N = 0;

int M = 0;


int main () 
{
    string line;
    string word = "";
    ifstream myfile ("cereal.in");
    int n = 0;

    int pref1 [100000];
    int pref2 [100000];

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
            istringstream(word) >> pref1[n];
            ss >> word;
            istringstream(word) >> pref2[n];
            n++;
        }

        myfile.close();
    }

    else cout << "Unable to open file"; 

    int answer [N];

    int j = 0;
    int count = 0;

    int takers [M];

    int ctype;

    int taken;

    for (int i = 0; i < M; i++)
    {
        takers[i] = 0;
    }

    for (int i = N-1; i >= 0; i--)
    {
        j = i;
        while (true)
        {
            ctype = pref1[j];
            taken = takers[ctype-1];
            if (taken == 0)
            {
                takers[ctype-1] = j+1;
                count++;
                break;
            }
            else if (takers[pref2[taken]-1] < taken && takers[pref2[taken]-1] != 0)
            {
                takers[ctype-1] = j+1;
                break;
            }
            else
            {
                j = takers[pref2[taken]-1];
                takers[ctype-1] = j+1;
                count++;
            }
            
        }
    }

    ofstream yourfile ("cereal.out");
    if (yourfile.is_open())
    {
        for (int i = 0; i < N; i++)
        {
            yourfile << answer[i] << endl;
        }
        
    }
    yourfile.close();

}