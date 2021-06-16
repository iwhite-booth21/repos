#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
using namespace std;
#define V 5



void printArray(int** A, int Size)
{
    int i, j;
    for (i = 1; i <= Size; i++)
    {
        for (j = 1; j <= Size; j++)
        {
            cout << setw(10) << left << A[i][j];
        }
        cout << endl;
    }
}




void ReadAdjArr(int** A, int Size)
{
    int weight = { Size };
    int i, j;
    for (i = 1; i <= Size; i++) {
        A[i][i] = 0;
    }
    //define infinity to a high value
    const int inf = 5000;
    for (i = 1; i <= Size; i++)
    {
        for (j = 1; j <= Size; j++)
        {
            if (i != j) 
            { 
                A[i][j] = inf; 
                weight = inf;
            }
        }
    }
    cout << "Enter Graph Information: " << endl;
    // 0 for False, 1 for True
    bool isThereEdge;
    cout << "Enter a 0 or 1 depending on if there is a edge or not: " << endl;
    for (i = 1; i <= Size; i++)
    {
        for (j = 1; j <= Size; j++)
        {
            if (i != j)
            {
                cout << "Is there any edge from vertex "
                    << i << " to " << "vertex " << j << endl;
                cin >> isThereEdge;
                if (isThereEdge)
                {
                    cout << "Enter the weight from " << i
                        << " to " << j << ": " << endl;
                    cin >> A[i][j];
                    
                    int counter;
                    for (counter = 1; counter <= Size; counter++)
                    {
                        weight = A[i][j];

                    }
                    
                }
            }
        }
    }
    for (i = 1; i <= Size; i++) 
    {
        cout << weight << " ,";
    }



}










bool createsMST(int u, int v, vector<bool> inMST) {
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
    return true;
}
void printMinSpanningTree(int N, int **A) {
    int Size = sizeof(N);
    vector<bool> inMST(Size, false);
    inMST[0] = true;
    int edgeNo = 0, MSTcost = 0;
    while (edgeNo < Size - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++) {
                if (A[i][j] < min) {
                    if (createsMST(i, j, inMST)) {
                        min = A[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            cout << "Edge " << edgeNo++ << " : (" << a << " , " << b << " ) : cost = " << min << endl;
            MSTcost += min;
            inMST[b] = inMST[a] = true;
        }
    }
    cout << "Cost of Minimum spanning tree =" << MSTcost;
}
int main() {

    /*
    int cost[][V] = {
       { INT_MAX, 12, INT_MAX, 25, INT_MAX },
       { 12, INT_MAX, 11, 8, 12 },
       { INT_MAX, 11, INT_MAX, INT_MAX, 17 },
       { 25, 8, INT_MAX, INT_MAX, 15 },
       { INT_MAX, 12, 17, 15, INT_MAX },
    };
    */

    int **spanTree;
    int N;
    cout << "No. of Vertices: " << endl;
    cin >> N;
    int i;
    spanTree = new int*[N + 1];
    for (i=1;i<=N;i++) 
    {
        spanTree[i] = new int[N + 1];
            
    }

    ReadAdjArr(spanTree, N);

    cout << "The Minimum spanning tree for the given tree is :\n";
    printArray(spanTree,N);
    return 0;
}
