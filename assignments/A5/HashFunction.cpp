#include <iostream>
#include <fstream>
#include <algorithm> // std::min_element, std::max_element
#include <math.h>    /* pow */

using namespace std;

static const int MAX_INPUT_SIZE = 1000;

// ================== FREQTABLE CLASS: START ================== //
class FreqTable
{
  public:
    int values[MAX_INPUT_SIZE];
    int frequencies[MAX_INPUT_SIZE];
    int numEntries;

    FreqTable();
    void add(int valueToAdd);
    void printTable();
    friend ostream &operator<<(ostream &os, const FreqTable &ft);
};

FreqTable::FreqTable()
{
    numEntries = 0;
}

void FreqTable::add(int valueToAdd)
{
    bool added = false;

    for (int i = 0; i < numEntries; i++)
    {
        if (values[i] == valueToAdd)
        {
            frequencies[i]++;
            added = true;
            break;
        }
    }

    if (!added)
    {
        values[numEntries] = valueToAdd;
        frequencies[numEntries] = 1;
        numEntries++;
    }
}

void FreqTable::printTable()
{
    cout << "\nFREQUENCY TABLE\n"
         << "value | frequency\n\n";
    for (int i = 0; i < numEntries; i++)
    {
        cout << values[i] << " " << frequencies[i] << endl;
    }
}

ostream &operator<<(ostream &os, const FreqTable &ft)
{
    for (int i = 0; i < ft.numEntries; i++)
    {
        os << ft.values[i] << " " << ft.frequencies[i] << endl;
    }

    return os;
}

// ================== FREQTABLE CLASS: END ================== //

int hashFunc1(string inputKey)
{
    int p = 0;
    int sum = 0;

    sum = (int)inputKey[0] + (int)inputKey[1] + (int)inputKey[2] +(int)inputKey[3]+ (int)inputKey[4] +(int)inputKey[5] + (int)inputKey[6] + (int)inputKey[7] + (int)inputKey[8];

    p = sum % MAX_INPUT_SIZE;

    return p;
}

int hashFunc2(string inputKey)
{
    int p = 0;
    int sum = 0;

    for (int i = 0; i < inputKey.size(); i++)
    {
        sum = (9 * sum) + (int)inputKey[i];
    }

    sum = abs(sum);
    p = sum % MAX_INPUT_SIZE;

    return p;
}

// =================== MAIN DRIVER: START =================== //
int main()
{
    string tempKey = "";
    int gtOne = 0;

    FreqTable fq;

    ifstream inFile("IndexingKeys.txt");
    ofstream outFile("HashPlot1.txt");

    // TESTING FUNCTION 1
    while(getline(inFile, tempKey))
    {
        fq.add(hashFunc1(tempKey));
    }

    for(int i = 0; i < fq.numEntries; i++)
    {
        if(fq.frequencies[i] > 1)
        {
            gtOne++;
        }
    }

    cout << "\n ===== HASH FUNCTION ===== \n"
         << "Number of Indexes: " << fq.numEntries << endl
         << "Index Range: " << *min_element(fq.values, fq.values + fq.numEntries) << " - " << *max_element(fq.values, fq.values + fq.numEntries) << endl
         << "Largest Frequency: " << *max_element(fq.frequencies, fq.frequencies + fq.numEntries) << endl
         << "# many-to-1 maps: " << gtOne << endl << endl;

    outFile << fq;
    
    inFile.close();
    outFile.close();

    return 0;
}
// =================== MAIN DRIVER: START =================== //