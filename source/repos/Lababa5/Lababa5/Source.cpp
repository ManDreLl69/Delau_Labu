#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

int dlina = 0;
struct sob {
	int inf;
	struct sob* next;
};
typedef struct sob pes;
pes * tail = NULL, * first = NULL;

void push(int a) {
	pes* pr = (pes*)malloc(sizeof(pes));
	pr->inf = a;
	pr->next = NULL;
	if (!first) first = pr;
	else tail->next=pr;
	tail = pr;
	dlina++;
}
void pop(void) {
	if (dlina == 1) {
		free(tail);
		first = NULL;
		tail = NULL;
		return;
	}
	pes* pr = first;
	first = pr->next;
	free(pr);

}

void show(void) {
	pes* pr = first;
	printf("Stack content\n<<<<<!>>>>>\n");
	if (!pr){printf("Empty stack\n");
	return;}
	for (int i = 0; i < dlina ; i++) {
			printf("%d ", pr->inf);
			pr = pr->next;
		}
		printf("\n");
}

void vNachalo(int a) {
	pes* pr = (pes*)malloc(sizeof(pes));
	pr->inf = a;
	pr->next = first;
	first = pr;
	dlina++;
}

void vKonets(int a) {
	pes* pr = (pes*)malloc(sizeof(pes));
	pr->inf = a;
	tail->next = pr;
	if (!first) first = pr;
	else tail->next = pr;
	tail = pr;
	dlina++;
}

void kudaUgodno(int a,int b) {
	if (b > dlina) {
		puts("Error\n");
		return;
	}
	pes* pr = (pes*)malloc(sizeof(pes));
	pes* pr2 = first;
	pr->inf = a;
	for (int i = 0; i < b; i++) pr2 = pr2->next;
	pr->next = pr2->next;
	pr2->next = pr;
	dlina++;
}

void otrejuNachalo(void) {
	if (dlina == 1) {
		free(first);
		first = NULL;
		tail = NULL;
	}
	pes* pr = first;
	first = pr->next;
	free(pr);
}

void otrejuKonets(void) {
	if (dlina == 1) {
		free(tail);
		first = NULL;
		tail = NULL;
	}
	pes* pr = tail;
	pes* pr2 = first;
	for (int i = 0; i < dlina - 2; i++) pr2 = pr2->next;
	tail = pr2;
	free(pr);
}

void otrejuChast(int b) {
	if (b > dlina) {
		puts("Error\n");
		return;
	}
	pes* pr = NULL;
	pes* pr2 = first;
	for (int i = 0; i < b-1; i++) pr2 = pr2->next;
	pr = pr2->next;
	pr2->next = pr2->next->next;
	free(pr);
}
void Luboy(int b) {
	if (b > dlina) {
		puts("Error\n");
		return;
	}
	pes* pr = first;
	for (int i = 0; i < b; i++) pr = pr->next;
	printf("Selected element: %d \n", pr->inf);
}


	
void varik(void) {
	int min = INT_MAX;
	pes* pr = first;
	for (int i = 0; i < dlina;i++) {
		if ((pr->inf) % 2 == 1 && pr->inf < min)min = pr->inf;
		pr=pr->next;
    }
	if (min == INT_MAX) {
		puts("List has no odds");
		return;
	}
	pr = first;
	for (int i = 0; i < dlina; i++) {
		if (pr->inf % 2 == 1)pr->inf += min;
		pr = pr->next;
	}
}

void save(void) {
	FILE* gavric;
	int osh = fopen_s(&gavric, "C:/Users/anyak/source/repos/Lababa5/saves.txt", "wt");
	if (osh != 0) {
		puts("\nCho-to visivaet scriptovie oshibki\n");
		return;
	}
	pes* pr = first;
	fprintf(gavric, "%d ", dlina);
	for (int i = 0; i < dlina; i++) {
		fprintf(gavric, "%d ", pr->inf);
		pr = pr->next;
	}
	fclose(gavric);
}

void load(void) {
	FILE* gavric;
	int osh = fopen_s(&gavric, "C:/Users/anyak/source/repos/Lababa5/saves.txt", "rt");
	if (osh != 0) {
		puts("\nCho-to visivaet scriptovie oshibki\n");
		return;
	}
	while (dlina) {
		pop();
		dlina--;
	}
	int s;
	fscanf_s(gavric, "%d", &dlina);
	for (int i = 0; i < dlina; i++) {
		fscanf_s(gavric, "%d", &s);
		push(s);
		dlina--;
	}
	fclose(gavric);
}
 
int main() {
	int a, b,z;
	show();
	do {
		printf("\nEnter element(Enter 0 to exit): ");
		scanf_s("%d", &a);
		if (a == 0) {
			printf("\n");
			break; }
		printf("%d", a);
		push(a);
	} while (true);
	puts("0) Exit\n");
	puts("1) Add to begining\n");
	puts("2) Add to end\n");
	puts("3) Add to other place\n");
	puts("4) Remove from begining\n");
	puts("5) Remove from end\n");
	puts("6) Remove from other place\n");
	puts("7) Output list\n");
	puts("8) Selected element\n");
	puts("9) Varik 11\n");
	puts("10) Save\n");
	puts("11) Load\n");
	do{scanf_s("%d", &z);
	switch (z) {
	case 0:exit(0);
	case 1: printf("Enter value\n");
		scanf_s("%d", &a);
		vNachalo(a);
		show();
		break;
	case 2: printf("Enter value\n");
		scanf_s("%d", &a);
		vKonets(a);
		show();
		break;
	case 3:printf("Enter value\n");
		scanf_s("%d", &a);
		printf("Enter place\n");
		scanf_s("%d", &b);
		kudaUgodno(a, b);
		show();
		break;
	case 4:otrejuNachalo();
		dlina--;
		show();
		break;
	case 5:otrejuKonets();
		dlina--;
		show();
		break;
	case 6: printf("Select element\n");
		scanf_s("%d", &b);
		otrejuChast(b);
		dlina--;
		show();
		break;
	case 7:show();
		break;
	case 8: printf("Select element\n");
		scanf_s("%d", &b);
		Luboy(b);
		break;
	case 9:varik();
		show();
		break;
	case 10:save();
		show();
		break;
	case 11:load();
		show();
		break;
	default: printf("\nWrong Action\n");
	}
	}
	while (true);
}