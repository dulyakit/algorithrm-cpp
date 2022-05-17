/******************************************************************************
	Author      : Dulyakit Phommachat
	Code        : 61172110078-6
	Section     : CPE.61241
	Lab No.     : 2
	Course      : 04-061-212 Data Structures and Algorithms Laboratory
	Due Date    : 29/04/2022
	Instruction : A.Supattra Kerdmec
	Description : 1.จงเขียนโปรแกรมเพือทําการตรวจสอบการเข้าคู่กันของวงเล็บ (Check Balance Symbols) ซึงเป็นกระบวนการสําคัญทีใช้ในการตรวจสอบนิพจน์หรือ Expression ว่ามีความถูกต้องหรือไม่โดยมีการนําโครงสร้างข้อมูลชนิดสแตกเข้ามาใช้งานด้วยและมีอัลกอริทึมดังนี
					-ถ้า Character ทีกําลังพิจารณานันเป็นวงเล็บเปิดให้ทําการ Push ลงสู่สแตก
					-ถ้า Character ทีกําลังพิจารณานันเป็นวงเล็บปิด ให้ทําการ Pop ข้อมูลจาก Top of Stack ขึนมาตรวจสอบว่า Match กับ Character ทีกําลังพิจารณาหรือไม่ ทําเช่นนีไปเรือย ๆ จนหมด
					-ถ้าการตรวจสอบทีเกิดขึนนัน เข้าคู่กันทังหมดและสุดท้ายสแตกว่าง (ไม่มีข้อมูลเหลืออยู่เลย) จะได้ว่านิพจน์ทีรับเข้ามานันถูกต้อง แต่ถ้าสแตกยังมีข้อมูลเหลือแสดงว่านิพจน์นันไม่ถูกต้อง
					-แต่ถ้าการตรวจสอบทีเกิดขึนนัน มีคู่ใดคู่หนึงไม่เข้าคู่กันก็ให้หยุดทําและจะได้ว่านิพจน์ทีรับเข้ามานันไม่ถูกต้อง
	language    : C++
*******************************************************************************/

#include <stack>
#include <iostream>
using namespace std;

int CheckBalance(string input)
{
	stack<char> temp;
	for (int i = 0; i < input.length(); i++)
	{
		//ตรวจสอบ stack ว่าเป็นค่าว่างหรือไม่
		if (temp.empty())			
		{
			temp.push(input[i]);	//เพิ่มข้อมูลลง stack 

			if (input[i] == '}' || input[i] == ']' || input[i] == ')') {	//ถ้าข้อมูลตำแหน่งปัจจุบันเท่ากับเงื่อไขนี้จะส่งกลับค่า 2
				return 2;
			}
		}
		//หากข้อมูลใน stack ตัวบนสุด ว่าสัมพันธ์กับ input ตำแหน่งปัจจุบันหรือไม่
 		else if ((temp.top() == '{' && input[i] == '}') || (temp.top() == '[' && input[i] == ']') || (temp.top() == '(' && input[i] == ')')) {
			temp.pop();				//นำข้อมูลตำแหน่งบนสุดออก
		}
		else
		{
			temp.push(input[i]);	//ถ้าไม่เข้าเงื่อนไขจะทำการเพิ่มข้อมูลลง stack 
		}
	}
	//ถ้าไม่มีข้อมูลใน stack จะส่งกลับค่า 1
	if (temp.empty())
	{
		return 1;
	}
	return 0;	//ถ้าไม่เข้าเงื่อไขใดเลยจะส่งกลับ 0
}

int main()
{
	string input;
	cout << "Input Expression String == ";
	cin >> input;

	// เรียกใช้ฟังก์ชั่นตรวจสอบเครื่องหมาย
	if (CheckBalance(input) == 1)						//หากค่าที่ส่งกลับเท่ากับ 1 จะแสดง TRUE
		cout << "Checked Balance Symbols is TRUE";
	else if (CheckBalance(input) == 0)					//หากค่าที่ส่งกลับเท่ากับ 0 จะแสดง FALSE
		cout << "Checked Balance Symbols is FALSE";
	else												//หากค่าที่ส่งกลับอยู่นอกเงื่อนไขจะแสดง ERROR
		cout << "Checked Balance Symbols is ERROR";	
		
	return 0;
}
