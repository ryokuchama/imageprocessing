#include <iostream>
#include <cstdio>

using namespace std;

int CreateHist() {

    FILE *fp = popen("/usr/local/bin/gnuplot -persist", "w");

    if(fp == NULL) return -1;

    // ラベル
    fprintf(fp, "set xlabel 'Pixel Value'\n");
    fprintf(fp, "set ylabel 'Number of Pixel'\n");

    // 
    pclose(fp);

    return 0;
}
