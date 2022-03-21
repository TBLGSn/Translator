#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>

using namespace std;

#include "youdao_translator.h"
int main(int argc, char *argv[])
{   
    Youdao_translator youdao_translator;
    //string s = R"(密歇根州警方在社交媒体推特上发文称，MSP拆弹小组周末在一处住宅协助兰辛市警方。这家人在清理房屋时发现了一枚炮弹，他们认为是实弹，并报了警。拆弹小组进行了X光检查，确定炮弹不是实弹。经过进一步的检查，发现这是一枚第一次世界大战时期的炮弹，里面藏着大量的旧钱币和纸币，"时间可以追溯到19世纪和20世纪初。)"; 
   youdao_translator.request(R"(にほんご)");
    std::cout << youdao_translator.getdata();
    return 0;
}