// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>
#include <bit>

using namespace std;
class TELEM {
public:
	unsigned int bit0 : 1;
	unsigned int bit1 : 1;
	unsigned int bit2 : 1;
	unsigned int bit3 : 1;
	unsigned int bit4 : 1;
	unsigned int bit5 : 1;
	unsigned int bit6 : 1;
	unsigned int bit7 : 1;
	TELEM operator=(TELEM t) {
		bit0 = t.bit0;
		bit1 = t.bit1;
		bit2 = t.bit2;
		bit3 = t.bit3;
		bit4 = t.bit4;
		bit5 = t.bit5;
		bit6 = t.bit6;
		bit7 = t.bit7;
		return *this;
	}
	TELEM operator=(int i) {
		switch (i) {
		case 0:
			bit0 = 1;
			break;
		case 1:
			bit1 = 1;
			break;
		case 2:
			bit2 = 1;
			break;
		case 3:
			bit3 = 1;
			break;
		case 4:
			bit4 = 1;
			break;
		case 5:
			bit5 = 1;
			break;
		case 6:
			bit6 = 1;
			break;
		case 7:
			bit7 = 1;
			break;
		}
		return *this;
	}
	TELEM operator|(TELEM t) {
		TELEM re;
		if ((bit0 = 1) || (t.bit0 = 1))
			re.bit0 = 1;
		else
			re.bit0 = 0;
		if ((bit1 = 1) || (t.bit1 = 1))
			re.bit1 = 1;
		else
			re.bit1 = 0;
		if ((bit2 = 1) || (t.bit2 = 1))
			re.bit2 = 1;
		else
			re.bit2 = 0;
		if ((bit3 = 1) || (t.bit3 = 1))
			re.bit3 = 1;
		else
			re.bit3 = 0;
		if ((bit4 = 1) || (t.bit4 = 1))
			re.bit4 = 1;
		else
			re.bit4 = 0;
		if ((bit5 = 1) || (t.bit5 = 1))
			re.bit5 = 1;
		else
			re.bit5 = 0;
		if ((bit6 = 1) || (t.bit6 = 1))
			re.bit6 = 1;
		else
			re.bit6 = 0;
		if ((bit7 = 1) || (t.bit7 = 1))
			re.bit7 = 1;
		else
			re.bit7 = 0;
		return re;
	}
	TELEM operator&(TELEM t) {
		TELEM re;
		if ((bit0 = 1) && (t.bit0 = 1))
			re.bit0 = 1;
		else
			re.bit0 = 0;
		if ((bit1 = 1) && (t.bit1 = 1))
			re.bit1 = 1;
		else
			re.bit1 = 0;
		if ((bit2 = 1) && (t.bit2 = 1))
			re.bit2 = 1;
		else
			re.bit2 = 0;
		if ((bit3 = 1) && (t.bit3 = 1))
			re.bit3 = 1;
		else
			re.bit3 = 0;
		if ((bit4 = 1) && (t.bit4 = 1))
			re.bit4 = 1;
		else
			re.bit4 = 0;
		if ((bit5 = 1) && (t.bit5 = 1))
			re.bit5 = 1;
		else
			re.bit5 = 0;
		if ((bit6 = 1) && (t.bit6 = 1))
			re.bit6 = 1;
		else
			re.bit6 = 0;
		if ((bit7 = 1) && (t.bit7 = 1))
			re.bit7 = 1;
		else
			re.bit7 = 0;
		return re;
	}
	TELEM operator~() {
		TELEM re;
		if (bit0 = 1)
			re.bit0 = 0;
		else
			re.bit0 = 1;
		if (bit1 = 1)
			re.bit1 = 0;
		else
			re.bit1 = 1;
		if (bit2 = 1)
			re.bit2 = 0;
		else
			re.bit2 = 1;
		if (bit3 = 1)
			re.bit3 = 0;
		else
			re.bit3 = 1;
		if (bit4 = 1)
			re.bit4 = 0;
		else
			re.bit4 = 1;
		if (bit5 = 1)
			re.bit5 = 0;
		else
			re.bit5 = 1;
		if (bit6 = 1)
			re.bit6 = 0;
		else
			re.bit6 = 1;
		if (bit7 = 1)
			re.bit7 = 0;
		else
			re.bit7 = 01;
		return re;
	}
	int BitZn(int n) {
		switch (n) {
		case 0:
			return bit0;
			break;
		case 1:
			return bit1;
			break;
		case 2:
			return bit2;
			break;
		case 3:
			return bit3;
			break;
		case 4:
			return bit4;
			break;
		case 5:
			return bit5;
			break;
		case 6:
			return bit6;
			break;
		case 7:
			return bit7;
			break;
		}
	}
	int operator==(TELEM t) {
		if ((bit0 == t.bit0) && (bit1 == t.bit1) && (bit2 == t.bit2) && (bit3 == t.bit3) && (bit4 == t.bit4) && (bit5 == t.bit5) && (bit6 == t.bit6) && (bit7 == t.bit7))
			return 0;
		else
			return 1;
	}
	int operator !=(TELEM t) {
		if (*this == t)
			return 1;
		else
			return 0;
	}
};

class TBitField
{
private:
  int  BitLen; // длина битового поля - макс. к-во битов
  TELEM *pMem; // память для представления битового поля
  int  MemLen; // к-во эл-тов Мем для представления бит.поля
  size_t bitsInElem = 8;
  size_t shiftSize = 3;

  // методы реализации
  int   GetMemIndex(const int n) const; // индекс в pМем для бита n       (#О2)
  TELEM GetMemMask (const int n) const; // битовая маска для бита n       (#О3)
public:
  TBitField(int len);                //                                   (#О1)
  TBitField(const TBitField &bf);    //                                   (#П1)
  ~TBitField();                      //                                    (#С)

  // доступ к битам
  int GetLength(void) const;      // получить длину (к-во битов)           (#О)
  void SetBit(const int n);       // установить бит                       (#О4)
  void ClrBit(const int n);       // очистить бит                         (#П2)
  int  GetBit(const int n) const; // получить значение бита               (#Л1)

  // битовые операции
  int operator==(const TBitField &bf) const; // сравнение                 (#О5)
  int operator!=(const TBitField &bf) const; // сравнение
  TBitField& operator=(const TBitField &bf); // присваивание              (#П3)
  TBitField  operator|(const TBitField &bf); // операция "или"            (#О6)
  TBitField  operator&(const TBitField &bf); // операция "и"              (#Л2)
  TBitField  operator~(void);                // отрицание                  (#С)

  friend istream &operator>>(istream &istr, TBitField &bf);       //      (#О7)
  friend ostream &operator<<(ostream &ostr, const TBitField &bf); //      (#П4)
};
// Структура хранения битового поля
//   бит.поле - набор битов с номерами от 0 до BitLen
//   массив pМем рассматривается как последовательность MemLen элементов
//   биты в эл-тах pМем нумеруются справа налево (от младших к старшим)
// О8 Л2 П4 С2

#endif
