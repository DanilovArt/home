#include "iset.h"
#include <stddef.h>

template <class T> struct riba{
    T data;
riba* next;
};

template <class T> class MySet: public ISet<T> {
public:

    //сложность O(1)
   MySet(){
      head=NULL;
       razmer=0;
}

   //сложность O(N)
   ~MySet(){
       riba<T>* trans  = head;
       while(trans!=NULL)
       {
           head=trans->next;
           delete trans;
           trans=head;
       }
   }


   //сложность O(N)
   void add(const T &elem){
       riba<T>* trans=head;
     riba<T>* temp=new riba<T>;
     temp->data=elem;
     temp->next=NULL;
     if(head==NULL)
     {
        temp->next=head;
                head=temp;
                razmer+=1;
            return ;
     }
       if(trans->data==elem)
           return;
       if(trans->data>elem)
       {    temp->next=head;
                  head=temp;
                  razmer+=1;
           return ;}
       while((trans->next!=NULL)&&(trans->next->data<=elem))
         trans=trans->next;
       if(trans->data==elem)
           return;
                temp->next=trans->next;
                trans->next=  temp;
                razmer+=1;
                return;
   }


    //сложность O(N)
 bool contains(const T &elem) const{
 riba<T>* trans=head;
 while((trans!=NULL)&&(elem>trans->data))
 {
     trans=trans->next;
 }
 if(elem==trans->data)
     return true;
   return false;
   }

    //сложность O(N)
   void remove(const T &elem){
       riba<T>* trans=head;
	   riba<T>* remover = NULL;
	   if (head->data == elem)
	   {
		   head = head->next;
		   razmer -= 1;
		   delete trans;
		   return;
	   }
	   if ((razmer > 1) && (head->next->data == elem))
	   {
		   trans = head->next;
		   head->next = head->next->next;
		   delete trans;
		   razmer -= 1;
		   return;
	   }
       while ((trans->next != NULL) && (trans->next->data < elem))
	   {
		   trans = trans->next;
	   }
	   if (trans->next->data == elem)
	   {
		   remover = trans->next;
		   trans->next = trans->next->next;
		   delete remover;
		   razmer -= 1;
	   }
}
   //сложность O(1)
   int size() const{
       return razmer;
   }
private:
   riba<T>* head;
   unsigned int razmer;
};
