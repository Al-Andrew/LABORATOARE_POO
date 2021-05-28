#ifndef _AUDI_H
#define _AUDI_H


#include <string>
using namespace std;
#include "Masina.h"

class audi : public Masina {
  private:
    string name;

    int hp;


  public:
    inline const string get_name() const;

    inline const int get_hp() const;

    void set_hp(int value);

    void set_name(string value);

    virtual string getCarModelName();

};
inline const string audi::get_name() const {
  return name;
}

inline const int audi::get_hp() const {
  return hp;
}

#endif
