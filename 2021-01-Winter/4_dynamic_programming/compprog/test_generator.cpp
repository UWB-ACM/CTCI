//
//  main.cpp
//  sample
//  Mitchell Dang

// read 2 number and print out the sum
#include <cassert>
#include <string>
#include <random>
#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
#define ll long long

// number of tests
const int NTEST = 10;

// randomize numebr >= l and <= h
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}


void genInp()
{
    srand(time(NULL));
    mkdir("test",0777);
    mkdir("./test/input",0777);

    string filename = "input";
    for (int iTest = 0; iTest < NTEST; iTest++)
    {
        string testNo = iTest < 10 ? ("0" + to_string(iTest)) : to_string(iTest);
        ofstream inp(("./test/input/"+ filename + testNo + ".txt").c_str());
        
        /* modify code below to make it work for your program */
        // START OF YOUR TEST GENERATION LOGIC
        
        ll a = Rand(1, 100); // generate a number for a
        ll b = Rand(-10, 50); // generate a number for b
        inp << a << " " << b << endl; // write a b into a file (ie. input00.txt, input01.txt, ...)
        
        // END OF YOUR TEST GENERATION LOGIC
        inp.close(); 
    }
}

void genOut() {
    mkdir("./test/output",0777);
    
    for (int iTest = 0; iTest < NTEST; iTest++) {
        string testNo = iTest < 10 ? ("0" + to_string(iTest)) : to_string(iTest);
        string cmd = "./main < ./test/input/input"+ testNo + ".txt > ./test/output/output" + testNo + ".txt";
        system(cmd.c_str());
        
    }
}


int main(int argc, const char * argv[]) {
    cin.tie(0); ostream::sync_with_stdio(0);
    
    // ==> modify NTEST to change the number of tests generated
    
    // STEP 1: GENERATE TESTS, follow these steps:
    // 0. uncomment to generateTests()
    // 1. run this command in terminal/cmd: g++ main.cpp -o gentest
    // 2. ./gentest
    
    genInp();
    
    /*============================*/
    
    // STEP 2: GENERATE exec file for solution, follow these steps:
    // 0. uncomment solution()
    // 1. run this command in terminal/cmd: g++ main.cpp -o solve
    // 2. ./solve
    
    //solution();
    
    
    
    // STEP 3: GENERATE exec file for output
    // 0. uncomment runTests
    // 1. run this command in terminal/cmd: g++ main.cpp -o runTests
    // 2. ./runTests
    
    //genOut();
    
    
    return 0;
}


void solution() {
    // sample program
    int a,b;
    cin >> a >> b;
    cout << (a+b) << endl;
}
