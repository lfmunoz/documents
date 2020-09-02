




#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))


#ifndef _OTA_H
#define _OTA_H

class OTA {
public:
  void setup();
  void update();
  bool active;
private:
  bool connected = false;
};

extern OTA ota;

#endif