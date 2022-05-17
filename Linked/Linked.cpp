/******************************************************************************
    Author      : Dulyakit Phommachat
    Code        : 61172110078-6
    Section     : CPE.61241
    Lab No.     : 2
    Course      : 04-061-212 Data Structures and Algorithms Laboratory
    Due Date    : 24/04/2022
    Instruction : A.Supattra Kerdmec
    Description : ให้เขียนโปรแกรมเพือทําการจําลองการทํางานของ Doubly Linked List โดยใช้ Pointer Based Implementation สําหรับข้อมูลทีแต่ละโหนดใน List เก็บกําหนดให้เป็นเลขจํานวนเต็ม  ตัว ส่วนการเลือกทํา Operationจะให้รับข้อมูลเข้าเป็นจํานวนเต็มระหว่าง 1-9
    language    : C++
*******************************************************************************/

#include <iostream>

using namespace std;
using std::string;

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* last = NULL;

void isEmpty() {
    //กำหนดให้ res มีค่าเป็น yes หาก linked_list ไม่มีค่า และ no หาก linked_list มีค่า
    string res = head == NULL ? "yes \n" : "no \n";
    cout << res << "\n";
}

void getSize() {
    int length = 0;
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));

    //วนลูป linked_list ทุกตำแหน่งและเพิ่มค่าให้ตัวแปร length ตามจำนวนข้อมูลที่วนลูป จะได้ขนาดของ linked_list
    for (current = head; current != NULL; current = current->next) {
        length++;
    }

    cout << length << "\n\n";
}

void insertFirst(int newdata) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));   //สร้าง newNode ขึ้นมาใหม่
    newNode->data = newdata;    //กำหนดให้ข้อมูลของ newNode มีค่าเท่ากับค่าที่ input
    newNode->next = head;       //กำหนดให้ตำแหน่งถัดไปของ newNode เป็นค่า linked_list ของ head
    head = newNode;             //กำหนดให้ head มีค่าเท่ากับ newNode
    //จะได้ข้อมูลที่ input เข้ามาอยู่หน้าสุด ตามด้วยข้อมูลเดิมของ head เรียงต่อกันตามลำดับ
}

void insertLast(int newdata) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));    //สร้าง newNode ขึ้นมาใหม่
    newNode->data = newdata;    //กำหนดให้ข้อมูลของ newNode มีค่าเท่ากับค่าที่ input
    newNode->next = NULL;       //กำหนดให้ตำแหน่งถัดไปของ newNode เป็น NULL
    //จะได้ linked_list ที่มีค่าเท่ากับ input เพียงค่าเดียว

    struct Node* temp = head;       //สร้าง temp ขึ้นมาให้เท่ากับ head (ทั้งสองตัวจะมีค่าเท่ากันทั้งตอนปัจจุบันและตอนที่ตัวใดตัวหนึ่งเปลี่ยนแปลงค่า)
    while (temp->next != NULL) {    //วนลูปข้อมูลใน temp จนกว่าตำแหน่งถัดไปจะเป็น NULL
        temp = temp->next;          //กำหนดค่าให้ temp เท่ากับตำแหน่งถัดไปเรื่อยๆจนถึงตำแหน่งสุดท้าย
    }
    temp->next = newNode;           //กำหนดให้ตำแหน่งถัดไปจากตำแหน่งสุดท้ายของ temp เป็นค่าของ newNode
}

void removeFirst(){
    head = head->next;      //ขยับให้ตำแหน่งแรกแทนที่ด้วยค่าของตำแหน่งถัดไปตามลำดับ
}

void removeLast() {
    struct Node* temp = head;               //สร้าง temp ขึ้นมาให้เท่ากับ head (ทั้งสองตัวจะมีค่าเท่ากันทั้งตอนปัจจุบันและตอนที่ตัวใดตัวหนึ่งเปลี่ยนแปลงค่า)
    while (temp->next->next != NULL) {      //วนลูปข้อมูลใน temp จนกว่าตำแหน่งถัดไป 2 ตำแหน่งจะเป็น NULL
        temp = temp->next;                  //กำหนดค่าให้ temp เท่ากับตำแหน่งถัดไปเรื่อยๆจนถึงตำแหน่งรองสุดท้าย
    }
    temp->next = NULL;                      //กำหนดให้ตำแหน่งถัดไปหรือตำแหน่งสุดท้ายเป็น NULL
}

void displayList() {
    struct Node* ptr = head;            //สร้าง ptr ขึ้นมาให้เท่ากับ head
    while (ptr != NULL) {               //วนลูปข้อมูลใน temp จนกว่าตำแหน่งถัดไปจะเป็น NULL
        cout << ptr->data << " ";       //แสดงข้อมูลของ ptr ในรอบปัจุบัน
        ptr = ptr->next;                //กำหนดค่าให้ ptr เท่ากับตำแหน่งถัดไปเรื่อยๆจนถึงตำแหน่งสุดท้าย
    }
}

void traverseList(int select) {
    int num, res;
    string str;
    cout << "Input Number : ";
    cin >> num;
    cout << "Input Step : ";
    cin >> str;
    
    if (num != str.size()) {                        //หากจำนวนก้าวกับก้าวที่ป้อนเข้าไม่เท่ากันจะแสดงข้อความดังนี้ 
        cout << "number and steps are not the same. \n";
        select = 8;                                 //กำหนดให้โปรแกรมวนกลับมาที่ฟังก์ชั่นเดิม และให้กรอกค่าใหม่  
    }
    else {
        struct Node* ptr = head;                    //สร้าง ptr ขึ้นมาให้เท่ากับ head
        for (int i = 0; i < str.size(); i++) {      //สร้างลูปให้เท่ากับขนาดของ str (ก้าวที่รับเข้ามา) แต่สามารถใช้ num แทนก็ได้เช่นกันเพราะทำการป้องกัน error ไว้ด้านบนแล้ว
            if (str[i] == 'L' && i != 0) {          //หากก้าวที่รับเข้ามาในตำแหน่งปัจจุบันเท่ากับ L และ รอบปัจจุบันไม่เท่ากับ 0 
                ptr = ptr->prev;                    //กำหนดให้ ptr เท่ากับตำแหน่งก่อนหน้า
                res = ptr->data;                    //และกำหนดให้ตัวแปร res เท่ากับข้อมูลในตำแหน่งของ ptr
            }
            else if (str[i] == 'L' && i == 0) {     //ในกรณีที่ตำแหน่งปัจจุบันเป็น 0 และก้าวเป็น L จะให้อยู่ในตำแหน่งเริ่มต้น
            }
            else {                                  //กรณีนี้จะเกิดได้กับ R 
                ptr = ptr->next;                    //กำหนดให้ ptr เท่ากับตำแหน่งถัดไป
                res = ptr->data;                    //และกำหนดให้ตัวแปร res เท่ากับข้อมูลในตำแหน่งของ ptr
            }
        }
        cout << res;
    }
}

int main()
{
    int select;
    cout << "1. Operation isEmpty \n";
    cout << "2. Operation getSize \n";
    cout << "3. Operation insertFirst \n";
    cout << "4. Operation insertLast \n";
    cout << "5. Operation removeFirst \n";
    cout << "6. Operation removeLast \n";
    cout << "7. Operation displayList \n";
    cout << "8. Operation traverseList \n";
    cout << "9. Exit Program \n";
    
    while (true) {
        cout << "Select item : ";
        std::cin >> select;

        //หลังจากรับค่าตัวเลือกจะนำค่าดังกล่าวมาเข้าเงื่อนไขใน switch ซึ่งในแต่ละเงื่อนไขจะมีทั้งเรียกใช้ฟังก์ชั่นปกติและส่งค่าไปพร้อมกัน
        switch (select) {   
        case 1: isEmpty();
            break;
        case 2: getSize();
            break;
        case 3: 
            int firstdata;
            cout << "Input new first node : ";
            cin >> firstdata;
            cout << "\n";
            insertFirst(firstdata);
            break;
        case 4: 
            int lastdata;
            cout << "Input new last node : ";
            cin >> lastdata;
            cout << "\n";
            insertLast(lastdata);
            break;
        case 5: removeFirst();
            cout << "\n";
            break;
        case 6: removeLast();
            cout << "\n";
            break;
        case 7: displayList();
            cout << "\n\n";
            break;
        case 8: traverseList(select);
            cout << "\n\n";
            break;
        case 9:
            cout << "Exit";
            return false;   //ออกจากลูป
            break;
        default:
            return false;   //ออกจากลูป
            break;
        }
    }

    return 0;
}
