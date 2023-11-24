#include "LcdMonitor.h"

LcdMonitor::LcdMonitor(int rows, int columns) {
    lcd->begin(rows, columns);
    lcd->backlight();
}

void LcdMonitor::setAndPrint(char* string, int xposition, int yposition) {
    lcd->setCursor(xposition, yposition);
    lcd->printstr(string);
}