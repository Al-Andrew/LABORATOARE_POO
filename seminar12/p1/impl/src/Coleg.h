#ifndef _COLEG_H
#define _COLEG_H


#include <string>
using namespace std;
#include "Contact.h"

class Coleg : public Contact {
  private:
    string nr_telefon;

    string adresa;

    string firma;


  public:
    inline const string get_nr_telefon() const;

    void set_nr_telefon(string value);

    inline const string get_adresa() const;

    void set_adresa(string value);

    inline const string get_firma() const;

    void set_firma(string value);

};
inline const string Coleg::get_nr_telefon() const {
  return nr_telefon;
}

inline const string Coleg::get_adresa() const {
  return adresa;
}

inline const string Coleg::get_firma() const {
  return firma;
}

#endif
