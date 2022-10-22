#include <stdio.h>
#define Maxlength 100
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlength];
	Position Last;	
}List;


void makenullList(List *pL){
	pL->Last = 0;
}

int member(ElementType x, List L){
	Position p = 1;
	while(p != L.Last+1){
	    if(x==L.Elements[p-1])
			return 1;
		p++;
	}
	return 0;
}

void insertList(ElementType x, Position p, List *pL){
	if(pL->Last == Maxlength)
		printf("LOI");
	else if(p<1 || p>(pL->Last+1))
		printf("LOI");
	else {
		Position Q;
		for(Q=pL->Last;Q>=p;Q--)
			pL->Elements[Q] = pL->Elements[Q-1];
		pL->Elements[p-1] = x;
		pL->Last++;
		 
	}
}

Position locate(ElementType x, List L){
	Position p = 1;
	while(p!=L.Last+1){
		if(L.Elements[p-1]==x)
			return p;
		p++;
	}
	return L.Last+1;
}

void difference(List L1, List L2, List *pL){
	Position p = 1;
	makenullList(pL);
	while (p != L1.Last+1){
		if(member(L1.Elements[p-1],L2)==0)
			insertSet(L1.Elements[p-1],pL);
		p++;
	}
}

void normalize(List *pL){
	Position p = 1, q;
	while(p!=pL->Last+1){
	    q= p+1;
		while(q != pL->Last+1){
			if(pL->Elements[p-1]==pL->Elements[q-1])
				deleteList(q,pL);
			else 
			    q++;
		}
		p++;
	}
}

void deleteList(Position p, List *pL){
	if(p<1 || p>pL->Last){
		printf("Vi tri khong hop le\n");
	}else if((pL->Last+1) == 0)
	    printf("Vi tri khong hop le");
	else{
		Position Q;
		for(Q=p;Q<pL->Last;Q++){
			pL->Elements[Q-1] = pL->Elements[Q];
		}
		pL->Last --;
	}
}

void erase(ElementType x,List *pL){
	Position p = 1;
	while (p!=pL->Last+1){
		if(locate(x,*pL)==p){
			deleteList(p,pL);
			break;
    	}
	    else 
	        p++;
	}
}

void removeAll(ElementType x, List *pL){
	Position p = 1;
	while (p!=pL->Last+1){
		if(locate(x,*pL)==p){
			deleteList(p,pL);
			locate(x,*pL);
		}
		else p++;		
	}
}

void printOddNumbers(List L){
	int i;
	for(i=0;i<=L.Last;i++){
		if(L.Elements[i]%2!=0)
			printf("%d ",L.Elements[i]);
	}
}

float getAvg(List L){
	Position P = 1;
	float s = 0;
	int count = 0;
	if(L.Last == 0){
	    return -10000.0000;
	}
	while( P != L.Last+1){
		s += L.Elements[P-1];
		count ++;
		P++;
	}
	return s/count;
}

void sort(List *pL){
		Position p=1,q;
		int x;
		while(p!=pL->Last+1){
			q = p+1;
			while(q!=pL->Last+1){
				if(pL->Elements[p-1] > pL->Elements[-1]){
					x = pL->Elements[p-1];
					pL->Elements[p-1] = pL->Elements[q-1];
					pL->Elements[q-1] = x;
				}
				q++;
			}
			p++;
		}
}

void readList(List *pL){
		makenullList(pL); 
		int n,i;
		ElementType x;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&x);
			insertList(x,(pL->Last+1),pL);
		}

}

void readSet(List *pL){
	makenullList(pL);
	Position p = 0;
	int x,n;
	scanf("%d",&n);
	while (p != n){
		scanf("%d",&x);
		if(!member(x,*pL)){
			insertSet(x,pL);
		} 
	p++;
	}
}

void printList(List L){
	Position p =1;
	while(p != L.Last+1){
		printf("%d ",L.Elements[p-1]);
		p++;
	}
	printf("\n");
}

void copyEvenNumbers(List L1, List *pL){
	makenullList(pL);
	Position p = 1;
	while(p != L1.Last+1){
		if(L1.Elements[p-1]%2==0)
			insertList(L1.Elements[p-1],pL->Last+1,pL);
		p++;
	}
}

void insertSet(ElementType x, List *pL){
		pL->Elements[pL->Last] = x;
		pL->Last++;

}

void unionSet(List L1, List L2,List *pL){
	makenullList(pL);
	Position p = 1;
	
	while(p!=L1.Last+1){
		insertSet(L1.Elements[p-1],pL);
		p++;
	}
	p = 1;
	while(p!=L2.Last+1){
		if(member(L2.Elements[p-1],*pL)==0)
			insertSet(L2.Elements[p-1],pL);
		else 
		    p++;
	}
											                                
}



void intersection(List L1,List L2, List *pL){
	Position p = 1;
	makenullList(pL);
	while(p!=L1.Last+1){
		if(member(L1.Elements[p-1],L2)==1)
			insertSet(L1.Elements[p-1],pL);
		p++;
	}
}

int main(){


 }

