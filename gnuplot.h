#include <iostream>
#include <cstdio>

using namespace std;

int CreateHist() {

    FILE *fp = popen("/usr/local/bin/gnuplot -persist", "w");

    if(fp == NULL) return -1;

    // グリッド
    fprintf(fp, "set grid");
    // ラベル
    fprintf(fp, "set xlabel 'Pixel Value'\n");
    fprintf(fp, "set ylabel 'Number of Pixel'\n");

    // 描画
    fprintf(fp, "plot x with histeps title 'Histgram'");
    pclose(fp);

    return 0;
}
