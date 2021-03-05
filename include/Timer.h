#ifndef AA_Timer
#define AA_Timer

class Timer {
   public:
    Timer();
    Timer(unsigned long time);
    ~Timer();
    void start();
    void start(unsigned long time);
    void stop();
    void setInterval(unsigned long time);
    unsigned long getInterval();
    void reset();  //sets begintime to now

    void turn(bool state);
    bool isON() { return _on; };

    unsigned long delta();
    float percent();
    bool tick();  //returns true when Timer is exceeded and resets timer

    bool operator()() { return tick(); }
    void operator()(const unsigned long time) { setInterval(time); }
    void operator()(const bool state) { turn(state); }
    void operator>>(unsigned long &delta) { delta = this->delta(); }
    void operator>>(float &percent) { percent = this->percent(); }

   private:
    bool _on;
    unsigned long ttime;   //time Interval for each full Timer tick
    unsigned long tlast;   //start time
    unsigned long tnow;    //current time
    unsigned long tdelta;  //timedelta between start and current
};

#endif