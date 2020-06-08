#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

int n, m, cost, cost1;

class Edge {
public:
	int u, v;
};

struct classcomp {
	bool operator() (const Edge& e, const Edge& e1) const {return (e.u < e1.u || (e.u == e1.u && e.v < e1.v));}
};


map<Edge, int, classcomp> edgeMap;

FILE *fp;

int main(int argc, char* argv[]){
	if (argc != 4) {
		printf("Usage: %s inputfile outputfile youroutputfile\n", argv[0]);
		return 0;
	}
	
	fp = fopen(argv[1], "r");
	fscanf(fp, "%d %d", &n, &m);
	Edge edge;
	map<Edge, int, classcomp>::iterator it; 
	int i, w;
	for (i = 0; i < m; i++){
		fscanf(fp, "%d %d %d", &edge.u, &edge.v, &w);
		if (edge.u > edge.v) {
			int t = edge.u; edge.u = edge.v; edge.v = t;
		}
		edgeMap[edge]=w;
	}
	fclose(fp);

	fp = fopen(argv[2], "r"); 
	fscanf(fp, "%d", &cost);
	fclose(fp);

	fp = fopen(argv[3], "r");
	fscanf(fp, "%d", &cost1);
	if (cost1 != cost) {
		printf("Cost is not correct.\n"); 
		return 0;
	}
	for (i = 0; i < n-1; i++){
		fscanf(fp, "%d %d", &edge.u, &edge.v);
		if (edge.u > edge.v){
			int t = edge.u; edge.u = edge.v; edge.v = t;
		}
		it = edgeMap.find(edge);
		if (it == edgeMap.end()) {
			printf("Can not find edge (%d, %d).\n", edge.u, edge.v); return 0;
		}
		cost1 -= it->second;
	}
	fclose(fp);

	if (cost1 != 0) {
		printf("Your cost does not equal to the total cost of all output edges.\n"); return 0;
	}
	
	printf("OK\n");

}
