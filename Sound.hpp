#include <SDL2/SDL_mixer.h>
#include<string>


class Sound {
public:

    Sound() = default;
    void Load(std::string filepath);
    ~Sound();

    void play(int channel);
    void stop(int channel);

private:
    Mix_Chunk* m_chunk;
};

