#ifndef _CUNOSCUT_H
#define _CUNOSCUT_H


#include <string>
using namespace std;
#include "Contact.h"

class Cunoscut : public Contact {
  private:
    string nr_telefon;


  public:
    inline const string get_nr_telefon() const;

    void set_nr_telefon(string value);

};
inline const string Cunoscut::get_nr_telefon() const {
  return nr_telefon;
}

#endif
