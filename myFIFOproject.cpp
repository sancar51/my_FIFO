// myFIFOproject.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
uint16_t MAX = 10;
uint8_t FIFO[10];
int16_t tail = 0;
int16_t front = 0;
int16_t back = 0;
using namespace std;

void FIFO_write(uint8_t data)
{
	if (tail < MAX)
	{

		if (front < MAX)
		{
			FIFO[front] = data;
			front++;
			tail++;
		}
		else
		{
			front = 0;
			FIFO[front] = data;
			front++;
			tail++;
		}
		
		
	}

}

uint8_t FIFO_read()
{
	uint8_t data;
	if (tail > 0)
	{
		if (back < MAX)
		{
			data = FIFO[back];
			FIFO[back] = 0;
			back++;
			tail--;	
			return data;
		}
		else
		{
			back = 0;
			data = FIFO[back];
			FIFO[back] = 0;
			back++;
			tail--;
			return data;
		}
		

	}


	return 0;
}




int main()
{
	while (1)
	{
		int select;
		int data;
		
		std::cout << "\FIFO'ya veri kaydetmek icin 1'e FIFO'dan veri okumak icin 2'ye basin."<<endl;
		scanf_s("%d", &select);


		switch (select)
		{
		case 1: cout << "data girin"<<endl;
			scanf_s("%d", &data);
			FIFO_write(data);
			break;
		case 2: cout << " okunan data"<<endl;
			data= FIFO_read();
			cout << endl << data<<endl;
			break;

		default:
			break;
		}
	}
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
