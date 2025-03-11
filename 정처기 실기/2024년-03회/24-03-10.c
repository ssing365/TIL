#include <stdio.h>

/*
✅ * (포인터 연산자)
 : 포인터를 선언할 때 사용 (struct Node *node)
 포인터가 가리키는 주소의 값을 참조할 때 사용 (*p)
*/

struct  Node // struct : 구조체 선언 예약어
{
    int value;
    struct Node* next;
};

/*
✅ -> (화살표 연산자)
 : 구조체 포인터가 가리키는 멤버에 접근할 때 사용
 node -> value는 (*node).value와 동일
*/

void func(struct Node *node){
    while(node != NULL && node -> next != NULL){
        int t = node -> value;
        node -> value = node -> next -> value;
        node -> next -> value = t;
        node = node -> next -> next;
    }
}

/*
✅ & (주소 연산자)
 : 변수의 메모리 주소를 가져올 때 사용 (&n1 → n1의 주소 반환)
*/

int main(){
    struct Node n1 = {1, NULL};
    struct Node n2 = {2, NULL};
    struct Node n3 = {3, NULL};
    n1.next = &n3;
    n3.next = &n2;
    func(&n1);
    
    struct Node* current = &n1;
    while(current != NULL){
        printf("%d", current-> value);
        current = current-> next;
    }
    return 0;
}
