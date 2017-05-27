#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class g{
private:
    char* vertex; // star means array
    int **edges;
    int numVerticies; //basically count
    int maxVerticies;
public:
    g(int);
    ~g();
    g(const g&);
    g& operator=(const g&);
    void addVertex(char x);
    bool checkV(char x);//returns true if x is not in vertex array
    bool removeVertex(const char&);
    int getIndex(const char &);
    void addEdge(const char& start, const char& stop, int w = 1);
    void removeEdge(const char& start, const char& stop);
    bool isPath(const char& start, const char&stop);
    void print();
    vector<int> getNeighbors(int i);
};

int main()
{
    g s(3);
    char a = 'a';
    char b = 'b';
    char c = 'c';
    s.addVertex(a);
    s.addVertex(b);
    s.addVertex(c);
    s.addEdge(a,b,1);
    s.addEdge(b,c,1);
    s.addEdge(a,c,1);

    if(s.isPath(c,a))
    {
        cout<<"There is a path from c to a"<<endl;
    }
    else if(!s.isPath(c,a))
    {
        cout<<"There is no path from c to a"<<endl;
    }

    return 0;
}

g::g(int n){
    vertex = new char[n];
    numVerticies = 0;
    maxVerticies = n;
    edges = new int*[n]; //edges is pointer, type is int*,
                   //edges points to a 1d array of pointsers
    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=1;
        }
    }
}

g::~g(){
    if(vertex) delete [] vertex;

    if(edges){
        for(int i=0; i<maxVerticies; i++){
                delete [] edges [i];
                delete [] edges;
        }
    }
}


g::g(const g& rhs){
    vertex = NULL;
    edges = NULL;
    *this = rhs;
}


g& g::operator=(const g& rhs){
    if(this==&rhs) return *this;
    if(vertex) {delete [] vertex; }
    if(edges){
        for(int i=0; i<maxVerticies; i++) // destructor
            delete [] edges [i];

        delete [] edges;
    }

    vertex = new char[rhs.maxVerticies];
    numVerticies = 0;
    maxVerticies = rhs.maxVerticies; // constructor to allocate and copy

    edges = new int*[ rhs.maxVerticies]; //edges is pointer, type is int*,
                                    //edges points to a 1d array of pointsers
    for(int i=0; i< rhs.maxVerticies; i++){
        edges[i] = new int[rhs.maxVerticies];
        for(int j=0; j< rhs.maxVerticies; j++)
            edges[i][j]=0;
    }

    numVerticies=rhs.numVerticies;
    for(int i=0; i<rhs.numVerticies; i++){
        vertex[i]=rhs.vertex[i];
        for(int j=0; j<rhs.numVerticies; j++){
            edges[i][j]=rhs.edges[i][j];
        }
    }

    maxVerticies = rhs.maxVerticies;
    return *this;
}

void g::addVertex(char x){
    if(checkV(x)) {//check already exists
        if(maxVerticies>numVerticies){
                vertex[numVerticies] = x;
                numVerticies++;
        }
    }
}

bool g::removeVertex(const char& x){
    int i;
    for (i=0;i<numVerticies;i++){
        if (x == vertex[i])
            break;
    }

    if (i == numVerticies)
        return false;

    else{
        vertex[i] = vertex[numVerticies - 1];
        for (int j=0;j<numVerticies;j++){
            edges[i][j] = edges[numVerticies - 1][j];
            edges[j][i] = edges[j][numVerticies - 1];
            edges[numVerticies-1][j] = 0;
            edges[j][numVerticies-1] = 0;
        }
        numVerticies--;
    }
    return true;
}

int g::getIndex(const char& x){
    int i = 0;
    for (i=0; i< numVerticies;i++)
        if (x == vertex[i])
            return i;

    return -1;
}

bool g::checkV(char x){
    for (int i=0;i<numVerticies;i++)
        if (vertex[i] == x)
            return false;

    return true;
}
bool g::isPath(const char&start,const char&stop)
{
    int sta = getIndex(start);
    int sto = getIndex(stop);
    bool pathfound = true;
    if(start == stop)
    {
        return true;
    }
    for(int i = sta; i<sto; i++)
    {
        for(int j = sta; j<sto; j++)
        {
            if(edges[i][j]!=1)
            {
                pathfound = false;
            }
        }
    }
}

void g::addEdge(const char& start, const char& stop, int w){
    int sta = getIndex(start);
    int sto = getIndex(stop);
    if ( (sta != -1) && (sto != -1) )
    {
        edges[sta][sto] = w;
    }

}

void g::removeEdge(const char& start, const char& stop){
    int sta = getIndex(start);
    int sto = getIndex(stop);
    if ( (sta != -1) && (sto != -1) )
        edges[sta][sto] = 0;
}

vector<int> g::getNeighbors(int i){
    vector<int> result;
    for (int j = 0; j<numVerticies; j++){
        if (edges[i][j] != 0)
            result.push_back(j);
    }
    return result;
}




