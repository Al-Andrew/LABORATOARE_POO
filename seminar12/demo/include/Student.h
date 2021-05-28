#ifndef _STUDENT_H
#define _STUDENT_H


#include <string>
using namespace std;
#include <vector>
using namespace std;

class Masina;

class Student {
  private:
    string name;


  public:
    string getName();

    inline const string get_name() const;

    void set_name(string value);


  private:
    vector<Masina *> masiniDetinute;

};
inline const string Student::get_name() const {
  return name;
}

#endif
