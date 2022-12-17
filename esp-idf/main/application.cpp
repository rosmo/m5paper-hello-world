#include "application.hpp"
// M5 specific
#include "application.hpp"

bool HelloWorldApplication::init() {
    canvas = new M5EPD_Canvas(&M5.EPD);
    M5.EPD.Clear(true);

    canvas->setTextSize(6);
    textWidth = canvas->textWidth(message);
    textHeight = canvas->fontHeight();
    printf("Text width: %d, height: %d\n", textWidth, textHeight);
    canvas->createCanvas(textWidth, textHeight);
    canvas->drawString(message, 0, 0);
    return true;
}

void HelloWorldApplication::run() {
    int x = -1, y = -1;
    while (true) {
        x = random(0, M5EPD_PANEL_W - textWidth - 1);
        y = random(0, M5EPD_PANEL_H - textHeight - 1);
        printf("Write message to a random location, x = %d, y = %d\n", x, y);
        M5.EPD.Clear(false);
        canvas->pushCanvas(x, y, UPDATE_MODE_NONE);
        M5.EPD.UpdateFull(UPDATE_MODE_GLR16);
        vTaskDelay(5 * (1000 / portTICK_PERIOD_MS));
    }
}