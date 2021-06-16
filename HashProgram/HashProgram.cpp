/*
C++ Program developed by Dr Alak
Hashing using separate chaining
*/
#include <iostream>
#include <climits>
#include <stdio.h>
#include <list>
using namespace std;












class Hash
{
    int BUCKET;    // No. of buckets 

    // Pointer to an array containing buckets 
    list<int>* table;
public:
    Hash(int V);  // Constructor 

    // inserts a key into hash table 
    void insertItem(int x, char y, int z);

    // deletes a key from hash table 
    void deleteItem(int key);

    // hash function to map values to key 
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void displayHash();






private:
    // Rehash Function

    int Rehash(int key, char operationType, int j, int m)
    {
        int C1, C2;
        C1 = 1;
        C2 = 2;
        int x;
        int g;
        int h_k;
        h_k = key % m;
        switch (operationType)
        {
        case 'L':
            g = 1;
            break;

        case 'Q':
            g = C1 + C2 * j;
            break;

        case 'D':
            g = h2(key);
            break;

        default:
            cout << "Not a valid method" << endl;
            exit(0);
        }
        x = (h_k + j * g) % m;  // m = N
        return x;
    }

    int h2(int k)
    {
        return  (10 - (k % 10));
    }
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key, char operationType, int m)
{
    int index = hashFunction(key);
    if (operationType == 'S')
    {
        table[index].push_back(key);
    }
    else 
    {
        int j = 1;
        while (table[index] == INT_MAX) 
        {
            index = Rehash(key, operationType, j, m);
            j++;
        }
        table[index].push_back(key);
    }
   
    
}

void Hash::deleteItem(int key)
{
    // get the hash index of key 
    int index = hashFunction(key);

    // find the key in (inex)th list 
    list <int> ::iterator i;
    for (i = table[index].begin();
        i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it 
    if (i != table[index].end())
        table[index].erase(i);
}

// function to display hash table 
void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
// Driver program  
int main()
{
    // array that contains keys to be mapped 
    //int a[] = {15, 11, 27, 8, 12}; 
    //int n = sizeof(a)/sizeof(a[0]); 
    
    char probeType;
    cout << "Probe type: D - Double Hashing| Q - Quadratic| L - Linear " << endl;
    cin >> probeType;
    int key;
    int m;
    cout << "Enter number of keys to be inserted: ";
    cin >> m;
    // insert the keys into the hash table
    int N;
    cout << "Enter hash table size: ";
    cin >> N;
    Hash h(N);
    for (int i = 1; i <= m; i++)
    {
        cout << "Enter the key to be inserted: ";
        cin >> key;
        h.insertItem(key, probeType,N);
    }
    h.displayHash();
    // delete a key from the hash table
    cout << "Enter the key to be deleted: ";
    cin >> key;
    h.deleteItem(key);

    // display the Hash table 
    h.displayHash();

    



    return 0;
}

/*
  Enter number of keys to be inserted: 5
Enter hash table size: 7
Enter the key to be inserted: 50
Enter the key to be inserted: 700
Enter the key to be inserted: 76
Enter the key to be inserted: 85
Enter the key to be inserted: 92
0 --> 700
1 --> 50 --> 85 --> 92
2
3
4
5
6 --> 76
Enter the key to be deleted: 85
0 --> 700
1 --> 50 --> 92
2
3
4
5
6 --> 76
*/
