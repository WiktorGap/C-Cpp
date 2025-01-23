#include <iostream>
#include <cstring>
class Media
{
public:
    Media(const std::string& _filename) : file(_filename) {}
    virtual void play()=0;
    virtual void pause()=0;
    const std::string& getFilename()const   //w funkcji std::string &file???
    {
        return file;
    }
    virtual ~Media()=default;
    private:
    std::string file;
};

class AudioPlayer : virtual public Media
{
public: 
    AudioPlayer(const std::string& obj) : Media(obj) {}
    std::string file;
    void play() override
    {
        std::cout<<"AudioPlayer: playing "<<getFilename()<<"\n";
    }
    void pause() override
    {
        std::cout<<"AudioPlayer: paused: "<<getFilename();
    }
};

class ViedoPlayer : virtual public Media
{
public:
    ViedoPlayer(const std::string& obj) : Media(obj) {}
    std::string file;
    void play() override
    {
        std::cout<<"VideoPlayer: playing "<<getFilename()<<"\n";
    }
    void pause() override
    {
        std::cout<<"VideoPlayer: paused: "<<getFilename()<<"\n";
    }
    void setBrightness(int brightness)
    {
         std::cout<<"Brighntess is set to value: "<<brightness<<"\n";
    }

};

class AVPlayer :  public ViedoPlayer ,  public AudioPlayer
{
public:
    AVPlayer(const std::string& obj) : Media(obj), ViedoPlayer(obj), AudioPlayer(obj) {};
    std::string file;
    void play() override
    {
        std::cout<<"AVPlayer: synchronizing "<<"\n";
        AudioPlayer::play();
        ViedoPlayer::play();
    }
    void pause() override
    {
        std::cout<<"AVPlayer: pausing"<<getFilename()<<"\n";
    }

};

int main()
{
    std::string filename = "kingVonAlbum.mp3";
    AudioPlayer audioPlayer(filename);
    audioPlayer.play();
    audioPlayer.pause();

    std::string filename2 = "exampleVideo.mp4";
    ViedoPlayer videoPlayer(filename2);
    videoPlayer.play();
    videoPlayer.pause();
    videoPlayer.setBrightness(20);

    std::string filename3 = "movie.mp4";
    AVPlayer avPlayer(filename3);
    avPlayer.play();
    avPlayer.pause();
;
    return 0;
}
