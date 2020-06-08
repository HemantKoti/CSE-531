#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

char A[1050], B[1050], c[1050];

int f[1050][1050];

FILE *fp;

bool subsequence(int n, char *A, int l, char *c) {
	int i, j=0;
	for (i = 0; i < n; i++) {
		if (A[i] == c[j]) j++;
		if (j == l) return true;
	}
	printf("%d\n", j);
	return false;
}

int main(int argc, char* argv[]){
	if (argc != 4) {
		printf("Usage: %s inputfile outputfile youroutputfile\n", argv[0]);
		return 0;
	}
	fp = fopen(argv[1], "r");
	fscanf(fp, "%s", A);
	fscanf(fp, "%s", B);
	fclose(fp);

	int i, j;
	int n = strlen(A);
	int m = strlen(B);
	int l, l1;

	fp = fopen(argv[2], "r");
	fscanf(fp, "%d", &l);
	fclose(fp);

	fp = fopen(argv[3], "r");
	fscanf(fp, "%d", &l1);
	fscanf(fp, "%s", c);
	fscanf(fp, "%s", c);
	fclose(fp);

	if (l1 != l) {
		printf("length is not correct\n");
		exit(0);
	}
	if (!subsequence(n, A, l, c)) {
		printf("c is not a subsequence of A\n");
		exit(0);
	}
	if (!subsequence(m, B, l, c)) {
		printf("c is not a subsequence of B\n");
		exit(0);
	}
	printf("OK\n");

}
