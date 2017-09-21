#include "stdafx.h"
#include "part.h"
#include <iostream>

using namespace std;
void Part::Display() const
  {
  cout << "\nPart Number: " << m_nPartNumber << endl;
  cout << "\nPart Number+Number: " << m_nPartNumber + m_nPartNumber << endl;
  }

