<!--
 * @Author: tblgsn
 * @Date: 2021-10-27 15:37:20
 * @Description: 
 * @FilePath: /Translator/README.md
-->
# Translator
C++ 翻译接口
## 简介
常见翻译平台(例如[有道智云](https://ai.youdao.com/product-fanyi-text.s)、[google 翻译](https://cloud.google.com/translate)、[百度翻译](https://api.fanyi.baidu.com/))等众多的翻译平台都没有提供 C++ 接口,而网上对于这部分的内容又比较少。再加上一些其他原因，最终成就了这个库函数。

## 项目依赖
项目的开发环境为: Ubuntu 18.04.6 LTS
项目以来于轻量级的网络库[libcurl](https://curl.se/libcurl/)
版本信息如下:
- libcurl/7.58.0 
- OpenSSL/1.1.1 
- zlib/1.2.11 
- libidn2/2.0.4 
- libpsl/0.19.1 (+libidn2/2.0.4) 
- nghttp2/1.30.0 librtmp/2.3
对于 JSON 格式的返回信息，通过字符串的处理进行提取

## 项目的使用
使用以下命令安装 libcurl 库
```shell
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install -y libcurl-dev
```

在你的项目文件中包含 src 文件夹中的文件、导入 libcurl 库(参见CMakeLists.txt 文件)，通过以下的接口进行使用.
```c++
    //以有道翻译为例
    Youdao_translator youdao_translator;//得到一个有道翻译器
    youdao_translator.request(R"(にほんご)"); //以原生字符串的形式传入查询的句子
    
    std::cout << youdao_translator.getdata(); //得到返回结果
```
