#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class Config
{
private:
    std::unordered_map<std::string, std::string> stringConfig;
    std::unordered_map<std::string, int> intConfig;

    const std::string stringConfigFile = "str_config.json";
    const std::string intConfigFile = "int_config.json";

    Config()
    {
        loadStringConfig();
        loadIntConfig();
    }

    ~Config()
    {
        saveStringConfig();
        saveIntConfig();
    }

    void loadStringConfig()
    {
        std::ifstream file(stringConfigFile);
        if (file.is_open())
        {
            std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            stringConfig = json::parse(content);
            file.close();
        }
    }

    void loadIntConfig()
    {
        std::ifstream file(intConfigFile);
        if (file.is_open())
        {
            std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            intConfig = json::parse(content);
            file.close();
        }
    }

    void saveStringConfig()
    {
        std::ofstream file(stringConfigFile);
        if (file.is_open())
        {
            file << json(stringConfig).dump(4);
            file.close();
        }
    }

    void saveIntConfig()
    {
        std::ofstream file(intConfigFile);
        if (file.is_open())
        {
            file << json(intConfig).dump(4);
            file.close();
        }
    }

public:
    static Config& getInstance()
    {
        static Config instance;
        return instance;
    }

    void set(const std::string &key, const std::string &value)
    {
        stringConfig[key] = value;
    }

    void set(const std::string &key, const int value)
    {
        intConfig[key] = value;
    }

    std::string getString(const std::string &key)
    {
        return stringConfig[key];
    }

    int getInt(const std::string &key)
    {
        return intConfig[key];
    }
};

int main()
{
    Config& config = Config::getInstance();

    config.set("username", "admin");
    config.set("timeout", 30);

    std::cout << "Username: " << config.getString("username") << std::endl;
    std::cout << "Timeout: " << config.getInt("timeout") << std::endl;

    return 0;
}

