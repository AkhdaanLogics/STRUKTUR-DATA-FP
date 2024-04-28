#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int pil, tiket;

string userBaru, passBaru, loginUser, passUser, tanggalBerangkat, jamPemberangkatan;

struct Identitas
{
	string nama;
	int telp;
	string email;

}dataDiri;

struct RutePenerbangan
{
	string tujuan1 = "Jogja - Klaten";
	string tujuan2 = "Jogja - Solo";
	string tujuan3 = "Jogja - Bali";
}rute;

void printTicket()
{
	cout << "Tiket anda sedang di proses";
	for (int i = 0; i < 4; i++)
	{
		cout << ".";
		Sleep(1000);
	}
	cout << endl;

	cout << "Account Name\t\t : " << dataDiri.nama << endl;
	cout << "\n\n===================================\n\n";
	cout << "Jumlah Pesanan Tiket\t : " << tiket << endl;
	if (pil == 1)
	{
		cout << "Tujuan Pemberangkatan\t : " << rute.tujuan1;
	}

	if (pil == 2)
	{
		cout << "Tujuan Pemberangkatan\t : " << rute.tujuan2;
	}

	if (pil == 3)
	{
		cout << "Tujuan Pemberangkatan\t : " << rute.tujuan3;
	}
	
	else
	{
		cout << "[SYSTEM ERROR]\n";
		cout << "1. Pastikan pengisian formulir anda sesuai aturan input\n";
		cout << "2. Hubungi admin apabila masalah terus berlanjut\n";
	}
	
	cout << "Tanggal Pemberangkatan\t : " << tanggalBerangkat << endl;
	cout << "Jam Pemberangkatan\t\t : " << jamPemberangkatan << endl;

	cout << "\n\n===================================\n\n";
}

void validasiPemberangkatan()
{

}

void PilihanJam()
{
	cout << "Pilih Jam Penerbangan\n";
	cout << "Masukkan Tanggal\t\t : ";
	cin >> tanggalBerangkat;
	cout << "Masukkan Jam Pemberangkatan\t : ";
	cin >> jamPemberangkatan;
	cout << "Jumlah Tiket Yang Dibeli\t : ";
	cin >> tiket;
	validasiPemberangkatan();
}


void PilihPesawat()
{
	cout << "Pilih Pesawat\n1. Batik Air\n2. Lion Air\n3. Garuda Indonesia\nMasukkan Pilihan : ";
	cin >> pil;
	PilihanJam();
}

void PilihRute()
{
	char input;
	cout << "Pilihan Penerbangan\n1. Jogja - Klaten\n2. Jogja - Solo\n3. Jogja - Bali\n";
	cout << "Masukkan Pilihan : ";
	cin >> pil;

	if (pil == 1)
	{
		cout << "Estimasi biaya penerbangan anda adalah : ";
		cout << "Apakah anda ingin melanjutkan pemesanan?\n";
		cout << "Masukkan pilihan [Y/N] : ";
		cin >> input;
		if (input == 'Y' || input == 'y')
		{
			printTicket();
		}

		else if (input == 'N' || input == 'n')
		{
			while (true);
		}

		else
		{
			cout << "Inputan anda salahh!\n";
		} while (false);
	}
}

void HalamanAdmin()
{
	cout << "Menu Admin\n1. Lihat Data Penumpang\n2. Cari Nama Penumpang\n3. Jadwal Pesawat\n Masukkan Pilihan : ";
	cin >> pil;
}

void HalamanUser()
{
	PilihPesawat();
	PilihRute();
}

void Registrasi()
{
	cout << "1. Buat Akun\n2. Login\nMasukkan Pilihan : ";
	cin >> pil;
}

void Login();

void BuatAkun()
{
	cout << "Buat Akun\n";
	cout << "Username : ";
	cin >> userBaru;
	cout << "Password : ";
	cin >> passBaru;
	cout << "Akun Berhasil Dibuat!\n";
	_getch();
	system("cls");
	Login();
}

void ValidasiAkun();

void Login()
{
	cout << "Halaman Login\n";
	cout << "Username : ";
	cin >> loginUser;
	cout << "Password : ";
	cin >> passUser;

	ValidasiAkun();

}

void ValidasiAkun()
{

	if (loginUser == "root" && passUser == "root")
	{
		cout << "Anda Login sebagai admin!";
		_getch();
		system("cls");
		HalamanAdmin();
	}
	else if (loginUser == userBaru && passUser == passBaru)
	{
		cout << "Login Berhasil!";
		_getch();
		system("cls");
		HalamanUser();
	}
	else
	{
		cout << "Password atau Username salah!";
		_getch();
		system("cls");
		Login();
	}
}

int main()
{
	Registrasi();
	switch (pil)
	{
	case 1:
		BuatAkun();
		break;
	case 2:
		Login();
		break;
	default:
		cout << "Inputan Salah!";
	}
}