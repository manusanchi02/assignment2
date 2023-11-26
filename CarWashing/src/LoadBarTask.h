#ifndef __LOADBARTASK__
#define __LOADBARTASK__
#include "Task.h"
#include "LcdMonitor.h"

class LoadBarTask : public Task
{
public:
    /**
     * Class constructor.
     * @param rows number of lcd rows
     * @param columns number of lcd columns
     */
    LoadBarTask(int rows, int column);
    /**
     * Init method.
     */
    void init(int period);
    /**
     * Tick method.
     */
    void tick();

protected:
    int rows;
    int column;
    int counter;
    char *bar;
    LcdMonitor *lcd;
};

#endif