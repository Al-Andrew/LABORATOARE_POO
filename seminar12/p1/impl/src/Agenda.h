#ifndef _AGENDA_H
#define _AGENDA_H


#include <vector>
using namespace std;
#include <string>
#include <optional>

class Contact;
class Prieten;

class Agenda {
  private:
    vector<Contact *> contacte;


  public:
    std::optional<Contact*> cauta_contact(string nume_contact);

    vector<Prieten*> get_friends();

    bool delete_contact(string nume_contact);

    void add_contact(const Contact* contact);

};
#endif
