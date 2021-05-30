//---------------------------------------------------------------------------
//  �����������:
//
//   1) ������������� ������ ��� Borland C++ Builder, ��� ��� � �� ������ ���
//      � Visual Studio ���� vcl.h �� �������� ������������ ������� StrToInt.
//   2) ���������� ���� �������� �� �������� ������, ��� ��� ����� + ����� =
//      ����������. ����� ���� ������� �������� � ������ ������, �� ��� �����.
//   3) ����������� ������� Sum ������������ ��� ��������� ������� ����������.
//      ������� � ������ ���� ��� � ������ � ������ 2. ��� ������� - ����������
//      ����� dynamic_cast �� ����� ��, ��� ����� (� �� ����� �� � ����� ���
//      ��������)
//   4) getX, setX, getR, setR - ��������� �� ��� �������� ��� �������� (�� � �
//      �� ������ ��� �� ����� �������� ���������).
//   5) � ������ ������ 2 � 3 - � ������� ����� Sum ������� � ����� ���������
//      ��� ���� ������ ���������� == -1, �� ��� �����. ������� ������ � ��������
//      ��� ����������� ���������� (����� ����������� ���������� ��� ��������).
//   6) ���������� ����� ��������������: ���� ��� ������� �� �� �����������
//      �������� ��������, �� � ����� ���������.
//   7) �� ��������������� ������������� ����� ���������� �� saf_and@tut.by
//
//                      ������� ������. ���, ����, 2 ����, 3 ������.
//                      25.12.2008
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vcl.h>

using namespace std;

//---------------------------------------------------------------------------

//����� �����
class TmyPoint {
        protected:
                //���������� �������
                int FX;
        public:
                //�������� ����������
                int getX() {
                        return FX;
                }
                //���������� ����������
                void setX(int X) {
                        FX = X;
                }
                //����������� �� ����������
                TmyPoint(int X = 0) {
                        FX = X;
                }
                //����������� �� �����
                TmyPoint(const TmyPoint& p) {
                        TmyPoint(p.FX);
                }
                //�������� ������������
                TmyPoint operator = (TmyPoint& p) {
                        setX(p.getX());
                        return *this;
                }
                //�������� ���������� �� �������
                virtual AnsiString Info() {
                        return "TmyPoint (X=" + IntToStr(getX()) + ")";
                }
                //������� ����� ���������� �������� (������ �����������)
                virtual int Sum() {
                        return getX();
                }
};

//����� ����������
class TmyRound : public TmyPoint {
        protected:
                //������ �������
                int FR;
        public:
                //�������� ������
                int getR() {
                        return FR;
                }
                //���������� ������
                void setR(int R) {
                        FR = R;
                }
                //����������� �� ���������� � �������
                TmyRound(int X = 0, int R = 1) {
                        setX(X);
                        FR = R;
                }
                //���������� �� ����������
                TmyRound(const TmyRound& r) {
                        TmyRound(r.FX, r.FR);
                }
                //�������� ������������
                TmyRound operator = (TmyRound& r) {
                        setX(r.getX());
                        setR(r.getR());
                        return *this;
                }
                //�������� ���������� �� �������
                virtual AnsiString Info() {
                        return "TmyRound (X=" + IntToStr(getX()) + " R=" + IntToStr(getR()) + ")";
                }
                //������� ����� ���������� �������� (������ �����������)
                virtual int Sum() {
                        return getX() + getR();
                }

};

//---------------------------------------------------------------------------

//������� ���������� �� ��������
ostream& operator << (ostream& out, TmyPoint& p) {
        out << p.Info() << endl;
        return out;
}

//������� ���������� � ������� ���������
void outArr(TmyPoint* p[], int e) {
        for (int i=0; i < e; i++) cout << "a[" << i << "] = " << *p[i];
        cout << endl;
}

//�������� �����
TmyRound& operator + (TmyPoint& n1, TmyPoint& n2) {
        TmyRound* tmp = new TmyRound(n1.getX(), n2.getX());
        return *tmp;
}

//�������� �����������
TmyRound& operator + (TmyRound& n1, TmyRound& n2) {
        int m;
        if ((min(n1.getR(), n2.getR())) == -1) m = max(n1.getR(), n2.getR());
        else m = min(n1.getR(), n2.getR());
        TmyRound* tmp = new TmyRound(n1.getX()+n2.getX(), m);
        return *tmp;
}

//���������� + �����
TmyRound& operator + (TmyRound& n1, TmyPoint& n2) {
        TmyRound* tmp = new TmyRound(n1.getX()+n2.getX(), n1.getR());
        return *tmp;
}

//����� + ����������
TmyRound& operator + (TmyPoint& n1, TmyRound& n2) {
        return n2+n1;
}

//---------------------------------------------------------------------------

//���������� �� ��������
void Sort(TmyPoint* p[], int e) {
        for (int i=0; i < e; i++) {
                for (int j = 0; j<e-i-1; j++)
                        if ((*p[j]).getX() > (*p[j+1]).getX()) {
                                TmyPoint* pp = p[j];
                                (p[j]) = (p[j+1]);
                                (p[j+1]) = pp;
                        }
                }
}


//������� ����������?
bool IsTmyRound(TmyPoint& p) {
        return (p.Info()[4] == *"R");
}

//��������������� (���� �����, �� ������ = -1)
TmyRound& Convert(TmyPoint& p) {
        TmyRound* res;
        if (IsTmyRound(p)) res = new TmyRound(p.getX(), p.Sum() - p.getX());
        else res = new TmyRound(p.getX(), -1);
        return *res;
}

//������������ �� � ��
TmyPoint& Sum(TmyPoint* p[], int first, int last) {
        TmyRound* sum;
        sum = &Convert(*p[first]);
        for (int i=first+1; i<last; i++) *sum = *sum + Convert(*p[i]);
        if ((*sum).Sum() != ((*sum).getX()) - 1) return *sum;
        else {
                TmyPoint* sump;
                sump = new TmyPoint((*sum).getX());
                return *sump;
        }
}

//������������ �� � ����������
TmyPoint& SumC(TmyPoint* p[], int first, int count) {
        return Sum(p, first, count-first+2);
}

//---------------------------------------------------------------------------

int main()
{
        cout << "TASK 8\n\n";
        //������ 4 �������
        TmyPoint p1(12);
        TmyPoint p2(4);
        TmyRound r1(17, 22);
        TmyRound r2(-8, 3);
        //������� �� �� �������
        cout << "Objects :" << endl;
        cout << "p1 = " << p1;
        cout << "p2 = " << p2;
        cout << "r1 = " << r1;
        cout << "r2 = " << r2;
        cout << endl;
        //���������� ��� �������� ������������� ��������� ������������
        cout << "SUM :" << endl;
        cout << "p1 + p2 = " << p1 + p2;
        cout << "r1 + r2 = " << r1 + r2;
        cout << "p1 + r1 = " << p1 + r1;
        cout << "r2 + p1 = " << r2 + p1;
        cout << "r1 + r2 + p1 + p2 = " << r1 + r2 + p1 + p2;
        cout << endl;
        //���������� ��� �������� ������������
        cout<< "= :" << endl;
        p1 = p2;
        cout << "p1 = p2 : " << p1;
        r1 = r1 + r2;
        cout << "r1 = r1 + r2 : " << r1;
        cout << endl;
        //������������� ������ ���������� �� ��������
        cout<< "SORT :" << endl;
        TmyPoint* p[] = {&p1, &p2, &TmyRound(33,33), &TmyPoint(6), &r1, &r2};
        outArr(p, 6);
        Sort(p , 6);
        outArr(p, 6);
        //����� ����� ��������� ������� (����������������!)
        cout << "SUM ARRAY :" << endl;
        cout << "Sum p[0]-p[5] : " << Sum(p, 0, 6);
        cout << "Sum p[1]-p[3] : " << Sum(p, 1, 4);
        cout << "Sum p[1]-4 : " << SumC(p, 1, 4);
        //��������� ������, ��� ������� ������������
        cout << "\nEND OF TASK 8";
        cin.get();
        return 0;
}

//---------------------------------------------------------------------------
