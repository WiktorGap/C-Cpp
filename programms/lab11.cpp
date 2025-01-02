#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include "json.hpp"


using json = nlohmann::json;

class Config
{

private:
    Config() : MyFile(stringConfigFile), MyFileInt(intConfigFile)
    {
        std::string str;
        std::string file_contents;
        
        while(std::getline(MyFile,str))
        {
            file_contents += str;
            file_contents.push_back('\n');
        }


        stringConfig=json::parse(file_contents);

        std::string str_;
        std::string file_contents_;
        while(std::getline(MyFileInt,str))
        {
            file_contents_ += str;
            file_contents.push_back('\n');
        }

        intConfig=json::parse(file_contents_);


    }
public:

    ~Config(){}

    void set(const std::string &key, const std::string &value)
    {
        stringConfig[key]=value;
    };
    void set(const std::string &key, const int value)
    {
        intConfig[key]=value;
    };
    std::string getString(const std::string &key)
    {
            return stringConfig[key];
    };
    int getInt(const std::string &key)
    {
        return intConfig[key];
    };





void read() {
    std::string jsonText = "{\"key\":\"value\",\"key2\":\"value2\",\"key3\":\"value3\"}";
    json data = json::parse(jsonText);

    std::unordered_map<std::string, std::string> conf = data;

    for (const auto &entry : conf)
    {
        std::cout << entry.first << "=" << entry.second << std::endl;
    }
}

private:
    std::unordered_map<std::string,std::string> stringConfig;
    std::unordered_map<std::string,int> intConfig;

    const std::string stringConfigFile = "str_config.json";
    const std::string intConfigFile = "int_config.json";

    std::ifstream MyFile;
    std::ifstream MyFileInt;

};


int main()
{


    return 0;
}