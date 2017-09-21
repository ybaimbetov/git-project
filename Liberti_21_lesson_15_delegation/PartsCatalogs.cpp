#include "stdafx.h"
#include "PartsCatalogs.h"


void PartsCatalogs::Insert(Part* pPart)
  {
  int nPartNumber = pPart->GetPartNumber();
  int nOffset;

  if (!thePartsList.Find(nOffset, nPartNumber))
    thePartsList.Insert(pPart);
  else
    {
    cout << nPartNumber << "was ";
    switch (nOffset)
      {
      case 0: cout << "the first "; break;
      case 1: cout << "the second "; break;
      case 2: cout << "the third "; break;
      default:cout << "the " << nOffset + 1 << "th "; break;
      }
    cout << "entry. Rejected!\n";
    }
  }


int PartsCatalogs::Exists(int nPartNumber)
  {
  int nOffset;
  thePartsList.Find(nOffset, nPartNumber);
  return nOffset;
  }

Part* PartsCatalogs::Get(int nPartNumber)
  {
  int nOffset;
  Part* thePart = thePartsList.Find(nOffset, nPartNumber);
  return thePart;
  }
