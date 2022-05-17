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

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

bool search(struct node *root, int temp)
{
    bool res = false;
    if (root != NULL)
    {
        struct node *current = (struct node *)malloc(sizeof(struct node));
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
    if (root == NULL)
        return 0;

    int length = 1;

    struct node *current = (struct node *)malloc(sizeof(struct node));

    for (current = root; current != NULL; current = current->right)
    {
        length++;
    }

    return length;
}

int getMax(node *root)
{
    if (root == NULL)
        return INT_MIN;

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
    if (root == NULL)
        return INT_MAX;

    int res = root->key;
    int left = getMin(root->left);
    int right = getMin(root->right);

    if (left < res)
        res = left;
    if (right < res)
        res = right;

    return res;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;

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

        struct node *temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

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
            return false;
            break;
        default:
            return false;
            break;
        }
    }

    return 0;
}
