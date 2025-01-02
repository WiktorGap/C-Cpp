#include <iostream>
#include <cstring>
class Media
{
public:
    Media(std::string& _filename):file(_filename){};
    virtual void play()=0;
    virtual void pause()=0;
    const std::string& getFilename()const   //w funkcji std::string &file???
    {
        return file;
    }
    virtual ~Media();
    private:
    std::string file;
};

class AudioPlayer : public Media
{
public: 
    AudioPlayer(const std::string &obj):file(obj)
    {
        std::string file_name = obj.getFilename();
        file_name = file;
    };
    std::string file;
    void play() override
    {
        std::cout<<"AudioPlayer: playing "<<file;
    }
    void pause() override
    {
        std::cout<<"AudioPlayer: paused: "<<file;
    }
};



int main()
{
    return 0;
}