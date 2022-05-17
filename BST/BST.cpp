/******************************************************************************
    Author      : Dulyakit Phommachat
    Code        : 61172110078-6
    Section     : CPE.61241
    Lab No.     : 4
    Course      : 04-061-212 Data Structures and Algorithms Laboratory
    Due Date    : 06/05/2022
    Instruction : A.Supattra Kerdmec
    Description : การจําลองการทํางานของโครงสร้างข้อมูลBinary Search Tree
    language    : C++
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

//ฟังก์ชั่นสำหรับสร้างโหนดใหม่เพื่อประหยัดพื้นในการเขียนโค้ด
//โดยประยุกต์มาจาก Lab linked_list ที่ผ่านมาซึ่งจะทำให้การสร้างโหนดใหม่ประหยัดเวลาในการเขียนโค้ดอย่างมาก
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

//ฟังก์ชั่นตรวจสอบว่าต้นไม้ที่ส่งมาเป็นค่าว่างหรือไม่ โดยจะนำโหนดที่รับมา สร้างเป็นโหนดใหม่และนำมาตรวจสอบค่าว่าง(ใช้ร่วมกับบางฟังก์ชัั่น)
bool empty(struct node *root)
{
    if (root != NULL)
    {
        return false;
    }
    return true;
}

//ฟังก์ชั่นเพิ่มข้อมูลในต้นไม้ จากค่าที่รับมา
struct node *insert(struct node *node, int key)
{
    //ถ้าต้นไม้ เป็นค่าว่าง จะคืนค่าโหนดใหม่
    if (node == NULL)
        return newNode(key);

    //ถ้าค่าที่รับมาน้อยกว่าข้อมูลโหนดตำแหน่งปัจจุบันจะตรวจสอบค่าทางซ้ายไปเรื่อยๆจนกว่าค่าที่รับมาจะมีค่ามากกว่าตัวถัดไปจึงเพิ่มข้อมูลลงไป ณ ตำแหน่งนั้น
    //แต่ถ้าค่าที่รับมามากกว่าจะตรวจสอบค่าทางขวาเรื่อยๆจนกว่าค่าที่รับมาจะมีค่ามากกว่าตัวถัดไปจึงเพิ่มข้อมูลลงไป ณ ตำแหน่งนั้น
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    //ส่งคืนโหนด
    return node;
}

//ฟังก์ชั่นค้นหาข้อมูลในต้นไม้
bool search(struct node *root, int temp)
{
    bool res = false;
    if (root != NULL)
    {
        //สร้างโหนดเพิ่มเพื่อทำการลูปภายในโหนด
        struct node *current = (struct node *)malloc(sizeof(struct node));

        //วนลูปโหนดจนกว่่าตำแหน่งถัดไปจะเป็นค่าว่าง
        for (current = root; current != NULL; current = current->right)
        {
            //ถ้าข้อมูลในตำแหน่งปัจจถบันตรงกับค่าที่รับมาจะกำหนดให้ตัวแปร res เป็น true
            //ถ้าไม่มีข้อมูลที่ตรงกันจะส่งค่า false กลับ
            if (current->key == temp)
            {
                res = true;
            }
        }
    }
    //ส่งกลับค่าในตัวแปร res
    return res;
}

//ฟังก์ชั่นหาขนาดของต้นไม้
int getSize(struct node *root)
{
    int length = 1;

    //สร้างโหนดเพิ่มเพื่อทำการลูปภายในโหนด
    struct node *current = (struct node *)malloc(sizeof(struct node));

    //วนลูปต้นไม้ทุกตำแหน่งและเพิ่มค่าให้ตัวแปร length ตามจำนวนข้อมูลที่วนลูป จะได้ขนาดของต้นไม้
    for (current = root; current != NULL; current = current->right)
    {
        length++;
    }

    return length;
}

//ฟังก์ชั่นหาค่าที่มากที่สุดในต้นไม้
int getMax(node *root)
{
    //ถ้าโหนดเป็นค่าว่าง จะส่งกลับค่าที่มากที่สุดของจำนวนเต็มลบ(ค่าคงที่ของ c++) และจบการทำงานของฟังก์ชั่น(เขียนเพื่อป้องกันการเกิด error)
    if (root == NULL)
        return INT_MIN;

    //ส่งกลับค่าสูงสุด 3 ค่า เพื่อนำไปหาค่าที่มากที่สุด โดยมี
    // 1. ข้อมูลของรูทตำแหน่งนั้นๆ
    // 2. ค่ามากสุดของต้นไม้ย่อยทางซ้าย
    // 3. ค่ามากสุดของต้นไม้ย่อยทางขวา
    int res = root->key;
    int lres = getMax(root->left);
    int rres = getMax(root->right);

    //หาค่าที่มากที่สุดของทั้งฝั่งซ้ายและฝั่งขวา
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;

    //ส่งกลับค่าที่มากที่สุด
    return res;
}

//ฟังก์ชั่นหาค่าที่น้อยที่สุดในต้นไม้
int getMin(node *root)
{
    //ถ้าโหนดเป็นค่าว่าง จะส่งกลับค่าที่มากที่สุดของจำนวนเต็มบวกและจบการทำงานของฟังก์ชั่น(เขียนเพื่อป้องกันการเกิด error)
    if (root == NULL)
        return INT_MAX;

    //ส่งกลับค่าสูงสุด 3 ค่า เพื่อนำไปหาค่าที่น้อยที่สุด โดยมี
    // 1. ข้อมูลของรูทตำแหน่งนั้นๆ
    // 2. ค่าน้อยสุดของต้นไม้ย่อยทางซ้าย
    // 3. ค่าน้อยสุดของต้นไม้ย่อยทางขวา
    int res = root->key;
    int left = getMin(root->left);
    int right = getMin(root->right);

    //หาค่าที่น้อยที่สุดของทั้งฝั่งซ้ายและฝั่งขวา
    if (left < res)
        res = left;
    if (right < res)
        res = right;

    //ส่งกลับค่าที่น้อยที่สุด
    return res;
}

//ฟังก์ชั่นหาตำแหน่งเล็กสุดในต้นไม้ (ใช้ร่วมกับฟังก์ชั่น delete)
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    //วนลูปเพื่อหาตำแหน่งซ้ายสุดของต้นไม้
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

//ฟังก์ชั่นลบข้อมูลออกจากต้นไม้ด้วยค่าที่รับมา
struct node *deleteNode(struct node *root, int key)
{
    //ถ้าโหนดเป็นค่าว่างจะส่งคืนโหนดและจบการทำงานของฟังก์ชั่น
    if (root == NULL)
        return root;

    //ถ้าค่าที่จะลบเล็กกว่ารากของคีย์
    //จะอยู่ในต้นไม้ย่อยทางด้านซ้าย
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    //ถ้าค่าที่จะลบใหญ่กว่ารากของคีย์
    //จะอยู่ในต้นไม้ย่อยทางด้านขวา
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    //ถ้าค่าที่จะลบเหมือนกันกับคีย์ของราก
    else
    {
        //โหนดที่ไม่มีลูก
        if (root->left == NULL and root->right == NULL)
            return NULL;

        //โหนดที่มีลูกคนเดียวหรือไม่มีลูก
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        //โหนดที่มีลูกสองคนและเล็กที่สุดในต้นไม้ย่อยด้านขวา
        struct node *temp = minValueNode(root->right);

        //คัดลอกข้อมูลของผู้สืบทอดแบบ inorder ไปยังโหนด
        root->key = temp->key;

        //ลบผู้สืบทอด inorder
        root->right = deleteNode(root->right, temp->key);
    }
    //ส่งคืนโหนด
    return root;
}

// preorder traversal of BST
void preorder(struct node *root)
{
    //ป้องกัน error
    if (root == NULL)
        return;

    //แสดงข้อมูลโหนดปัจจุบัน
    cout << root->key << " ";
    //จากนั้นท่องจากต้นไม้ย่อยทางซ้าย
    preorder(root->left);
    //และท่องไปต้นไม้ย่อยทางขวา
    preorder(root->right);

    //ท่องไปเรื่อยๆจนสิ้นสุดข้อมูลของต้นไม้
}

// inorder traversal of BST
void inorder(struct node *root)
{
    //ป้องกัน error
    if (root == NULL)
        return;

    //ท่องจากต้นไม้ย่อยทางซ้าย
    inorder(root->left);
    //จากนั้นแสดงข้อมูลโหนดปัจจุบัน
    cout << root->key << " ";
    //และท่องไปต้นไม้ย่อยทางขวา
    inorder(root->right);
}

// postorder traversal of BST
void postorder(struct node *root)
{
    //ป้องกัน error
    if (root == NULL)
        return;

    //ท่องจากต้นไม้ย่อยทางซ้าย
    postorder(root->left);
    //จากนั้นไปต้นไม้ย่อยทางขวา
    postorder(root->right);
    //และแสดงข้อมูลโหนดปัจจุบัน
    cout << root->key << " ";
}

// Main code
int main()
{
    struct node *root = NULL;
    int param;
    int select;
    string text;
    cout << "1. operation insert  \n";
    cout << "2. operation remove \n";
    cout << "3. operation search \n";
    cout << "4. operation getSize \n";
    cout << "5. operation getMaxMin \n";
    cout << "6. operation traverse \n";
    cout << "7. exit \n";

    while (true)
    {
        cout << "\n";
        cout << "Select item : ";
        std::cin >> select;

        //หลังจากรับค่าตัวเลือกจะนำค่าดังกล่าวมาเข้าเงื่อนไขใน switch
        switch (select)
        {
        case 1:
            cout << "please input parameter : ";
            cin >> param;
            root = insert(root, param);
            break;
        case 2:
            cout << "please input parameter : ";
            cin >> param;
            deleteNode(root, param);
            break;
        case 3:
            cout << "please input parameter : ";
            cin >> param;
            text = search(root, param) ? "yes \n" : "no \n";
            cout << text;
            break;
        case 4:
            cout << getSize(root) << "\n";
            break;
        case 5:
            int min, max;
            min = getMin(root);
            max = getMax(root);
            if (empty(root))
            {
                cout << "no \n";
            }
            else
            {
                cout << "Min = " << min << " and Max = " << max << "\n";
            }
            break;
        case 6:
            if (!empty(root))
            {
                preorder(root);
                cout << "\n";
                inorder(root);
                cout << "\n";
                postorder(root);
                cout << "\n";
            }
            else
            {
                cout << "no \n";
            }
            break;
        case 7:
            cout << "Exit";
            return false; //ออกจากลูป
            break;
        default:
            return false; //ออกจากลูป
            break;
        }
    }

    return 0;
}
