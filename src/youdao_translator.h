/*
 * @Author: tblgsn
 * @Date: 2021-10-27 13:54:13
 * @Description: 有道翻译的头文件
 * @FilePath: /Translator/src/youdao_translator.h
 */
#ifndef _TRANSLATOR_SRC_YOUDAO_TRANSLATOR_H_
#define  _TRANSLATOR_SRC_YOUDAO_TRANSLATOR_H_
#include <string>
#include "translator.h"
class Youdao_translator : public Translator
{
private:
    //接口API，需要在最后加上真正的"查询的语句"
    string url = "http://fanyi.youdao.com/translate?&doctype=json&type=AUTO&i=";
public:
    void set_url(string& s){
        url = s;
    }
    Youdao_translator(){}
    Youdao_translator(const char *url):url(url){}
    void request(const string sentence);
    ~Youdao_translator();
};

#endif //  _TRANSLATOR_SRC_YOUDAO_TRANSLATOR_H_