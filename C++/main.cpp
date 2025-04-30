#define MINIAUDIO_IMPLEMENTATION
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <vector>
#include <windows.h>
#include <miniaudio.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <spook1_wav.h>
#include <spook2_wav.h>
#include <image_rgba.h>
using std::vector, std::random_device , std::minstd_rand, std::uniform_int_distribution, std::cout, std::endl, std::cerr;
//written before I knew better. Probably should rewrite from scratch.


void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    ma_decoder* pDecoder = (ma_decoder*)pDevice->pUserData;
    if (pDecoder == nullptr) {
        return;
    }

    ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, nullptr);
    (void)pInput;
}

int playsound(unsigned char* file, unsigned int filel, int sleeptime) {
    ma_result result;
    ma_decoder decoder;
    ma_device_config deviceConfig;
    ma_device device;
    result = ma_decoder_init_memory(file, filel, nullptr, &decoder);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize decoder.\n");
        return -1;
    }

    // Configure the playback device
    deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format = decoder.outputFormat;
    deviceConfig.playback.channels = decoder.outputChannels;
    deviceConfig.sampleRate = decoder.outputSampleRate;
    deviceConfig.dataCallback = data_callback;
    deviceConfig.pUserData = &decoder;

    // Initialize the playback device
    result = ma_device_init(nullptr, &deviceConfig, &device);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize playback device.\n");
        ma_decoder_uninit(&decoder);
        return -1;
    }
    result = ma_device_start(&device);
    if (result != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&device);
        ma_decoder_uninit(&decoder);
        return -1;
    }
    std::this_thread::sleep_for(std::chrono::seconds(sleeptime));
    ma_device_uninit(&device);
    ma_decoder_uninit(&decoder);
    return 0;
}

void play_second_sound(Fl_Window* window) {
    playsound(spook2_wav, spook2_wav_len, 4);
    Fl::delete_widget(window); // End the FLTK event loop after playing the sound
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    // List of times that are selected by RNG
    vector<int> times = {15, 30, 45, 60, 360, 120, 21 ,49 ,63, 246};
    random_device rd;
    minstd_rand gen(rd());
    uniform_int_distribution<> distr(0, 9);
    //generates num from 1-10 to select time from list
    int time = distr(gen);
    cout << "Rando says " << time+1 << endl;
    cout << "This is sleep time: " << times[time] << endl;
    std::this_thread::sleep_for(std::chrono::seconds(times[time]));

    playsound(spook1_wav, spook1_wav_len, 5);

    Fl_Window *window = new Fl_Window(Fl::w(), Fl::h());
    window->fullscreen();
    window->color(FL_BLACK);
    Fl_Box *box = new Fl_Box(0, 0, Fl::w(), Fl::h());
    Fl_RGB_Image *img = new Fl_RGB_Image(image_rgba, 1080, 1080, 4);
    box->image(img);
    window->end();
    window->show();
    Fl::add_timeout(0, [](void* data) {
        play_second_sound(static_cast<Fl_Window*>(data));
    }, window);
    Fl::run();
    WinMain(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}
