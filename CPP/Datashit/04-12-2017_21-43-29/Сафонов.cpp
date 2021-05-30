//---------------------------------------------------------------------------
//  Комментарии:
//
//   1) Компилировать только под Borland C++ Builder, так как я не уверен что
//      в Visual Studio есть vcl.h из которого используется функция StrToInt.
//   2) Перегрузка сумм вынесена за описание класса, так как точка + точка =
//      окружность. Можно было сделать описание и внутри класса, но так проще.
//   3) Виртуальные функции Sum используются для получения радиуса окружности.
//      Сделано с учётом того что я описал в пункте 2. Как вариант - реализуемо
//      через dynamic_cast но опять же, так проще (и не фактч то в курсе это
//      пройдено)
//   4) getX, setX, getR, setR - оформлены не как свойства для простоты (да и я
//      не уверен что на курсе свойства проходили).
//   5) С учётом пункта 2 и 3 - в функции суммы Sum массива я делаю допущение
//      что если радиус окружности == -1, то это точка. Поэтому делаем и проверку
//      при возвращении результата (чтобы возвращался корректный тип элемента).
//   6) Сортировку можно оптимизировать: если при проходе мы не переставили
//      ниодного элемента, то её можно завершить.
//   7) За дополнительными комментариями можно обращаться на saf_and@tut.by
//
//                      Сафонов Андрей. БГУ, ФПМИ, 2 курс, 3 группа.
//                      25.12.2008
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vcl.h>

using namespace std;

//---------------------------------------------------------------------------

//Класс точка
class TmyPoint {
        protected:
                //Координата объекта
                int FX;
        public:
                //Получить координату
                int getX() {
                        return FX;
                }
                //Установить координату
                void setX(int X) {
                        FX = X;
                }
                //Конструктор по координате
                TmyPoint(int X = 0) {
                        FX = X;
                }
                //Конструктор по точке
                TmyPoint(const TmyPoint& p) {
                        TmyPoint(p.FX);
                }
                //Оператор присваивания
                TmyPoint operator = (TmyPoint& p) {
                        setX(p.getX());
                        return *this;
                }
                //Получить информацию об объекте
                virtual AnsiString Info() {
                        return "TmyPoint (X=" + IntToStr(getX()) + ")";
                }
                //Вернуть сумму внутренних значений (смотри Комментарии)
                virtual int Sum() {
                        return getX();
                }
};

//Класс окружность
class TmyRound : public TmyPoint {
        protected:
                //Радиус объекта
                int FR;
        public:
                //Получить радиус
                int getR() {
                        return FR;
                }
                //Установить радиус
                void setR(int R) {
                        FR = R;
                }
                //Конструктор по координате и радиусу
                TmyRound(int X = 0, int R = 1) {
                        setX(X);
                        FR = R;
                }
                //Контруктор по окружности
                TmyRound(const TmyRound& r) {
                        TmyRound(r.FX, r.FR);
                }
                //Оператор присваивания
                TmyRound operator = (TmyRound& r) {
                        setX(r.getX());
                        setR(r.getR());
                        return *this;
                }
                //Получить информацию об объекте
                virtual AnsiString Info() {
                        return "TmyRound (X=" + IntToStr(getX()) + " R=" + IntToStr(getR()) + ")";
                }
                //Вернуть сумму внутренних значений (смотри Комментарии)
                virtual int Sum() {
                        return getX() + getR();
                }

};

//---------------------------------------------------------------------------

//Вывести информацию об элементе
ostream& operator << (ostream& out, TmyPoint& p) {
        out << p.Info() << endl;
        return out;
}

//Вывести информацию о массиве элементов
void outArr(TmyPoint* p[], int e) {
        for (int i=0; i < e; i++) cout << "a[" << i << "] = " << *p[i];
        cout << endl;
}

//Сложение точек
TmyRound& operator + (TmyPoint& n1, TmyPoint& n2) {
        TmyRound* tmp = new TmyRound(n1.getX(), n2.getX());
        return *tmp;
}

//Сложение окружностей
TmyRound& operator + (TmyRound& n1, TmyRound& n2) {
        int m;
        if ((min(n1.getR(), n2.getR())) == -1) m = max(n1.getR(), n2.getR());
        else m = min(n1.getR(), n2.getR());
        TmyRound* tmp = new TmyRound(n1.getX()+n2.getX(), m);
        return *tmp;
}

//Окружность + точка
TmyRound& operator + (TmyRound& n1, TmyPoint& n2) {
        TmyRound* tmp = new TmyRound(n1.getX()+n2.getX(), n1.getR());
        return *tmp;
}

//Точка + окружность
TmyRound& operator + (TmyPoint& n1, TmyRound& n2) {
        return n2+n1;
}

//---------------------------------------------------------------------------

//Сортировка по убыванию
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


//Элемент окружность?
bool IsTmyRound(TmyPoint& p) {
        return (p.Info()[4] == *"R");
}

//Конвертирование (если точка, то радиус = -1)
TmyRound& Convert(TmyPoint& p) {
        TmyRound* res;
        if (IsTmyRound(p)) res = new TmyRound(p.getX(), p.Sum() - p.getX());
        else res = new TmyRound(p.getX(), -1);
        return *res;
}

//Суммирование от и до
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

//Суммирование от и количество
TmyPoint& SumC(TmyPoint* p[], int first, int count) {
        return Sum(p, first, count-first+2);
}

//---------------------------------------------------------------------------

int main()
{
        cout << "TASK 8\n\n";
        //Создаём 4 объекта
        TmyPoint p1(12);
        TmyPoint p2(4);
        TmyRound r1(17, 22);
        TmyRound r2(-8, 3);
        //Выводим их на консоль
        cout << "Objects :" << endl;
        cout << "p1 = " << p1;
        cout << "p2 = " << p2;
        cout << "r1 = " << r1;
        cout << "r2 = " << r2;
        cout << endl;
        //Показываем как работают перегруженные операторы суммирования
        cout << "SUM :" << endl;
        cout << "p1 + p2 = " << p1 + p2;
        cout << "r1 + r2 = " << r1 + r2;
        cout << "p1 + r1 = " << p1 + r1;
        cout << "r2 + p1 = " << r2 + p1;
        cout << "r1 + r2 + p1 + p2 = " << r1 + r2 + p1 + p2;
        cout << endl;
        //Показываем как работает присваивание
        cout<< "= :" << endl;
        p1 = p2;
        cout << "p1 = p2 : " << p1;
        r1 = r1 + r2;
        cout << "r1 = r1 + r2 : " << r1;
        cout << endl;
        //Демонстрируем работу сортировки по убыванию
        cout<< "SORT :" << endl;
        TmyPoint* p[] = {&p1, &p2, &TmyRound(33,33), &TmyPoint(6), &r1, &r2};
        outArr(p, 6);
        Sort(p , 6);
        outArr(p, 6);
        //Вывод суммы элементов массива (отсортированного!)
        cout << "SUM ARRAY :" << endl;
        cout << "Sum p[0]-p[5] : " << Sum(p, 0, 6);
        cout << "Sum p[1]-p[3] : " << Sum(p, 1, 4);
        cout << "Sum p[1]-4 : " << SumC(p, 1, 4);
        //Закончили работу, ждём реакции пользователя
        cout << "\nEND OF TASK 8";
        cin.get();
        return 0;
}

//---------------------------------------------------------------------------
