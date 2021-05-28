#ifndef _PRIETEN_H
#define _PRIETEN_H


#include <string>
using namespace std;
#include "Contact.h"

class Prieten : public Contact {
  private:
    string data_nasterii;

    string nr_telefon;

    string adresa;


  public:
    inline const string get_data_nasterii() const;

    void set_data_nasterii(string value);

    inline const string get_nr_telefon() const;

    void set_nr_telefon(string value);

    inline const string get_adresa() const;

    void set_adresa(string value);

};
inline const string Prieten::get_data_nasterii() const {
  return data_nasterii;
}

inline const string Prieten::get_nr_telefon() const {
  return nr_telefon;
}

inline const string Prieten::get_adresa() const {
  return adresa;
}

#endif
