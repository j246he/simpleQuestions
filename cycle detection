#include <stdio.h>  

typedef struct Node  
{  
    int val;  
    Node *next;  
}Node,*pNode;  



//判断是否有环  
bool isLoop(pNode pHead)  
{  
    pNode fast = pHead;  
    pNode slow = pHead;  
    //如果无环，则fast先走到终点  
    //当链表长度为奇数时，fast->Next为空  
    //当链表长度为偶数时，fast为空  
    while( fast != NULL && fast->next != NULL)  
    {  

        fast = fast->next->next;  
        slow = slow->next;  
        //如果有环，则fast会超过slow一圈  
        if(fast == slow)  
        {  
            break;  
        }  
    }  

    if(fast == NULL || fast->next == NULL  )  
        return false;  
    else  
        return true;  
}  

//计算环的长度  
int loopLength(pNode pHead)  
{  
    if(isLoop(pHead) == false)  
        return 0;  
    pNode fast = pHead;  
    pNode slow = pHead;  
    int length = 0;  
    bool begin = false;  
    bool agian = false;  
    while( fast != NULL && fast->next != NULL)  
    {  
        fast = fast->next->next;  
        slow = slow->next;  
        //超两圈后停止计数，挑出循环  
        if(fast == slow && agian == true)  
            break;  
        //超一圈后开始计数  
        if(fast == slow && agian == false)  
        {             
            begin = true;  
            agian = true;  
        }  

        //计数  
        if(begin == true)  
            ++length;  

    }  
    return length;  
}  


//求出环的入口点  
Node* findLoopEntrance(pNode pHead)  
{  
    pNode fast = pHead;  
    pNode slow = pHead;  
    while( fast != NULL && fast->next != NULL)  
    {  

        fast = fast->next->next;  
        slow = slow->next;  
        //如果有环，则fast会超过slow一圈  
        if(fast == slow)  
        {  
            break;  
        }  
    }  
    if(fast == NULL || fast->next == NULL)  
        return NULL;  
    slow = pHead;  
    while(slow != fast)  
    {  
        slow = slow->next;  
        fast = fast->next;  
    }  

    return slow;  
}  
