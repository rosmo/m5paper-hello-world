
#include <M5EPD.h>

#ifndef __APPLICATION_H
#define __APPLICATION_H

class Application {
    public:
        Application() { };
        virtual bool init() { return false; };
        virtual void run() { };
};

class HelloWorldApplication : Application {
    public:
        bool init();
        void run();
    private:
        M5EPD_Canvas *canvas;
        int textWidth = 0, textHeight = 0;
        String message = String("Hello World!");
};
#endif