#pragma once
#include "part.h"
#include "PartsList.h"

class PartsCatalogs
  {
  private:
    PartsList thePartsList;
  public:
    void Insert(Part*);
    int Exists(int nPartNumber);
    Part* Get(int nPartNubmer);
    //operator+(const PartsCatalogs&);
    void ShowAll() { thePartsList.Iterate(&Part::Display); }
  };