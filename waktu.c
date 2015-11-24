#include <stdio.h>
#include <time.h>
#include <string.h>
/*time()  : untuk mendapatkan informasi jumlah detik sejak tahun 1/11970
  localtime() : untuk meubah informasi jumlah detik menjadi informasi kalender (hari tanggal, bulan, tahun JAM:MENIT:DETIK) saat ini.
 strftime():  mencetak data kalender sesuai format*/

/*BY : D400150072*/
void tampilkan_kalender() {

	 time_t DETIK;
	 struct tm *info;
     char buffer[100];
	 char HARI[20];

	 time( &DETIK );  //mengumpulkan informasi jumlah detik

	 //merubah format data  ( localtime( ))
	 //dari JUMLAH DETIK menjadi KALENDER
	 info = localtime( &DETIK );
	 //merubah info menjadi TEKS

     strftime(buffer,100," %d %B %Y - %H:%M:%S", info);
	 // printf("Hari ke %ld \n", info.tm_wday);

	strftime(HARI,10,"%A", info);
	if ( strcmp(HARI,"Monday") == 0 ) {
			printf("\n Hari ini SENIN \n");
			printf(" Pada Tanggal: | %s |\n", buffer );
	}
	if ( strcmp(HARI,"Tuesday") == 0 ) {
			printf("\n Hari ini SELASA \n");
			printf(" Pada Tanggal: | %s |\n", buffer );
	}
	if ( strcmp(HARI,"Wednesday") == 0 ) {
			printf("\n Hari ini RABU \n");
			printf(" Pada Tanggal: | %s |\n", buffer );
	}
	if ( strcmp(HARI,"Thursday") == 0 ) {
			printf("\n Hari ini KAMIS \n");
			printf(" Pada Tanggal: | %s |\n", buffer );
	}
	if ( strcmp(HARI,"Friday") == 0 ) {
			printf("\n Hari ini JUM'AT \n");
			printf(" Pada Tanggal: | %s |\n", buffer );
	}
	if ( strcmp(HARI,"Saturday") == 0 ) {
			printf("\n Hari ini SABTU \n");
			printf(" Pada Tanggal: | %s |\n", buffer );
	}
	if ( strcmp(HARI,"Sunday") == 0 ) {
			printf("\n Hari ini MINGGU \n");
			printf(" Pada Tanggal: | %s |\n", buffer );
	}
}

int main ()
{
  time_t AWAL=0, AKHIR=0;

	time( &AWAL );
	while (1) {
		time( &AKHIR );
		if ( AKHIR - AWAL > 0 ) {
			//tampilkan tanggal
			tampilkan_kalender();
			AWAL = AKHIR;
		}

	}

   return(0);
}
