// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);
static TSet FAKE_SET(1);

TSet::TSet(int mp) : BitField(-1)
{
    if (mp > 0) {
        MaxPower = mp;
        TBitField b(mp);
        BitField = b;
    }
    else
        throw out_of_range("Set max power can not be less zero");
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(-1)
{
    *this = s;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(-1)
{
    BitField = bf;
    MaxPower = bf.GetLength();

}

TSet::operator TBitField()
{
    return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    if ((Elem < MaxPower) && (Elem >= 0)) {
        int n = BitField.GetBit(Elem);
        return n;
    }
    else
        return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if ((Elem < MaxPower)&&(Elem>=0)) {
    BitField.SetBit(Elem);
    }
    else
        throw out_of_range("You can not insert elem out of range 0..MaxPower-1");
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if ((Elem < MaxPower) && (Elem >=0)) {
    BitField.ClrBit(Elem);
    }
    else
        throw out_of_range("You can not delite elem out of range 0..MaxPower-1");
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return (*this).BitField==s.BitField;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    return (*this).BitField != s.BitField;
}

TSet TSet::operator+(const TSet &s) // объединение
{
    int m;
    if (MaxPower > s.GetMaxPower())
        m = MaxPower;
    else
        m = s.GetMaxPower();
    TSet st(MaxPower);
    st.BitField = BitField | s.BitField;
    return st;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    TSet st(MaxPower);
    st.BitField = BitField;
    st.BitField.SetBit(Elem);
    return st;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    TSet st(MaxPower);
    st.BitField = BitField;
    st.BitField.ClrBit(Elem);
    return st;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    int m;
    if (MaxPower < s.GetMaxPower())
        m = MaxPower;
    else
        m = s.GetMaxPower();
    TSet st(m);
    st.BitField = BitField & s.BitField;
    return st;
}

TSet TSet::operator~(void) // дополнение
{
    TSet st(MaxPower);
    st.BitField = ~BitField;
    return st;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{

    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
    for (int i = 0; i < s.GetMaxPower(); i++) {
        if (s.IsMember(i) == 1)
            ostr << i << " ";
    }
    return ostr;
}
