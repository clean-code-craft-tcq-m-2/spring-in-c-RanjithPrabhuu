
struct Stats{
  float min;
  float max;
  float average;
};


struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], int alerterCount, struct Stats computedStats);

