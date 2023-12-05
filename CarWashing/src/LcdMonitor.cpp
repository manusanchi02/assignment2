#include "LcdMonitor.h"

LcdMonitor::LcdMonitor(int rows, int columns)
{
    lcd = new LiquidCrystal_I2C(0x27, columns, rows);
    lcd->init();
    lcd->backlight();
}

void LcdMonitor::setAndPrint(char *string, int xposition, int yposition)
{
    lcd->setCursor(xposition, yposition);
    lcd->printstr(string);
}

void LcdMonitor::clean()
{
    lcd->clear();
}