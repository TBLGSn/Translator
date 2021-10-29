/*
 * @Author: tblgsn
 * @Date: 2021-10-27 10:46:38
 * @Description: 翻译接口
 * @FilePath: /translator/src/translator.cpp
 */

#include <string>
#include <sstream>
#include <iostream>
#include <curl/curl.h>
#include "translator.h"

using namespace std; 

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
            string data((const char*) ptr, (size_t) size * nmemb);
            *((stringstream*) stream) << data << endl;
            return size * nmemb;
}

void Translator::request(const char *url) {
    curl_easy_setopt(handle,CURLOPT_URL,url);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, (void *)&write_data);
    stringstream out;
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &out);
    if( curl_easy_perform(handle) != CURLE_OK ) {
        std::cout << "EREER";
        return;
    } else {
        string t = out.str();
        parse(t);
    }
}


