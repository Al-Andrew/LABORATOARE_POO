#ifndef _CONTACT_H
#define _CONTACT_H


#include <string>
using namespace std;
#include "Contact_t.h"

class Contact {
  private:
    string nume;


  public:
    inline const string get_nume() const;

    void set_nume(string value);


  private:
    Contact_t * type;

};
inline const string Contact::get_nume() const {
  return nume;
}

#endif
