#pragma once
#include <iostream>
#include "part.h"
using namespace std;

class PartNode
  {
  private:
    Part *m_pPart;
    PartNode *m_pNext;
  public:
    PartNode(Part* pPart);
    ~PartNode();
    void SetNext(PartNode* pNode) { m_pNext = pNode; }
    PartNode* GetNext() const;
    Part* GetPart() const;
  };

