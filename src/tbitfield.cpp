// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
    BitLen = len;
    int r = sizeof TELEM;
    MemLen = len / r;
    if (len % r > 0) {
        MemLen++;
    }
    pMem = new TELEM[MemLen]();
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    (*this) = bf;
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return (n >> shiftSize);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return 1<<(n&(bitsInElem-1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    int ind = (*this).GetMemIndex(n);
    TELEM mask = (*this).GetMemMask(n);
    pMem[ind] = pMem[ind] | mask;
}

void TBitField::ClrBit(const int n) // очистить бит
{
    int ind = (*this).GetMemIndex(n);
    TELEM mask = (*this).GetMemMask(n);
    pMem[ind] = pMem[ind] & (~mask);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    int ind = (*this).GetMemIndex(n);
    TELEM mask = (*this).GetMemMask(n);
    pMem[ind] = pMem[ind] & (mask);
    return pMem[ind];
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (MemLen != bf.MemLen) {
        MemLen = bf.MemLen;
        delete pMem;
        pMem = new TELEM[MemLen]();
    }
    BitLen = bf.BitLen;
    for (int i = 0; i < bf.MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    int k=0;
    if ((MemLen != bf.MemLen) || (BitLen != bf.BitLen)) {
        k = 1;
    }
    else {
        for (int i = 0; i < MemLen; i++) {
            if (pMem[i] != bf.pMem[i]) {
                k = 1;
                break;
            }
        }
    }
    return k;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    int k = 1;
    if ((MemLen != bf.MemLen) || (BitLen != bf.BitLen)) {
        k = 0;
    }
    else {
        for (int i = 0; i < MemLen; i++) {
            if (pMem[i] != bf.pMem[i]) {
                k = 0;
                break;
            }
        }
    }
    return k;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    TBitField res(BitLen);
    for (int i = 0; i < MemLen; i++) {
        res.pMem[i] = pMem[i] | bf.pMem[i];
    }
    return res;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    TBitField res(BitLen);
    for (int i = 0; i < MemLen; i++) {
        res.pMem[i] = pMem[i] & bf.pMem[i];
    }
    return res;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField res(BitLen);
    for (int i = 0; i < MemLen; i++) {
        res.pMem[i] = ~pMem[i];
    }
    return res;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string s;
    istr >> s;
    int l = s.size();
    TBitField t(l);
    for (int i = l - 1; i > -1; i--) {
        if (s[i] == 1) {
            t.SetBit(i);
        }
    }
    bf = t;
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    int n;
    for (int i = bf.BitLen - 1; i > -1; i--) {
        n = bf.GetBit(i);
        ostr << n;
    }
    return ostr;
}
