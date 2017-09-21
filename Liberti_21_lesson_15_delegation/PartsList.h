#pragma once
#include <iostream>
#include "PartNode.h"

using namespace std;

class PartsList
  {
  private:
    PartNode* m_pHead;
    int m_nCount;
    static PartsList m_pGlobalPartsList;
  public:
    PartsList();
    ~PartsList();
    void Iterate(void (Part::*func)() const) const;
    Part* Find(int& nPosition, int nPartNumber) const;
    Part* GetFirst() const;
    void Insert(Part* pPart);
    Part* operator[](int nOffSet) const;
    int GetCount() const { return m_nCount; }
    static PartsList& GetGlobalPartList() { return m_pGlobalPartsList; }
  };

