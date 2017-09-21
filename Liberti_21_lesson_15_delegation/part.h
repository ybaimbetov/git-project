#pragma once
class Part
  {
  private:
    int m_nPartNumber;
  public:
    Part() : m_nPartNumber(1) { };
    Part(int nPartnumber) : m_nPartNumber(nPartnumber) { };
    virtual ~Part() { };
    int GetPartNumber() const { return m_nPartNumber; }
    virtual void Display() const = 0;
  };

