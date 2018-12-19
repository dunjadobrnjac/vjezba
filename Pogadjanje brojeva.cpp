#include <iostream>
#include <cstdlib>  // sadrzi random funkciju - stalno vraca isti broj 
#include <time.h>   // zato treba i ova koja ima srand
#include <string>  // sl sve tri biblioteke su zbog š,č,đ,.. valjdaa
#include <cstdio>
#include <Windows.h>
static int osvojeniBodovi=10;
i   nt main()
{
	// Set console code page to UTF-8 so console known how to interpret string data
	SetConsoleOutputCP(CP_UTF8);
	// Enable buffering to prevent VS from chopping up UTF-8 byte sequences
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	while (true)
	{
		srand(time(0));
		int random = rand() % 101; // izabere random broj od 0 do 100 ( ako napises samo %100 onda je od 0 do 99)
		int broj;
		int brojPokusaja = 0;
		std::string odgovor;
		
		do
		{
			do //petlja za provjeru uslova prilikom unosenja brojeva
			{
				std::cout << " Unesi broj od 0 do 100 : ";
				while (!(std::cin >> broj) || std::cin.get() != '\n')
				{
					std::cout << " Unos nije validan! Unesite broj ponovo: ";
					std::cin.clear();
					std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // zabrana unosenja chakova i slova
				}

				if (broj < 0 || broj>100)
					std::cout << " Uneseni broj nije u dozvoljenom opsegu. " << std::endl;
			} while (broj < 0 || broj > 100); //ogranicenje opsega


			if (random < broj) //petlja za pogadjanje brojeva
				std::cout << u8" Broj koji tražite je manji od unesenog broja.\n"; // moze i <<std::endl- prelazak u novi red
			else if (random > broj)
				std::cout << u8" Broj koji tražite je veći od unesenog broja.\n";
			++brojPokusaja;
		} while (broj != random && brojPokusaja < 5);


		if (broj == random)
		{
			std::cout << u8" Čestitamo! Pogodili ste broj." << std::endl;
			osvojeniBodovi += 100 / brojPokusaja;
		}			
		else if (brojPokusaja == 5)
			std::cout << u8" Nemate više pokušaja." << std::endl;

		while (true) // pitanje hoce li ponovo igrati
		{
			std::cout << u8" Da li želite ponovo da igrate? (Da/Ne)? ";
			std::cin >> odgovor;

			if (odgovor.compare("ne")==0 || odgovor.compare("Ne")==0 || odgovor.compare("NE")==0 || odgovor.compare("nE")==0
				|| odgovor.compare("da")==0 || odgovor.compare("Da")==0 || odgovor.compare("dA")==0 || odgovor.compare("DA")==0)
				break;
			else
				std::cout << " Unesite 'Da' ili 'Ne'...\n";

		}

		if (odgovor.compare("ne")==0 || odgovor.compare("Ne")==0 || odgovor.compare("nE")==0 || odgovor.compare("NE")==0)
		{
			std::cout << " Hvala na igranju!" << std::endl;
			std::cout << u8" Vaš trenutni broj bodova je : " << osvojeniBodovi << std::endl;
			break;
		}
		else
			std::cout << "\n\n";
	}

	system("pause"); // omogucava da prozor ostane otvoren
	return 0;
}




