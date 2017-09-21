#pragma once
#include "part.h"
#include <iostream>
using namespace std;

class CarPart :
  public Part
  {
  private:
    int m_nModelYear;
  public:
    CarPart() : m_nModelYear(94) { };
    CarPart(int nYear, int nPartNumber);
    virtual void Display() const
      {
      Part::Display();
      cout << "Model Year: " << m_nModelYear << endl;
      }
  };

