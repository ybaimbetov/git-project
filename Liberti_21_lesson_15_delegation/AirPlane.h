#pragma once
#include "part.h"
#include <iostream>

using namespace std;

class AirPlanePart :
  public Part
  {
  private:
    int m_nEngineNumber;
  public:
    AirPlanePart() : m_nEngineNumber(1) { };
    AirPlanePart(int nEngineNumber, int nPartNumber);
    virtual void Display() const
      {
      Part::Display();
      cout << "Engine No: " << m_nEngineNumber << endl;
      }
  };

