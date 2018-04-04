/*
  Function.h
  Deklarasi fungsi dan variabel
*/

#ifndef Function_h
#define Function_h

#include "Arduino.h"

class Function
{
  public:
    void on ();
    void off ();
    void delay (string pilihan);
  private:
    string _pilihan;
    int _waktuDelay;
    int _idx;
};

#endif
