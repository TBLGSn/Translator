/*
 * @Author: tblgsn
 * @Date: 2021-10-27 13:54:37
 * @Description: 有道翻译
 * @FilePath: /Translator/src/youdao_translator.cpp
 */
#include <string>
#include "youdao_translator.h"

using namespace std;

void Youdao_translator::request(const string sentence){
    url += sentence;
    Translator::request(url.c_str()); 
};

Youdao_translator::~Youdao_translator()
{ 
}