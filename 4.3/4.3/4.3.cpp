// Написать программу - телефонный справочник. Она должна уметь хранить имена и
//номера телефонов, в интерактивном режиме осуществлять следующие операции: 
//0 - выйти
//1 - добавить запись(имя и телефон)
//2 - распечатать все имеющиеся записи
//3 - найти телефон по имени
//4 - найти имя по телефону
//5 - сохранить текущие данные в файл
//При запуске программа должна читать данные из файла(того самого, в который сохраняет данные),
//если файла нет - начинать с пустой базы номеров.Размер базы ограничен сотней записей.

#include <stdio.h>
#include <locale.h>

struct Contact
{
	char name[50]{};
	int lengthOfName = 0;
	char number[50]{};
	int lengthOfNumber = 0;
	Contact* next = nullptr;
};

struct ListOfContact
{
	Contact *head = nullptr;
	Contact *tail = nullptr;
	int length = 0;
};

ListOfContact *createList()
{
	return new ListOfContact;
}

int isEmpty(ListOfContact* ListOfContact)
{
	return ListOfContact->head == nullptr;
}

void add(ListOfContact* ListOfContact)
{
	setlocale(LC_ALL, "Rus");

	if (!isEmpty(ListOfContact))
	{
		ListOfContact->tail->next = new Contact;
		ListOfContact->tail = ListOfContact->tail->next;
	}
	else
	{
		ListOfContact->head = new Contact;
		ListOfContact->tail = ListOfContact->head;
	}
	ListOfContact->length++;

	printf("Введите имя\n");
	char nameReception[50]{};
	int counterName = 0;
	while (true)
	{
		scanf("%c", &nameReception[counterName]);
		if ((nameReception[counterName] == '\n') && (counterName != 0))
		{
			break;
		}
		else if (nameReception[counterName] != '\n')
		{
			ListOfContact->tail->lengthOfName++;
			ListOfContact->tail->name[counterName] = nameReception[counterName];
			counterName++;
		}
	}

	printf("Введите номер\n");
	char numberReception[50]{};
	int counterNumber = 0;
	while (true)
	{
		scanf("%c", &numberReception[counterNumber]);
		if (numberReception[counterNumber] == '\n')
		{
			break;
		}
		ListOfContact->tail->lengthOfNumber++;
		ListOfContact->tail->number[counterNumber] = numberReception[counterNumber];
		counterNumber++;
	}
}

void print(ListOfContact* ListOfContact)
{
	int length = ListOfContact->length;
	Contact *PrintfContact = ListOfContact->head;
	for (int i = 0; i < length; i++)
	{
		int counterOfName = PrintfContact->lengthOfName;
		for (int i = 0; i <= counterOfName; i++)
		{
			printf("%c", PrintfContact->name[i]);
		}
		printf("\n"); 
		int counterOfNumber = PrintfContact->lengthOfNumber;
		for (int i = 0; i <= counterOfNumber; i++)
		{
			printf("%c", PrintfContact->number[i]);
		}
		printf("\n\n");
		PrintfContact = PrintfContact->next;
	}
	delete PrintfContact;
}

void screachWithName(ListOfContact* ListOfContact, char skreachingName[], int counter)
{
	Contact* Screach = ListOfContact->head;
	int length = ListOfContact->length;
	for (int i = 0; i < length; i++)
	{
		int sizeName = Screach->lengthOfName;
		for (int i = 0; i < sizeName; i++)
		{
			for (int k = 0; k < counter; k++)
			{
				if (Screach->name[i + k] != skreachingName[k])
				{
					break;
				}
				else if (k == counter - 1)
				{
					printf("\n");
					int counterOfName = Screach->lengthOfName;
					for (int j = 0; j <= counterOfName; j++)
					{
						printf("%c", Screach->name[j]);
					}
					printf("\n");
					int counterOfNumber = Screach->lengthOfNumber;
					for (int j = 0; j <= counterOfNumber; j++)
					{
						printf("%c", Screach->number[j]);
					}
					printf("\n");
					break;
				}
			}
		}
		Screach = Screach->next;
	}
	delete Screach;
}

void screachWithNumber(ListOfContact* ListOfContact, char skreachingNumber[], int counter)
{
	Contact* ScreachName = ListOfContact->head;
	int length = ListOfContact->length;
	for (int i = 0; i < length; i++)
	{
		int sizeNumber = ScreachName->lengthOfNumber;
		for (int i = 0; i < sizeNumber; i++)
		{
			for (int k = 0; k < counter; k++)
			{
				if (ScreachName->number[i + k] != skreachingNumber[k])
				{
					break;
				}
				else if (k == counter - 1)
				{
					printf("\n");
					int counterOfName = ScreachName->lengthOfName;
					for (int j = 0; j <= counterOfName; j++)
					{
						printf("%c", ScreachName->name[j]);
					}
					printf("\n");
					int counterOfNumber = ScreachName->lengthOfNumber;
					for (int j = 0; j <= counterOfNumber; j++)
					{
						printf("%c", ScreachName->number[j]);
					}
					printf("\n");
					i = sizeNumber;
					break;
				}
			}
		}
		ScreachName = ScreachName->next;
	}
	delete ScreachName;
}

void save(ListOfContact* ListOfContact)
{
	if (!isEmpty(ListOfContact))
	{
		FILE* file = fopen("Contacts.txt", "w");

		Contact* SaveContact = ListOfContact->head;
		int length = ListOfContact->length;
		for (int i = 0; i < length; i++)
		{
			fwrite(SaveContact->name, sizeof(char), SaveContact->lengthOfName, file);
			fprintf(file, "%c", ' ');
			fwrite(SaveContact->number, sizeof(char), SaveContact->lengthOfNumber, file);
			fprintf(file, "%c",'\n');
			SaveContact = SaveContact->next;
		}
		delete SaveContact;
		fclose(file);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	
	int comand = 1;
	ListOfContact* ListOfContact = createList();
	
	
	FILE* file = fopen("Contacts.txt", "r");
	if (!file) 
	{
		printf("Файл не найден. Он будет создан автоматически при первом созранении.\n");
	}
	else
	{
		while (!feof(file))
		{
			Contact* PreTail = ListOfContact->tail;

			if (!isEmpty(ListOfContact))
			{
				ListOfContact->tail->next = new Contact;
				ListOfContact->tail = ListOfContact->tail->next;
			}
			else
			{
				ListOfContact->head = new Contact;
				ListOfContact->tail = ListOfContact->head;
			}
			ListOfContact->length++;
			int counterName = 0;

			while (true)
			{		
				char elementOfName = 0;
				const int readBytes = fscanf(file, "%c", &elementOfName);
				if ((elementOfName == ' ')||(elementOfName == '\n')||(elementOfName == NULL))
				{
					break;
				}

				ListOfContact->tail->name[counterName] = elementOfName;
				counterName++;
				ListOfContact->tail->lengthOfName = counterName;
			}
			if (!counterName)
			{
				delete ListOfContact->tail;
				ListOfContact->tail = PreTail;
				ListOfContact->length--;
				break;
			}

			int counterNumber = 0;
			while (true)
			{
				char elementOfNumber = 0;
				const int readBytes = fscanf(file, "%c", &elementOfNumber);
				if ((elementOfNumber == '\n')||(elementOfNumber == NULL))
				{
					break;
				}
				ListOfContact->tail->number[counterNumber] = elementOfNumber;
				counterNumber++;
				ListOfContact->tail->lengthOfNumber = counterNumber;
			}
			delete PreTail;
		}
		fclose(file);
	}

	while (true)
	{
		printf("\nЗдравствуйте, введите номер команды, для выполнения:\n");
		printf("0 - выйти\n");
		printf("1 - добавить запись(имя и телефон)\n");
		printf("2 - распечатать все имеющиеся записи\n");
		printf("3 - найти телефон по имени\n");
		printf("4 - найти имя по телефону\n");
		printf("5 - сохранить текущие данные в файл\n\n");
		scanf("%d", &comand);
		switch (comand)
		{
		case 0:
		{
			delete ListOfContact;
			return 0;
			break;
		}
		case 1:
		{
			add(ListOfContact);
			break;
		}
		case 2:
		{
			print(ListOfContact);
			break;
		}
		case 3:
		{
			printf("Введите имя\n");
			char sendName[50]{};
			int counterOfSign = 0;
			char name[50]{};
			while (true)
			{
				scanf("%c", &sendName[counterOfSign]);
				if ((sendName[counterOfSign] == '\n') && (counterOfSign != 0))
				{
					break;
				}
				else if (sendName[counterOfSign] != '\n')
				{
					name[counterOfSign] = sendName[counterOfSign];
					counterOfSign++;
				}
 			}
			screachWithName(ListOfContact, name, counterOfSign);
			break;
		}
		case 4:
		{
			printf("Введите номер\n");
			char sendNumber[50]{};
			int counterOfSign = 0;
			char number[50]{};
			while (true)
			{
				scanf("%c", &sendNumber[counterOfSign]);
				if ((sendNumber[counterOfSign] == '\n') && (counterOfSign != 0))
				{
					break;
				}
				else if (sendNumber[counterOfSign] != '\n')
				{
					number[counterOfSign] = sendNumber[counterOfSign];
					counterOfSign++;
				}
			}
			screachWithNumber(ListOfContact, number, counterOfSign);
			break;
		}
		case 5:
		{
			save(ListOfContact);
			break;
		}
		default:
		{
			return -1;
			break;
		}
		}
	}
}