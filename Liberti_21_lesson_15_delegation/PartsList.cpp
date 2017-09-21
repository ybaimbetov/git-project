#include "stdafx.h"
#include "PartsList.h"

PartsList PartsList::m_pGlobalPartsList;

PartsList::PartsList():
m_pHead(0), m_nCount(0)  { }


PartsList::~PartsList() { delete m_pHead; }

Part* PartsList::GetFirst() const
  {
  if (m_pHead)
    return m_pHead->GetPart();
  else
    return NULL;
  }

Part* PartsList::operator[](int nOffSet) const
  {
  PartNode* pNode = m_pHead;

  if (!m_pHead) return NULL;
  if (nOffSet > m_nCount) return NULL;

  for (int i = 0; i < nOffSet; i++)
    pNode = pNode->GetNext();

  return pNode->GetPart();
  }

Part* PartsList::Find(int& nPosition, int nPartNumber) const
  {
  PartNode* pNode = 0;
  for (pNode = m_pHead, nPosition = 0; pNode != NULL; pNode = pNode->GetNext(), nPosition++)
    {
    if (pNode->GetPart()->GetPartNumber() == nPartNumber)
      break;
    }
  if (pNode == NULL)
    return NULL;
  else
    return pNode->GetPart();
  }

void PartsList::Iterate(void (Part::*func)() const) const
  {
  if (!m_pHead)
    return;
  PartNode* pNode = m_pHead;
  do
    (pNode->GetPart()->*func)();
  while (pNode == pNode->GetNext());
  }

void PartsList::Insert(Part *pPart)
  {
  PartNode* pNode = new PartNode(pPart);
  PartNode* pCurrent = m_pHead;
  PartNode* pNext = 0;

  int nNew = pPart->GetPartNumber();
  int nNext = 0;
  m_nCount++;

  if (!m_pHead)
    {
    m_pHead = pNode;
    return;
    }

  // ≈сли это значение меньше головного узла,
  // то текущий узел становитс€ головным
  if (m_pHead->GetPart()->GetPartNumber() > nNew)
    {
    pNode->SetNext(m_pHead);
    m_pHead = pNode;
    return;
    }

  for (;;)
    {
    // ≈сли нет следующего, вставл€й текущий
    if (!pCurrent->GetNext())
      {
      pCurrent->SetNext(pNode);
      return;
      }

    // ≈сли текущий больше предыдущего, но меньше следующего, то вставл€ем
    // здесь. »наче присваиваем значение указател€ Next
    pNext = pCurrent->GetNext();
    nNext = pNext->GetPart()->GetPartNumber();
    if (nNext > nNew)
      {
      pCurrent->SetNext(pNode);
      pNode->SetNext(pNext);
      return;
      }
    pCurrent = pNext;
    }
  }