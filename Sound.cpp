#include<iostream>
#include "Sound.hpp"


// Implementation of Sound class methods
void Sound::Load(std::string filepath) {
    m_chunk = Mix_LoadWAV(filepath.c_str());
    if (!m_chunk) {
        std::cerr << "Failed to load sound file: " << filepath << " Error: " << Mix_GetError() << std::endl;
    }
}

Sound::~Sound() {
    if (m_chunk) {
        Mix_FreeChunk(m_chunk);
    }
}

void Sound::play(int channel) {
    if (channel >= 0) {
        Mix_HaltChannel(channel);
        if (Mix_PlayChannel(channel, m_chunk, 0) == -1) {
            std::cerr << "Error playing sound: " << Mix_GetError() << std::endl;
        }
    }
}

void Sound::stop(int channel) {
    if (channel >= 0) {
        Mix_HaltChannel(channel);
    }
}
