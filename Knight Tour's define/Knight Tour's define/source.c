#define _CRT_SECURE_NO_WARNINGS
#define WEIGHT 6
#define HEIGHT 5


#include <stdio.h>
#include <stdlib.h>

int count = 1;

void solution(int arr[][WEIGHT], int xgo[], int ygo[], int x, int y);
int warnsdorff(int arr[][WEIGHT], int xgo[], int ygo[], int x, int y);

int main(int argc, char* argv[]) {

	int xgo[8] = { 1,2,2,1,-1,-2,-2,-1 }; //1,2,3,4,5,6,7,8
	int ygo[8] = { -2,-1,1,2,2,1,-1,-2 };
	int i, j = 0;
	int arr[HEIGHT][WEIGHT] = { 0, };
	int x = 5, y = 4;

	//x = atoi(argv[1]);
	//y = atoi(argv[2]);

	solution(arr, xgo, ygo, x, y);

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WEIGHT; j++) {
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void solution(int arr[][WEIGHT], int xgo[], int ygo[], int x, int y) {

	int cc[8] = { 0, };
	int cc_dest[8] = { 0, };
	int cc_count = 0;
	int go_index = 0;

	if (count == WEIGHT * HEIGHT + 1) {
		return;
	}
	arr[x][y] = count++;

	for (int i = 0; i < 8; i++) {
		if (arr[x + xgo[i]][y + ygo[i]] == 0)
			cc[i] = warnsdorff(arr, xgo, ygo, x + xgo[i], y + ygo[i]);
	}
	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (cc[j] == i) {
				cc_dest[cc_count++] = j;
				cc[j] = 0;
			}
		}
	}

	for (int i = 0; i < cc_count; i++) {
		solution(arr, xgo, ygo, x + xgo[cc_dest[i]], y + ygo[cc_dest[i]]);
		if (count == WEIGHT * HEIGHT + 1) {
			return;
		}
	}
	if (count != WEIGHT * HEIGHT + 1) {
		count--; 
		arr[x][y] = 0;
	}
}
int warnsdorff(int arr[][WEIGHT], int xgo[], int ygo[], int x, int y) {

	int result = 0;
	int i = 0;

	if (x < 0 || y < 0 || x > WEIGHT - 1 || y > HEIGHT -1) {
		return 0;
	}
	for (i = 0; i < 8; i++) {
		if (x + xgo[i] < 0 || y + ygo[i] < 0 || x + xgo[i] > WEIGHT - 1 || y + ygo[i] > HEIGHT - 1) {
			continue;
		}
		if (arr[x + xgo[i]][y + ygo[i]] == 0) {
			result++;
		}
		if (arr[x + xgo[i]][y + ygo[i]] == WEIGHT * HEIGHT -1) {
			result++;
		}
	}
	return result;
}