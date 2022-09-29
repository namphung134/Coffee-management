#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <iomanip>
#define MAX 100
using namespace std;

struct CoffeeShop
{
    int ID;
    char nameNV[100];
    char addressNV[100];
    char phoneNumberNV[15];
    char sexNV[5];
    int ageNV;
    char cccd[20];
    // int soLuongNV = 0;
    // int demID = 0; // đếm số lượng
};

struct Warehouse
{
    int IDSP;
    char nameSP[50];
    int priceSP;
    int quantitySP;
};

struct paymentBill
{
    int ID;
    int payment;    // tiền bill
    int collect;    // thu
    int spend;  // chi
    int status; // tình trạng
};

typedef CoffeeShop CS;
typedef Warehouse WH;
typedef paymentBill Bill;

void mainMenu(WH b[],Bill c[], int &qtyBill);

void orderCoffee(WH b[],Bill c[], int &qtyBill);
void admin(WH b[],Bill c[], int &qtyBill);

void nhapNhanVienMoi(CS a[], int demID, int soLuongNV);
void displayThongTinNV(CS a[], int demID, int soLuongNV);
void modifyThongTinNV(CS a[], int demID, int soLuongNV);
void deleteThongTinNV(CS a[], int demID, int soLuongNV);

void khoDefault(WH b[]);
void hienThiKho(WH b[]);
void modifyKho(WH b[]);

void hienThiDoanhThu(WH b[], Bill c[], int &qtyBill);
int calCommodity(WH b[]);
int calFund(Bill c[], int &qtyBill);

void cls();
void printLine(int n);

// hàm main

int main()
{
    // CS arrayCS[MAX];
    // WH arrayWH[MAX];

    cout << "\n WELLCOME TO";
//    sleep(1);
    cout << "\n\n     COFFEEE SHOP\n";

    getch();
    cls();

    // Warehouse *WH;
    WH arrayWH[MAX];

    khoDefault(arrayWH);

    // paymentBill *Bill;
    Bill arrayBill[MAX];
    int qtyBill = 0;


    mainMenu(arrayWH,arrayBill,qtyBill);
}

// hàm in ra dòng với n, vd: n = 5 thì in ra 5 kí tự "_" là: _____

void printLine(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "_";
    }
    cout << "\n";
}

// hàm system("cls")

void cls()
{
    system("cls");
}

// hàm menu

void mainMenu(WH arrayWH[],Bill arrayBill[], int &qtyBill)
{
    int choice;
    cls();
    while (choice < 1 || choice > 3)
    {
        cout << "\n\t\t1. Order coffee";
        cout << "\n\t\t2. Admin";
        cout << "\n\t\t3. Exit";
        cout << "\nenter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            orderCoffee(arrayWH,arrayBill,qtyBill);
            break;

        case 2:
            admin(arrayWH,arrayBill,qtyBill);
            break;

        case 3:
            getch();
            cls();
            mainMenu(arrayWH,arrayBill,qtyBill);
            break;

        default:
            cout << "\nban da nhap sai, hay nhap lai . . .";
            getch();
            mainMenu(arrayWH,arrayBill,qtyBill);
            break;
        }
    }
}

void orderCoffee(WH arrayWH[],Bill arrayBill[], int &qtyBill)
{
// order cofee
part1:
    int n, pay, sum = 0;
    int no[10];
    int price[10];
    string name[100];

    cout << "\nCoffee List: \n";
    cout << "  _________________________________________________________________" << endl;
    cout << " | No.  |               ITEM NAME                 |     PRICE     | " << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 1.   |   Black coffee                          |     15.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 2.   |   Milk coffee                           |     17.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 3.   |   Americano                             |     30.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 4.   |   Latte                                 |     35.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 5.   |   Espresso                              |     35.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 6.   |   Capuchino                             |     35.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 7.   |   SaiGon black Coffee                   |     25.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 8.   |   SaiGon milk Coffee                    |     27.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 9.   |   Bac xiu                               |     25.000 vnd|" << endl;
    cout << " |----------------------------------------------------------------| " << endl;
    cout << " | 10.  |   Dua Coffee                            |     30.000 vnd| " << endl;
    cout << " |----------------------------------------------------------------|" << endl;
    cout << endl;

    cout << "so luong ban muon order: ";
    cin >> n;
    if (n > 0 && n < 100)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ": ";
            cin >> no[i];

            if (no[i] == 1)
            {
                name[i] = "Black coffee";
                price[i] = 15000;
            }
            else if (no[i] == 2)
            {
                name[i] = "Milk coffee";
                price[i] = 17000;
            }
            else if (no[i] == 3)
            {
                name[i] = "Americano";
                price[i] = 30000;
            }
            else if (no[i] == 4)
            {
                name[i] = "Latte";
                price[i] = 35000;
            }
            else if (no[i] == 5)
            {
                name[i] = "Espresso";
                price[i] = 35000;
            }
            else if (no[i] == 6)
            {
                name[i] = "Capuchino";
                price[i] = 35000;
            }
            else if (no[i] == 7)
            {
                name[i] = "SaiGon black Coffee";
                price[i] = 25000;
            }
            else if (no[i] == 8)
            {
                name[i] = "SaiGon milk Coffee";
                price[i] = 27000;
            }
            else if (no[i] == 9)
            {
                name[i] = "Bac xiu";
                price[i] = 25000;
            }
            else if (no[i] == 10)
            {
                name[i] = "Dua Coffee";
                price[i] = 30000;
            }
            sum = sum + price[i];
        }
        cout << "\n1. Back to order coffee";
        cout << "\n2. Thanh toan";
        int op1;
        cout << "\n\nnhap option: ";
        cin >> op1;
        switch (op1)
        {
        case 1:
            goto part1;
            break;
        case 2:
            cls();
            cout << "---------------------------------------------------------------------\n";
            cout << "TT" << setw(30) << "Item" << setw(30) << "Cost" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "---------------------------------------------------------------------\n";
                cout << i + 1 << setw(30) << name[i] << setw(30) << price[i] << endl;

                // trừ số lượng sp trong kho
                arrayWH[no[i]].quantitySP--;
            }
            cout << "======================================================================\n";
            cout << "Thanh Tien:" << setw(50) << sum;
            cout << "\n---------------------------------------------------------------------\n\n\n";
            cout << "Thanh Toan: " << setw(50) << sum << endl;
            cout << "Tien Khach dua: ";
            cin >> pay;
            if (pay >= sum)
            {
                cout << "TIEN THUA: " << setw(50) << pay - sum << endl;

                // lưu dữ liệu thanh toán
                arrayBill[qtyBill+1].spend = pay - sum;
            }
            else
            {
                cout << "So tien khong du.";

                // lưu dữ liệu thanh toán
                arrayBill[qtyBill+1].spend = 0;
            }

            // lưu dữ liệu thanh toán
            arrayBill[qtyBill+1].payment = sum;
            arrayBill[qtyBill+1].collect = pay;
            arrayBill[qtyBill+1].status = arrayBill[qtyBill+1].collect - arrayBill[qtyBill+1].spend;

            cout << "\n1. Back to order coffee";
            cout << "\n2. In hoa don";

            int op2;
            cout << "\nenter option: ";
            cin >> op2;
            switch (op2)
            {
            case 1:
                goto part1;
                break;
            case 2:
                //lưu dữ liệu doanh thu
                qtyBill++;
                arrayBill[qtyBill].ID = qtyBill;

                cout << "\nPress any key de in hoa don . . .";
                cls();

                cout << "                      ----<<    HOA-DON    >>----     \n\n";
                cout << "TT";
                cout << setw(35) << "TEN DICH VU";
                cout << setw(15) << "DON GIA";
                cout << setw(13) << "THANH TIEN";
                cout << endl;
                cout << "---------------------------------------------------------------------" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << i + 1;
                    cout << setw(35) << name[i];
                    cout << setw(15) << price[i];
                    cout << setw(13) << price[i];
                    cout << endl;
                }
                cout << "====================================================================" << endl;
                cout << endl;
                cout << "THANH TIEN: " << setw(40) << sum << endl;
                cout << endl;
                cout << "---------------------------------------------------------------------" << endl;
                cout << endl;
                cout << "THANH TOAN: " << setw(40) << sum << endl;
                cout << endl;
                cout << "TIEN KHACH DUA: " << setw(38) << pay << endl;
                if ((pay - sum) >= 0)
                {
                    cout << "TIEN THUA: " << setw(40) << pay - sum << endl;
                }
                else
                {
                    cout << "So tien khong du." << endl;
                }
                cout << endl;
                cout << "====<<  CAM ON QUY KHACH DA SU DUNG DICH VU CUA CHUNG TOI  >>=====" << endl;
                cout << endl;
                cout << "======================<<   HEN-GAP-LAI   >>=======================";
                getch();
                cls();
                mainMenu(arrayWH,arrayBill,qtyBill);
                break;
            default:
                break;
            }
        }
    }
}

void admin(WH arrayWH[],Bill arrayBill[], int &qtyBill)
{
    // CoffeeShop *CS;
    CS arrayCS[MAX];
    int soLuongNV = 0;
    int demID = 0; // đếm số lượng
    // Warehouse *WH;
    cls();
// NHAP MAT KHAU DE DANG NHAP VAO ADMIN
admin1:
    char c = 0, x[20];
    int i = 0;
    cout << "PASS:";
    while (1)
    {
        c = getch();
        if (c == 13)
        {
            break;
        }
        else
        {
            x[i++] = c;
            cout << "*";
        }
    }
    x[i] = '\0';
    if (strcmp(x, "123456") == 0)
    {
        cout << endl
             << "Successful!";

        cls();
        while (true)
        {

            int choice;
            cout << "\n                      ----<<   ADMIN   >>----     " << endl;
            cout << "\n\t\t1. Them nhan vien moi";
            cout << "\n\t\t2. Hien thi thong tin nhan vien";
            cout << "\n\t\t3. Chinh sua thong tin nhan vien";
            cout << "\n\t\t4. Xoa thong tin nhan vien";
            cout << "\n\t\t5. Hien thi thong tin Kho";
            cout << "\n\t\t6. Chinh sua thong tin Kho";
            cout << "\n\t\t7. Hien thi tong doanh thu";
            cout << "\n\t\t0. Exit" << endl;
            cout << "\n\t\tNhap lua chon: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                demID++;
                nhapNhanVienMoi(arrayCS, demID, soLuongNV);
                soLuongNV++;
                break;
            case 2:
                displayThongTinNV(arrayCS, demID, soLuongNV);
                getch();
                cls();
                break;
            case 3:
                modifyThongTinNV(arrayCS, demID, soLuongNV);
                break;
            case 4:
                deleteThongTinNV(arrayCS, demID, soLuongNV);
                break;
            case 5:
                hienThiKho(arrayWH);
                break;
            case 6:
                modifyKho(arrayWH);
                break;
            case 7:
                hienThiDoanhThu(arrayWH, arrayBill, qtyBill);
                break;
            case 0:
                cout << "\nthoat chuong trinh";
                cls();
                mainMenu(arrayWH,arrayBill,qtyBill);
                break;

            default:
                cout << "\nnon value . . .\n";
                cls();
                break;
            }
        }
    }
    else
    {
        cout << endl
             << "Failure!" << endl;
        goto admin1;
    }

    getch();
}

void nhapNhanVienMoi(CS a[], int demID, int soLuongNV)
{
    cls();
    cout << "\nNhap thong tin nhan vien moi: \n";
    printLine(50);
    a[demID].ID = demID;
    cout << "\nnhan vien thu " << demID << endl;
    cout << "\nNhap nhan vien thu " << soLuongNV + 1 << ": ";
    cout << "\nEnter name: ";
    cin.ignore();
    cin.getline(a[demID].nameNV, 99);
    cout << "\nEnter address: ";
    cin.ignore();
    cin.getline(a[demID].addressNV, 99);
    cout << "\nEnter phone number: ";
    cin.ignore();
    cin.getline(a[demID].phoneNumberNV, 14);
    cout << "\nEnter sex: ";
    cin.ignore();
    cin.getline(a[demID].sexNV, 4);
    cout << "\nEnter age: ";
    cin >> a[demID].ageNV;
    cout << "\nEnter Identidy card: ";
    cin.ignore();
    cin.getline(a[demID].cccd, 19);

    cout << "\nDa them thong tin nhan vien thanh cong !\n";
    getch();
    cls();
}

void displayThongTinNV(CS a[], int demID, int soLuongNV)
{
    cls();
    if (soLuongNV > 0)
    {
        cout << "                      ----<<    STAFF INFORMATION    >>----     \n\n";
        printLine(100);
        cout << setw(5) << "ID";
        cout << setw(5) << "NAME";
        cout << setw(15) << "AGE";
        cout << setw(15) << "SEX";
        cout << setw(20) << "ADDRESS";
        cout << setw(20) << "PHONE";
        cout << setw(20) << "IDENTIDY CARD" << endl;
        for (int i = 0; i < demID; i++)
        {
            cout << setw(5) << a[i + 1].ID;
            cout << setw(5) << a[i + 1].nameNV;
            cout << setw(15) << a[i + 1].ageNV;
            cout << setw(15) << a[i + 1].sexNV;
            cout << setw(20) << a[i + 1].addressNV;
            cout << setw(20) << a[i + 1].phoneNumberNV;
            cout << setw(20) << a[i + 1].cccd << endl;
            printLine(100);
        }
        printLine(100);
    }
    else
    {
        cout << "\nKhong co thong tin nhan vien nao de hien thi . . .\n";
    }

    cout << "\nPress any key to continue . . .";
    getch();
    cls();
}

void modifyThongTinNV(CS a[], int demID, int soLuongNV)
{
    cls();
    printLine(50);
    if (soLuongNV > 0)
    {
        int id;
        cout << "\nnhap id nhan vien ban muon chinh sua: ";
        cin >> id;
        for (int i = 0; i < demID; i++)
        {
            printLine(50);
            if (a[i + 1].ID == id)
            {
                cout << "\nHay chinh sua thong tin cua nhan vien có ID " << id << ": \n";
                cout << "\nEnter name: ";
                cin.ignore();
                cin.getline(a[demID].nameNV, 99);
                cout << "\nEnter address: ";
                cin.ignore();
                cin.getline(a[demID].addressNV, 99);
                cout << "\nEnter phone number: ";
                cin.ignore();
                cin.getline(a[demID].phoneNumberNV, 14);
                cout << "\nEnter sex: ";
                cin.ignore();
                cin.getline(a[demID].sexNV, 4);
                cout << "\nEnter age: ";
                cin >> a[demID].ageNV;
                cout << "\nEnter Identidy card: ";
                cin.ignore();
                cin.getline(a[demID].cccd, 19);

                cout << "\nDa chỉnh sua thong tin nhan vien thanh cong !\n";
            }
        }
    }
    else
    {
        cout << "\nkhong ton tai nhan vien . . .\n";
    }
    cout << "\nPress any key to continue . . .";
    getch(); // hàm này dùng để nhấn nút tiếp theo thoát màn hình
    cls();
}

void deleteThongTinNV(CS a[], int demID, int soLuongNV)
{
    cls();
    printLine(50);
    if (soLuongNV > 0)
    {
        int id;
        cout << "nhap nhan vien co so id ban muon xoa: ";
        cin >> id;
        for (int i = 1; i <= demID; i++)
        {
            if (a[i].ID == id)
            {
                for (int j = i; j <= demID; j++)
                {
                    a[j] = a[j + 1]; // xoa thong tin cua mang a[i], thay the thong tin cua mang a[i] = a[i + 1];
                }
                cout << "\nda xoa thong tin nhan vien co id " << id << " thanh cong !";
                soLuongNV--;
            }
        
        }
    }
    else
    {
        cout << "khong ton tai nhan vien . . .\n";
    }
    cout << "\nPress any key to continue . . .";
    getch(); // hàm này dùng để nhấn nút tiếp theo thoát màn hình
    cls();
}

void hienThiKho(WH b[])
{
    cls();
    cout << "                      ----<<    WAREHOUSE    >>----     \n\n";
    printLine(100);
    cout << setw(10) << "IDSP";
    cout << setw(35) << "NAME SP";
    cout << setw(30) << "PRICE";
    cout << setw(25) << "QUANTITY" << endl;
    printLine(100);
    for (int i = 1; i <= 10; i++)
    {
        cout << setw(10) << b[i].IDSP;
        cout << setw(35) << b[i].nameSP;
        cout << setw(30) << b[i].priceSP;
        cout << setw(25) << b[i].quantitySP << endl;
        printLine(100);
    }

    cout << "\nPress any key to continue . . .";
    getch(); // nhấn enter tiếp theo thoát màn hình
    cls();
};

void modifyKho(WH b[])
{
    cls();
    printLine(50);
    int id;
    cout << "\nnhap id san pham ban muon chinh sua: ";
    cin >> id;
    printLine(50);
    for (int i = 1; i <= 10; i++)
    {
        if (b[i].IDSP == id)
        {
            cout << "\nHay chinh sua thong tin cua san pham co ID " << id << ": \n";
            cout << "\nEnter name SP: ";
            cin.ignore();
            cin.getline(b[i].nameSP, 99);
            cout << "\nEnter gia SP: ";
            cin.ignore();
            cin >> b[i].priceSP;
            cout << "\nEnter so luong SP: ";
            cin.ignore();
            cin >> b[i].quantitySP;

            cout << "\nDa chinh sua thong tin san pham thanh cong !\n";
        }
    }
    printLine(50);
    cout << "\nPress any key to continue . . .";
    getch(); // nhấn enter tiếp theo thoát màn hình
    cls();
};

void khoDefault(WH b[])
{
    for (int i = 1; i <= 10; i++){
        b[i].IDSP = i;
        b[i].quantitySP = 100;
    }

    // b[1].nameSP = "Black coffee";
    strncpy(b[1].nameSP, "Black coffee", sizeof(b[1].nameSP));
    b[1].priceSP = 15000;
    // b[2].nameSP = "Milk coffee";
    strncpy(b[2].nameSP, "Milk coffee", sizeof(b[2].nameSP));
    b[2].priceSP = 17000;
    // b[3].nameSP = "Americano";
    strncpy(b[3].nameSP, "Americano", sizeof(b[3].nameSP));
    b[3].priceSP = 30000;
    // b[4].nameSP = "Latte";
    strncpy(b[4].nameSP, "Latte", sizeof(b[4].nameSP));
    b[4].priceSP = 35000;
    // b[5].nameSP = "Espresso";
    strncpy(b[5].nameSP, "Espresso", sizeof(b[5].nameSP));
    b[5].priceSP = 35000;
    // b[6].nameSP = "Capuchino";
    strncpy(b[6].nameSP, "Capuchino", sizeof(b[6].nameSP));
    b[6].priceSP = 35000;
    // b[7].nameSP = "SaiGon black Coffee";
    strncpy(b[7].nameSP, "SaiGon black Coffee", sizeof(b[7].nameSP));
    b[7].priceSP = 25000;
    // b[8].nameSP = "SaiGon milk Coffee";
    strncpy(b[8].nameSP, "SaiGon milk Coffee", sizeof(b[8].nameSP));
    b[8].priceSP = 27000;
    // b[9].nameSP = "Bac xiu";
    strncpy(b[9].nameSP, "Bac xiu", sizeof(b[9].nameSP));
    b[9].priceSP = 25000;
    // b[10].nameSP = "Dua Coffee";
    strncpy(b[10].nameSP, "Dua Coffee", sizeof(b[10].nameSP));
    b[10].priceSP = 30000;
}

void hienThiDoanhThu(WH b[], Bill c[], int &qtyBill)
{
    cls();
    cout << "\n";
    cout << "                      ----<<    SALES    >>----     \n\n";
    cout << setw(33) << "Commodity";
    cout << setw(33) << "Fund";
    cout << setw(33) << "Bill quantity" << endl;
    printLine(100);
    cout << setw(33) << calCommodity(b);
    cout << setw(33) << calFund(c,qtyBill);
    cout << setw(33) << qtyBill << endl;

    printLine(100);
    cout << "\n";
    cout << "===<< Bills >>===\n\n";
    printLine(100);
    cout << setw(10) << "ID";
    cout << setw(20) << "PAYMENT";
    cout << setw(20) << "COLLECT";
    cout << setw(20) << "SPEND";
    cout << setw(30) << "STATUS" << endl;
    printLine(100);
    for (int i = 1; i <= qtyBill; i++)
    {
        cout << setw(10) << c[i].ID;
        cout << setw(20) << c[i].payment;
        cout << setw(20) << c[i].collect;
        cout << setw(20) << c[i].spend;
        cout << setw(30) << c[i].status << endl;
        printLine(100);
    }

    cout << "\nPress any key to continue . . .";
    getch(); // nhấn enter tiếp theo thoát màn hình
    cls();
};

int calCommodity(WH b[])
{
    int x = 0;
    for(int i=1; i<=10; i++) {
        x += b[i].priceSP*b[i].quantitySP;
    }
    return x;
};
int calFund(Bill c[], int &qtyBill)
{
    int x = 0;
    for(int i=1; i<=qtyBill; i++) {
        x += c[i].status;
    }
    return x;
};
