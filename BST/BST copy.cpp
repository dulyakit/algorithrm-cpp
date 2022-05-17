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

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

bool empty(struct node *root)
{
    if (root != NULL)
    {
        return false;
    }
    return true;
}

bool search(struct node *root, int temp)
{
    bool res = false;
    if (root != NULL)
    {
        struct node *current = (struct node *)malloc(sizeof(struct node));

        //วนลูป linked_list ทุกตำแหน่งและเพิ่มค่าให้ตัวแปร length ตามจำนวนข้อมูลที่วนลูป จะได้ขนาดของ linked_list
        for (current = root; current != NULL; current = current->right)
        {
            if (current->key == temp)
            {
                res = true;
            }
        }
    }
    return res;
}

int getSize(struct node *root)
{
    int length = 0;
    struct node *current = (struct node *)malloc(sizeof(struct node));

    //วนลูป linked_list ทุกตำแหน่งและเพิ่มค่าให้ตัวแปร length ตามจำนวนข้อมูลที่วนลูป จะได้ขนาดของ linked_list
    for (current = root; current != NULL; current = current->right)
    {
        length++;
    }

    return length;
}

int getMax(node *root)
{
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->key;
    int lres = getMax(root->left);
    int rres = getMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}

int getMin(node *root)
{
    int res = root->key;
    int left = getMin(root->left);
    int right = getMin(root->right);
    if (left < res)
    {
        res = left;
    }
    if (right < res)
    {
        res = right;
    }
    return res;
}
/* A utility function to
insert a new node with given key in
 * BST */
struct node *insert(struct node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct node *deleteNode(struct node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node has no child
        if (root->left == NULL and root->right == NULL)
            return NULL;

        // node with only one child or no child
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

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// A utility function to do
// inorder traversal of BST
void preorder(struct node *root)
{
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void postorder(struct node *root)
{
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

// Main code
int main()
{
    struct node *root = NULL;
    int param;
    int select;
    string text;

    cout << "\n";
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
        cout << "select item : ";
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
            if (!empty(root))
            {
                cout << "Min = " << getMin(root) << " and Max = " << getMax(root) << "\n";
            }
            else
            {
                cout << "no \n";
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
