#include <iostream>
#include <string>

class Media
{
public:
    Media(const std::string& _filename) : file(_filename) {}
    virtual void play() = 0;
    virtual void pause() = 0;

    const std::string& getFilename() const
    {
        return file;
    }

    virtual ~Media() = default;

private:
    std::string file;
};

class AudioPlayer : public Media
{
public: 
    AudioPlayer(const std::string& obj) : Media(obj) {}
    
    void play() override
    {
        std::cout << "AudioPlayer: playing " << getFilename() << '\n';
    }

    void pause() override
    {
        std::cout << "AudioPlayer: paused: " << getFilename() << '\n';
    }
};

int main()
{
    std::string filename = "kingVonAlbum.mp3";
    AudioPlayer player(filename);
    player.play();
    player.pause();
    return 0;
}
