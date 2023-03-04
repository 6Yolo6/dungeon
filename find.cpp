
#include"����.h"
#define FALSE   0   
#define TRUE    1   
#define NULL    0   
typedef int BOOL;

typedef struct Node
{//�ڵ�ṹ��   
    int f, g, h;
    int row;    //�ýڵ�������   
    int col;    //�ýڵ�������   
    int direction;//parent�ڵ�Ҫ�ƶ��ķ�����ܵ��ﱾ�ڵ�   
    struct Node* parent;
}Node, * Lnode;

typedef struct Stack
{//OPEN CLOSED ��ṹ��   
    Node* npoint;
    struct Stack* next;
}Stack, * Lstack;
int rows = 31;          //��ͼ����   
int cols = 31;          //��ͼ����   
int G_OFFSET = 1;       //ÿ��ͼ��Gֵ������ֵ   
int destinationRow;     //Ŀ��������   
int destinationCol;     //Ŀ��������   
int canMoveIndex = 0;   //����ͨ�еĵ�ͼͼ������   
int tileSize = 1;       //ͼ���С   

Lstack Open = NULL;
Lstack Closed = NULL;
Node* getNodeFromOpen()
{//ѡȡOPEN����fֵ��С�Ľڵ㣬���ظýڵ��ַ   
    Lstack temp = Open->next, min = Open->next, minp = Open;
    Node* minx;
    if (temp == NULL)
        return NULL;

    while (temp->next != NULL)
    {
        if ((temp->next->npoint->f) < (min->npoint->f))
        {
            min = temp->next;
            minp = temp;
        }
        temp = temp->next;
    }
    minx = min->npoint;
    temp = minp->next;
    minp->next = minp->next->next;
    free(temp);
    return minx;
}

BOOL Equal(Node* suc, Node* goal)
{//�жϽڵ��Ƿ���ȣ���ȣ������   
    if ((suc->row == goal->row) && (suc->col == goal->col))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Node* BelongInOpen(Node* suc)
{//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ   
    Lstack temp = Open->next;
    if (temp == NULL)
        return NULL;
    while (temp != NULL)
    {
        if (Equal(suc, temp->npoint))
        {
            return temp->npoint;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

Node* BelongInClosed(Node* suc)
{//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ   
    Lstack temp = Closed->next;
    if (temp == NULL)
        return NULL;
    while (temp != NULL)
    {
        if (Equal(suc, temp->npoint))
        {
            return temp->npoint;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

void PutintoOpen(Node* suc)
{//�ѽڵ����OPEN ��CLOSED ����   
    Stack* temp;
    temp = (Stack*)malloc(sizeof(Stack));
    temp->npoint = suc;

    temp->next = Open->next;
    Open->next = temp;
}
void PutintoClosed(Node* suc)
{//�ѽڵ����OPEN ��CLOSED ����   
    Stack* temp;
    temp = (Stack*)malloc(sizeof(Stack));
    temp->npoint = suc;
    temp->next = Closed->next;
    Closed->next = temp;
}

//�õ���ͼ���Hֵ   
int getH(int row, int col)
{
    return (abs(destinationRow - row) + abs(destinationCol - col));
}

//�õ���λ�����ڵ�ͼ��   
int getRowPosition(int y)
{
    return (y / tileSize);
}

//�õ���λ�����ڵ�ͼ��   
int getColPosition(int x)
{
    return (x / tileSize);
}
//����ͼ���Ƿ��ͨ��   
BOOL isCanMove(int col, int row)
{
    if (col < 0 || col >= cols)
        return FALSE;
    if (row < 0 || row >= rows)
        return FALSE;
    return Map[col][row] == canMoveIndex;
}

Node* checkOpen(int row, int col)
{
    Lstack temp = Open->next;
    if (temp == NULL)
        return NULL;
    while (temp != NULL)
    {
        if ((temp->npoint->row == row) && (temp->npoint->col == col))
        {
            return temp->npoint;
        }
        else
        {
            temp = temp->next;
        }
    }
    return NULL;
}

BOOL isInClose(int row, int col)
{
    Lstack temp = Closed->next;
    if (temp == NULL)
        return FALSE;
    while (temp != NULL)
    {
        if ((temp->npoint->row == row) && (temp->npoint->col == col))
        {
            return TRUE;
        }
        else
        {
            temp = temp->next;
        }
    }
    return FALSE;
}
int directionIndex = 0;
int direction[256];
void creatSeccessionNode(Node* bestNode, int row, int col)
{
    int g = bestNode->g + G_OFFSET;
    if (!isInClose(row, col))
    {
        Node* oldNode = NULL;
        if ((oldNode = checkOpen(row, col)) != NULL)
        {
            if (oldNode->g < g)
            {
                oldNode->parent = bestNode;
                oldNode->g = g;
                oldNode->f = g + oldNode->h;
            }
        }
        else
        {
            Node* node = (Node*)malloc(sizeof(Node));
            node->parent = bestNode;
            node->g = g;
            node->h = getH(row, col);
            node->f = node->g + node->h;
            node->row = row;
            node->col = col;
            directionIndex++;
            node->direction = directionIndex;
            //              openNode.addElement(node);   
            PutintoOpen(node);
        }
    }
}

/**
 * ���ݴ���Ľڵ������ӽڵ�
 * @param bestNode
 * @param destinationRow
 * @param destinationCol
 */
void seachSeccessionNode(Node* bestNode)
{
    int row, col;
    //      Node *bestNodeInOpen = NULL;   
            //�ϲ��ڵ�   
    if (isCanMove(row = bestNode->row - 1, col = bestNode->col))
    {
        creatSeccessionNode(bestNode, row, col);
    }
    //�²��ڵ�   
    if (isCanMove(row = bestNode->row + 1, col = bestNode->col))
    {
        creatSeccessionNode(bestNode, row, col);
    }
    //�󲿽ڵ�   
    if (isCanMove(row = bestNode->row, col = bestNode->col - 1))
    {
        creatSeccessionNode(bestNode, row, col);
    }
    //�Ҳ��ڵ�   
    if (isCanMove(row = bestNode->row, col = bestNode->col + 1))
    {
        creatSeccessionNode(bestNode, row, col);
    }
    PutintoClosed(bestNode);
}
//�����������   
void printfOpenData()
{//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ   
    Lstack temp = Open->next;
    Node* p_node;
    if (temp == NULL)
        return;
    while (temp != NULL)
    {
        Lstack head = temp;
        temp = temp->next;
        p_node = head->npoint;
        printf("Open�����ݣ�[%d,%d]\n", p_node->col, p_node->row);
        free(p_node);
        free(head);
        Open->next = temp;
    }
    printf("\n Open������ ����ȫ����� \n");
    return;
}
void printfClosedData()
{//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ   
    Lstack temp = Closed->next;
    Node* p_node;
    if (temp == NULL)
        return;
    while (temp != NULL)
    {
        Lstack head = temp;
        temp = temp->next;
        p_node = head->npoint;
        printf("Closed�����ݣ�[%d,%d]\n", p_node->col, p_node->row);
        free(p_node);
        free(head);
        Closed->next = temp;
    }
    printf("\n Closed������ ����ȫ����� \n");
    /*
    temp = Closed -> next;
    while(temp != NULL)
    {
        printf("Closed�����ݣ��ڵ�");
        temp = temp->next;
    }*/
    return;
}
void getPath(int startX, int StartY, int destinationX, int destinationY)
{
    Node* startNode = (Node*)malloc(sizeof(Node));
    Node* bestNode = NULL;
    int index = 0;
    destinationRow = getRowPosition(destinationY);
    destinationCol = getColPosition(destinationX);

    startNode->parent = NULL;
    startNode->row = getRowPosition(StartY);
    startNode->col = getColPosition(startX);
    startNode->g = 0;
    startNode->h = getH(startNode->row, startNode->col);
    startNode->f = startNode->g + startNode->h;
    startNode->direction = 0;
    PutintoOpen(startNode);// openNode.add(startNode);   

    while (TRUE)
    {
        bestNode = getNodeFromOpen(); //��OPEN����ȡ��fֵ��С�Ľڵ�   
        if (bestNode == NULL)//δ�ҵ�·��   
        {
            printf("δ�ҵ�·��\n");
            return;
        }
        else if (bestNode->row == destinationRow
            && bestNode->col == destinationCol)
        {
            Node* _Node = bestNode;
            int nodeSum = 0;
            int nodeIndex = 0;
            printf("�������д���=%d\n", index);
            while (_Node->parent != NULL)
            {
                printf("x:%d  y:%d  direction = %d \n", _Node->col, _Node->row, _Node->direction);
                _Node = _Node->parent;
                nodeSum += 1;
            }
            printf("�ڵ�����=%d\n", nodeSum);
            _Node = bestNode;
            nodeIndex = nodeSum - 1;
            while (_Node->parent != NULL && nodeIndex >= 0)
            {
                Node* _NodeParent = _Node->parent;
                printf("x:%d  y:%d  direction = %d \n", _Node->col, _Node->row, _Node->direction);
                Enermy.x = _Node->col, Enermy.y = _Node->row;
                if (_NodeParent->col - _Node->col == 0 && _NodeParent->row - _Node->row == +1)
                {//�Ӹ��ڵ㵽���ڵ�Ĳ�����  ��   
                    direction[nodeIndex] = 1;
                }
                else if (_NodeParent->col - _Node->col == 0 && _NodeParent->row - _Node->row == -1)
                {//�Ӹ��ڵ㵽���ڵ�Ĳ�����  ��   
                    direction[nodeIndex] = 2;
                }
                else if (_NodeParent->col - _Node->col == +1 && _NodeParent->row - _Node->row == 0)
                {//�Ӹ��ڵ㵽���ڵ�Ĳ�����  ��   
                    direction[nodeIndex] = 3;
                }
                else if (_NodeParent->col - _Node->col == -1 && _NodeParent->row - _Node->row == 0)
                {//�Ӹ��ڵ㵽���ڵ�Ĳ�����  ��   
                    direction[nodeIndex] = 4;
                }
                else
                {
                    direction[nodeIndex] = 0;
                }
                nodeIndex -= 1;
                _Node = _Node->parent;
            }
            for (nodeIndex = 0; nodeIndex < nodeSum; nodeIndex++)
            {
                printf("direction[%d]=%d\n", nodeIndex, direction[nodeIndex]);
            }
            return;
        }
        index++;
        seachSeccessionNode(bestNode);
    }
}
void autoPathfinding()
{
    //��ʼ����������open��closed��   
    Open = (Stack*)malloc(sizeof(Stack));
    Open->next = NULL;
    Closed = (Stack*)malloc(sizeof(Stack));
    Closed->next = NULL;
    //-----------------------------------   
    getPath(Enermy.x,Enermy.y,Player.x,Player.y);
    printf("�����϶�����ʼ״̬�޷�����Ŀ��״̬!\n");

    printfOpenData();
    printfClosedData();
    free(Open);
    free(Closed);
    //--------------------------------------   
}