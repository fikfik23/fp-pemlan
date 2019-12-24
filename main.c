#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>

#define MAX 99

int jump(int arr[], int jumlah, int cari){
	int m = sqrt(jumlah);
	int indexatas = m;
	int indexbawah = 0;
	int ketemu = 0;
	int index = -1;
	int i, j;
	for (i=0; i<(jumlah/m); i++){
		if (cari==arr[indexbawah]){//pengecekan dengan arr[indexbawah]
			ketemu = 1;
			index = indexbawah;
			break;
		}
		else if (cari==arr[indexatas]){//pengecekan degan arr[indexatas]
			ketemu = 1;
			index = indexatas;
			break;
		}
		else if (cari>arr[indexbawah]&&cari<arr[indexatas]){//pengecekan diantara arr[indexatas] dan arr[indexbawah]
			for ( j=indexbawah; j<indexatas; j++){
				if (cari==arr[j]){
					index = j;
					ketemu = 1;
				}
			}
			break;
		}
		else if (cari>arr[indexbawah]&&i==((jumlah/m)-1)){//pengecekan jika lebih dari arr[indexbawah] dan saat putaran terakhir
			for ( j=indexbawah; j<indexatas; j++){
				if (cari==arr[j]){
					index = j;
					ketemu = 1;
					break;
				}
			}
		}
		else{
			indexbawah = indexatas;
			indexatas = indexatas + m;
		}
	}
	return index;
}

//int jump_search(int a[], int low, int high, int val, int z)
//{
//int step, i;
//step = z;
//for(i=0; i<step; i++)
//{
//if(val < a[step])
//high = step - 1;
//else
//low = step + 1;
//}
//for(i=low; i<=high; i++)
//{
//printf("%d", a[i]);
//if(a[i] == val)
//return i;
//}
////return -1;
//}

struct stock
{
	char nama[10];
	int harga;
};

int main()
{
	struct stock barang[MAX];
    int b[MAX];
    int search,update;
    int ul=0,n,i,j,p,sw=1,temp,z=0;
    int val,pos,cari[MAX];
    int harga=0,kembalian,bayar;
    
    while(ul==0)
	{
    
    system("cls");
    printf("=============================\n");
    printf("Selamat Datang\n");
    printf("=============================\n");
    printf("1. Memasukan Barang.\n");
    printf("2. Mengurutkan dari harga yang termurah.\n");
    printf("3. Mencari.\n");
    printf("4. Merubah Harga\n");
    printf("5. Total Harga.\n");
    printf("6. Keluar.\n");
    printf("=============================\n");
    scanf("%d",&p);
    
    switch(p)
	{
	case 1:
    printf("Masukkan banyak data.\n");
    scanf("%d",&n);
    printf("Masukkan data :\n");
    for(i=0;i<n;i++)
    {
    	printf("Masukkan nama barang	: ");
        scanf("%s",barang[z].nama);
        printf("Masukkan Harga barang	: ");
        scanf("%d",&barang[z].harga);
        b[z]=barang[z].harga;
        cari[z]=barang[z].harga;
        z++;
    }
    break;

	case 2:
			printf("=====================\n");
		    printf("Sebelum diurutkan\n");
		    printf("=====================\n");
    for(i=0;i<z;i++)
	{
		printf("Harga %d\n",barang[i].harga);
	}
	printf("=====================\n");
    
    printf("=====================\n");
    printf("\nSetelah dirutkan\n");
    printf("=====================\n");
    sw=1;
    for(i=0;i<z-1 &&sw==1;i++)
    {
        sw=0;
        for(j=0;j<n-1-i;j++)
        {
            if(b[j]>b[j+1])
	        {
	        temp=b[j+1];
	        b[j+1]=b[j];
	        b[j]=temp;
	        sw=1;
    		}
    if(b[z-1-j]<b[z-2-j])
    {
        temp=b[z-2-j];
        b[z-2-j]=b[z-1-j];
        b[z-1-j]=temp;
        sw=1;
    }
	    }
	}
	for(j=0;j<z;j++)
	{
		printf("Harga %d\n",b[j]);
	}
	printf("=====================\n");

	getch();
	
	break;

	case 3:
		printf("%d", b[0]);
		printf("%d", b[1]);
		printf("%d", b[2]);
		printf("\n Harga yang ingin dicari : ");
		scanf("%d", &val);
//		pos = jump_search(b, 0, z-1,val, z);
		pos = jump(b, z, val);
		if(pos == -1)
		printf("\n %d Maaf harga yang dicari tidak ada pada daftar ", val);
		else
		printf("\n %d harga ini terdapat pada posisi [%d] pada list barang yang dibeli", val,pos);
		getch();
		
		break;
	
	case 4:
		printf("Masukkan data yang ingin diubah : ");
		scanf("%d",&search);
		
		for(i=0;i<z;i++)
		{
			if(search==barang[i].harga)
			{
				printf("perbarui harga : ");
				scanf("%d",&update);
				barang[i].harga=update;
				b[i]=barang[i].harga;
				cari[i]=barang[i].harga;
			}
			else
			{
				
			}
		}
		
		break;
	
	case 5:
			printf("===================================\n");
			printf("No.Nama Barang\tHarga\n");
			printf("===================================\n");
		for(i=0;i<z;i++)
		{
			printf("%d.%s\tHarga		: %d\n",i,barang[i].nama,barang[i].harga);
			harga+=barang[i].harga;
		}
			printf("===================================\n");
			printf("Total harga		: %d\n",harga);
			printf("Dibayar			: ");
			scanf("%d",&bayar);
			printf("===================================\n");
			kembalian=bayar-harga;
			printf("Kembalian		: %d\n",kembalian);
			getch();
			
			for(i=0;i<z;i++)
			{
				cari[i]=0;
				z=0;
			}
		break;
	
	case 6:
		printf("Terima Kasih\n");
		ul=1;
		
		break;
	}
	}


return 0;
}
