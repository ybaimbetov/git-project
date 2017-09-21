// Liberti_21_lesson_15_delegation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CarPart.h"
#include "AirPlane.h"
#include "PartsCatalogs.h"
#include "part.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
PartsCatalogs pc;
Part* pPart = 0;
int nPartNumber, nValue, nChoice;

while (1)
  {
  cout << "(0)Quit (1)Car (2)Plane: ";
  cin >> nChoice;

  if (!nChoice)
    break;

  cout << "New PartNumber?: ";
  cin >> nPartNumber;

  if (nChoice == 1)
    {
    cout << "Modal Year? : ";
    cin >> nValue;
    pPart = new CarPart(nValue, nPartNumber);
    }
  else
    {
    cout << "Engine Number? : ";
    cin >> nValue;
    pPart = new AirPlanePart(nValue, nPartNumber);
    }
  pc.Insert(pPart);
  }
pc.ShowAll();
return 0;
}

