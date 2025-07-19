#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 64
#define d 2
#define u 64

void main(int argc, char *argv[]) {
    srand(time(NULL));

    int rule[64][8] = {
      {0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},
      {0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},
      {0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},
      {0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},
      {0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},
      {0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},
      {0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},
      {0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0},{0,0,0,1,1,1,0,0}
    };

    long int seeds[5] = {7, 1234, 12345, 19650218, 123456789123456789};
    int noSeeds = 5, sI = 0;

    for (sI = 0; sI < noSeeds; sI++) {
        long int num = seeds[sI];
        int state[N], cnt = 0, i = 0, selected_idx, next_idx;
        FILE *fp;
        char ch = 0, s = 0;

        fp = fopen("BigFile12345.bin", "w");
        if (fp == NULL) {
            exit(0);
        }

        // Initialize state array
        for (i = 0; i < N; i++) {
            state[i] = num % d;
            num = num / d;
        }

        while (cnt < 200000000) {
            for (int step = 0; step < 32; step++) {
                // Select random index
                selected_idx = rand() % N;
                next_idx = (selected_idx + 1) % N;

                // Get neighbors for selected_idx
                int left_sel = state[(selected_idx - 1 + N) % N];
                int center_sel = state[selected_idx];
                int right_sel = state[next_idx];

                // Get neighbors for next_idx
                int left_next = state[selected_idx];
                int center_next = state[next_idx];
                int right_next = state[(next_idx + 1) % N];

                // Calculate rule index for selected_idx
                int rule_idx_sel = 4 * left_sel + 2 * center_sel + right_sel;

                // Calculate rule index for next_idx
                int rule_idx_next = 4 * left_next + 2 * center_next + right_next;

                // Update selected index and next index
                int new_sel = rule[selected_idx][rule_idx_sel];
                int new_next = rule[next_idx][rule_idx_next];

                state[selected_idx] = new_sel;
                state[next_idx] = new_next;
            }

            // Store the 32nd evolved state as binary in the file
            for (i = 0; i < N; i++) {
                ch = (ch << 1) | state[i];
                if (s == 7) {
                    fprintf(fp, "%c", ch);
                    s = 0;
                    ch = 0;
                } else {
                    s++;
                }
            }

            cnt++;
        }

        fprintf(fp, "%c", ch);
        fclose(fp);
    }
}