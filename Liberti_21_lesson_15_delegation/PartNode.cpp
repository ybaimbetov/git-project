#include "stdafx.h"
#include "PartNode.h"


PartNode::PartNode(Part* pPart) : m_pPart(pPart), m_pNext(0) { }

PartNode::~PartNode()
  {
  delete m_pPart;
  m_pPart = 0;
  delete m_pNext;
  m_pNext = 0;
  }

PartNode* PartNode::GetNext() const { return m_pNext; }
Part* PartNode::GetPart() const
  {
  if (m_pPart)
    return m_pPart;
  else
    return NULL;
  }