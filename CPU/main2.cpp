#include "BenchMark.h"
#include "Edge_sketch.h"
#include "Edge_CU.h"
#include<vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

vector<vector<int> > graph ;
vector<vector<int> > readFile(string path, int &N)
{
	FILE *fp ;
	

	fp = fopen(path.c_str(), "r") ;
	if(!fp)
	{
		cout << "Error : read file" << endl ;
		exit(0) ;
	}

	int a, b, count=0 ;
	int n, m ;

	fscanf(fp, "%d%d", &n, &m) ;
	N = n ;

	for(int i=0; i<n; i++)
		graph.push_back(vector<int>()) ;

	while(fscanf(fp, "%d%d", &a, &b) == 2)
	{
		graph[a].push_back(b) ;
		count++ ;
	}
      //  cout<<a<<endl;
	if(count != m)
		cout << "m not equal to the number of edges in file" + path << endl ;
         
	fclose(fp) ;

	return graph ;
}

int main(int argc, char *argv[]) {
	std::cout << "test00";
        Edge_Sketch<uint64_t, uint64_t> * node = new Edge_Sketch<uint64_t, uint64_t>(500000);
	Edge_Sketch<uint64_t, uint64_t> * edges = new Edge_Sketch<uint64_t, uint64_t>(500000);
	/*
    for(uint32_t i = 1;i < argc;++i) {
        std::cout << argv[i] << std::endl;
        BenchMark dataset(argv[i], "Dataset");
        dataset.HHMultiBench(500000, 0.0001);
    }*/
    return 0;
}
