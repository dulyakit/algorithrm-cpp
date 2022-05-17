/******************************************************************************

    Author      : Dulyakit Phommachat
    Code        : 61172110078-6
    Section     : CPE.61241
    Lab No.     : 1
    Course      : 04-061-212 Data Structures and Algorithms Laboratory
    Due Date    : 22/04/2022
    Instruction : A.Supattra Kerdmec
    Description : 14. จงเขียนโปรแกรมในการอ่านค่าสายอักขระ (String) โดยรับค่าสายอักขระมาจากผู้ใช้ 2 ค่า และตรวจสอบว่าสายอักขระที่ 2 เป็นส่วนของสายอักขระที1 หรือไม่

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findString(string Str1, string Str2) {

    std::vector< char > arr;

    for (int i = 0; i < Str1.size(); i++) {     //วนลูปนำตัวอักขระแต่ละตัวใน Str1 ไปตรวจสอบอักขระแต่ละตัวใน Str2 (ขั้นตอนนี้จะค่อนข้างเปลืองทรัพยากร)
        for (int j = 0; j < Str2.size(); j++) {
            if (Str2[j] == Str1[i]) {
                arr.push_back(Str2[j]);         //เมื่อเจอตัวอักขระที่เหมือนกันจะเพิ่ม element เข้าไปใน array
            }
        }
    }

    if (arr.size() != 0) {  //หากขนาดของ array ไม่เท่ากับ 0 โปรแกรมจะแสดง is a substring of Str1
        cout << "String1: " << Str1 << ", String1: " << Str2 << ", Result: Str2 is a substring of Str1 " << endl;
    }
    else {
        cout << "String1: " << Str1 << ", String1: " << Str2 << ", Result: Str2 is not a substring of Str1 " << endl;
    }
}

int main()
{
    string Str1;
    string Str2;

    //รับค่าอักขระที่ 1 และ 2
    std::cin >> Str1;
    std::cin >> Str2;

    //เรียกใช้ฟังก์ชั่นค้นหาอักขระ
    findString(Str1, Str2);

    return 0;
}
