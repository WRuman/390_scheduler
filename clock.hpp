/**
 * William Ruman 2015 -- Truman State University
 * Header for the system clock class, which issues 'ticks' and dictates
 * simulation state
 */
 
#ifndef __WR_CLOCK_INCLUDED__
#define __WR_CLOCK_INCLUDED__
 
class clock {
    public:
        unsigned int getTime();
        void start();
    private:
        unsigned int tick;
};


#endif //__WR_CLOCK_INCLUDED__