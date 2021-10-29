/*
 * @Author: tblgsn
 * @Date: 2021-10-27 10:46:38
 * @Description: 翻译接口
 * @FilePath: /Translator/src/translator.h
 */
#ifndef _TRANSLATOR_SRC_TRANSLATOR_H_
#define _TRANSLATOR_SRC_TRANSLATOR_H_
#include <string>
#include <sstream>
#include <curl/curl.h>

using namespace std;

class Translator {
    public:
        Translator():res(""),handle(nullptr) {
            curl_global_init(CURL_GLOBAL_ALL);
            handle = curl_easy_init();
        }
        
        virtual ~Translator() {
            curl_easy_cleanup(handle);
            curl_global_cleanup();
        }
        /**
         * @description:  用户自己定义其他翻译器时，需要自己实现这个接口
         * @param {char*} url
         * @return {*}
         */        
        virtual void request(const char* url);
        
        string getdata() const {
            return this->res;
        }
    private:
        /**
         * @description: 实现将服务器返回的结果(通常为json 格式)解析出实际的结果
         * @param {string} &s
         * @return {*}
         */        
        virtual void parse(string &s) = 0;
        CURL* handle; 
    protected:
        string res;
};
#endif // _TRANSLATOR_SRC_TRANSLATOR_H_