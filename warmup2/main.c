	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numCodons;

char ** makeCodons() {
    freopen("codons.txt", "r", stdin);

	scanf("%d", &numCodons);
    char ** codons; 
    codons = malloc(sizeof(char**) * numCodons + 1);

    for (int i = 0; i < numCodons; i++) {
        codons[i] = malloc(4*sizeof(char));
		scanf("%s", codons[i]);
	}

    return codons;
}

void freeCodons(char ** codons) {
    for (int i = 0; i < numCodons; i++) {
		free(codons[i]);
	}

    free(codons);
}

int main() {
    freopen("input_problem_3.txt", "r", stdin);
	int numTestCases;
	scanf("%d", &numTestCases);
    char ** codons = makeCodons();
    for (int i = 0; i < 65; i++) {
		printf("%s \n", codons[i]);
	}

    freeCodons(codons);
    
}