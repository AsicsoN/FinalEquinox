#include "Battleship.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawnBase.h"
#include "Crew.h"
#include "PlayerCrewObject.h"
#include "CharacterSheetInitialization.h"

UCharacterSheet* UCharacterSheetInitialization::CreateStartingCharacterSheet()
{
	UCharacterSheet* characterSheet = NewObject<UCharacterSheet>();

	characterSheet->PlayerCrewObject = NewObject<UPlayerCrewObject>();

	UCrew* crew1 = NewObject<UCrew>();
	UCrew* crew2 = NewObject<UCrew>();

	crew1->CrewName = "Jonathan Phelps";
	crew1->CrewRace = ERace::Human;
	crew1->IsMale = true;
	crew1->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitHumanMaleJon"), NULL, LOAD_None, NULL);
	crew1->Leadership = -3;
	crew1->Navigation = 1;
	crew1->Gunnery = -2;
	crew1->Engineering = 1;
	crew1->Science = -3;
	crew1->Tactics = -1;
	crew1->Communication = 0;
	crew1->SubsystemRepair = 1;
	crew1->ShieldRepair = -3;

	crew2->CrewName = "Ren-Sa";
	crew2->CrewRace = ERace::Malderian;
	crew2->IsMale = false;
	crew2->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitMalderianFemale2"), NULL, LOAD_None, NULL);
	crew2->Leadership = -2;
	crew2->Navigation = -2;
	crew2->Gunnery = 0;
	crew2->Engineering = -3;
	crew2->Science = 0;
	crew2->Tactics = 0;
	crew2->Communication = -1;
	crew2->SubsystemRepair = -2;
	crew2->ShieldRepair = -5;

	characterSheet->UnusedCrew.Add(crew1);
	characterSheet->UnusedCrew.Add(crew2);

	//UObject* ObjectToSpawn = FindObject<UObject>(characterSheet, TEXT("/Game/Blueprints/Pawns/PlayerBattleshipPawn.PlayerBattleshipPawn_C"));
	//APlayerShipPawnBase* flagship = NewObject<APlayerShipPawnBase>(characterSheet, ObjectToSpawn->StaticClass());

	APlayerShipPawnBase* flagship = LoadObject<APlayerShipPawnBase>(characterSheet, TEXT("/Game/Blueprints/Pawns/PlayerBattleshipPawn.Default__PlayerBattleshipPawn_C"), NULL, LOAD_None, NULL);
	flagship->Name = "HCS Odysseus";
	flagship->Type = EType::Large;
	flagship->Captain = characterSheet->PlayerCrewObject;
	flagship->NavigationOfficer = NewObject<UCrew>();
	flagship->TacticsOfficer = NewObject<UCrew>();
	flagship->ScienceOfficer = NewObject<UCrew>();
	flagship->Engineer = NewObject<UCrew>();
	flagship->CAG = NewObject<UCrew>();

	flagship->NavigationOfficer->CrewName = "Sam Baker";
	flagship->NavigationOfficer->IsLocked = true;
	flagship->NavigationOfficer->CrewRace = ERace::Human;
	flagship->NavigationOfficer->IsMale = true;
	flagship->NavigationOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitSamBaker"), NULL, LOAD_None, NULL);
	flagship->NavigationOfficer->Leadership = 2;
	flagship->NavigationOfficer->Navigation = 2;
	flagship->NavigationOfficer->Gunnery = 1;
	flagship->NavigationOfficer->Engineering = -4;
	flagship->NavigationOfficer->Science = 0;
	flagship->NavigationOfficer->Tactics = 1;
	flagship->NavigationOfficer->Communication = -1;
	flagship->NavigationOfficer->SubsystemRepair = -4;
	flagship->NavigationOfficer->ShieldRepair = -5;

	flagship->TacticsOfficer->CrewName = "Tu'Vol Strogonar";
	flagship->TacticsOfficer->CrewRace = ERace::Krum;
	flagship->TacticsOfficer->IsMale = true;
	flagship->TacticsOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitKrumMale1"), NULL, LOAD_None, NULL);
	flagship->TacticsOfficer->Leadership = -4;
	flagship->TacticsOfficer->Navigation = -2;
	flagship->TacticsOfficer->Gunnery = -1;
	flagship->TacticsOfficer->Engineering = -5;
	flagship->TacticsOfficer->Science = 0;
	flagship->TacticsOfficer->Tactics = 3;
	flagship->TacticsOfficer->Communication = 2;
	flagship->TacticsOfficer->SubsystemRepair = -5;
	flagship->TacticsOfficer->ShieldRepair = -4;

	flagship->ScienceOfficer->CrewName = "Mar-Tun";
	flagship->ScienceOfficer->IsLocked = true;
	flagship->ScienceOfficer->CrewRace = ERace::Malderian;
	flagship->ScienceOfficer->IsMale = false;
	flagship->ScienceOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitMarTun"), NULL, LOAD_None, NULL);
	flagship->ScienceOfficer->Leadership = -3;
	flagship->ScienceOfficer->Navigation = -2;
	flagship->ScienceOfficer->Gunnery = -5;
	flagship->ScienceOfficer->Engineering = 1;
	flagship->ScienceOfficer->Science = 3;
	flagship->ScienceOfficer->Tactics = -5;
	flagship->ScienceOfficer->Communication = -1;
	flagship->ScienceOfficer->SubsystemRepair = 3;
	flagship->ScienceOfficer->ShieldRepair = 1;

	flagship->Engineer->CrewName = "Samantha Matthaus";
	flagship->Engineer->CrewRace = ERace::Human;
	flagship->Engineer->IsMale = false;
	flagship->Engineer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitHumanFemale1"), NULL, LOAD_None, NULL);
	flagship->Engineer->Leadership = 1;
	flagship->Engineer->Navigation = 1;
	flagship->Engineer->Gunnery = 0;
	flagship->Engineer->Engineering = 2;
	flagship->Engineer->Science = 1;
	flagship->Engineer->Tactics = 1;
	flagship->Engineer->Communication = 0;
	flagship->Engineer->SubsystemRepair = 2;
	flagship->Engineer->ShieldRepair = 1;

	characterSheet->Fleet.Add(flagship);

	APlayerShipPawnBase* destroyer = LoadObject<APlayerShipPawnBase>(characterSheet, TEXT("/Game/Blueprints/Pawns/PlayerDestroyerPawn.Default__PlayerDestroyerPawn_C"), NULL, LOAD_None, NULL);
	destroyer->Name = "HCS Amphion";
	destroyer->Type = EType::Medium;
	destroyer->Captain = NewObject<UCrew>();
	destroyer->NavigationOfficer = NewObject<UCrew>();
	destroyer->TacticsOfficer = NewObject<UCrew>();
	destroyer->ScienceOfficer = NewObject<UCrew>();
	destroyer->Engineer = NewObject<UCrew>();
	destroyer->CAG = NewObject<UCrew>();

	destroyer->Captain->CrewName = "Zon-Ra";
	destroyer->Captain->CrewRace = ERace::Malderian;
	destroyer->Captain->IsMale = true;
	destroyer->Captain->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitMalderianMale1"), NULL, LOAD_None, NULL);
	destroyer->Captain->Leadership = -2;
	destroyer->Captain->Navigation = -3;
	destroyer->Captain->Gunnery = 2;
	destroyer->Captain->Engineering = 1;
	destroyer->Captain->Science = 0;
	destroyer->Captain->Tactics = 0;
	destroyer->Captain->Communication = 1;
	destroyer->Captain->SubsystemRepair = -2;
	destroyer->Captain->ShieldRepair = 1;


	destroyer->NavigationOfficer->CrewName = "Sergey Yegorow";
	destroyer->NavigationOfficer->CrewRace = ERace::Human;
	destroyer->NavigationOfficer->IsMale = true;
	destroyer->NavigationOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitHumanMaleSergey"), NULL, LOAD_None, NULL);
	destroyer->NavigationOfficer->Leadership = 1;
	destroyer->NavigationOfficer->Navigation = 2;
	destroyer->NavigationOfficer->Gunnery = -2;
	destroyer->NavigationOfficer->Engineering = -5;
	destroyer->NavigationOfficer->Science = -4;
	destroyer->NavigationOfficer->Tactics = -2;
	destroyer->NavigationOfficer->Communication = -4;
	destroyer->NavigationOfficer->SubsystemRepair = 0;
	destroyer->NavigationOfficer->ShieldRepair = -3;


	destroyer->TacticsOfficer->CrewName = "Xiohe Inwei";
	destroyer->TacticsOfficer->CrewRace = ERace::Krum;
	destroyer->TacticsOfficer->IsMale = false;
	destroyer->TacticsOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitKrumFemale1"), NULL, LOAD_None, NULL);
	destroyer->TacticsOfficer->Leadership = -4;
	destroyer->TacticsOfficer->Navigation = -2;
	destroyer->TacticsOfficer->Gunnery = 1;
	destroyer->TacticsOfficer->Engineering = -4;
	destroyer->TacticsOfficer->Science = -5;
	destroyer->TacticsOfficer->Tactics = 1;
	destroyer->TacticsOfficer->Communication = -1;
	destroyer->TacticsOfficer->SubsystemRepair = -3;
	destroyer->TacticsOfficer->ShieldRepair = -3;


	destroyer->ScienceOfficer->CrewName = "Io Ra";
	destroyer->ScienceOfficer->CrewRace = ERace::Barkhomi;
	destroyer->ScienceOfficer->IsMale = true;
	destroyer->ScienceOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitBarkhomiMale1"), NULL, LOAD_None, NULL);
	destroyer->ScienceOfficer->Leadership = -5;
	destroyer->ScienceOfficer->Navigation = -5;
	destroyer->ScienceOfficer->Gunnery = -2;
	destroyer->ScienceOfficer->Engineering = 1;
	destroyer->ScienceOfficer->Science = 1;
	destroyer->ScienceOfficer->Tactics = -4;
	destroyer->ScienceOfficer->Communication = -1;
	destroyer->ScienceOfficer->SubsystemRepair = 2;
	destroyer->ScienceOfficer->ShieldRepair = 2;


	destroyer->Engineer->CrewName = "Josh Hadley";
	destroyer->Engineer->CrewRace = ERace::Human;
	destroyer->Engineer->IsMale = false;
	destroyer->Engineer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitHumanMaleJosh"), NULL, LOAD_None, NULL);
	destroyer->Engineer->Leadership = -5;
	destroyer->Engineer->Navigation = -4;
	destroyer->Engineer->Gunnery = -2;
	destroyer->Engineer->Engineering = 1;
	destroyer->Engineer->Science = 0;
	destroyer->Engineer->Tactics = -5;
	destroyer->Engineer->Communication = -3;
	destroyer->Engineer->SubsystemRepair = 0;
	destroyer->Engineer->ShieldRepair = -1;

	characterSheet->Fleet.Add(destroyer);

	APlayerShipPawnBase* destroyer2 = DuplicateObject(destroyer, characterSheet);
	destroyer2->Name = "HCS Zethus";
	destroyer2->Type = EType::Medium;
	destroyer2->Captain = NewObject<UCrew>();
	destroyer2->NavigationOfficer = NewObject<UCrew>();
	destroyer2->TacticsOfficer = NewObject<UCrew>();
	destroyer2->ScienceOfficer = NewObject<UCrew>();
	destroyer2->Engineer = NewObject<UCrew>();
	destroyer2->CAG = NewObject<UCrew>();

	destroyer2->Captain->CrewName = "Kevin Sawall";
	destroyer2->Captain->CrewRace = ERace::Human;
	destroyer2->Captain->IsMale = true;
	destroyer2->Captain->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitHumanMaleKevin"), NULL, LOAD_None, NULL);
	destroyer2->Captain->Leadership = 1;
	destroyer2->Captain->Navigation = 1;
	destroyer2->Captain->Gunnery = 0;
	destroyer2->Captain->Engineering = 0;
	destroyer2->Captain->Science = 1;
	destroyer2->Captain->Tactics = 0;
	destroyer2->Captain->Communication = 0;
	destroyer2->Captain->SubsystemRepair = -4;
	destroyer2->Captain->ShieldRepair = -2;


	destroyer2->NavigationOfficer->CrewName = "Rxnh Keti";
	destroyer2->NavigationOfficer->CrewRace = ERace::Barkhomi;
	destroyer2->NavigationOfficer->IsMale = true;
	destroyer2->NavigationOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitBarkhomiMale2"), NULL, LOAD_None, NULL);
	destroyer2->NavigationOfficer->Leadership = 2;
	destroyer2->NavigationOfficer->Navigation = 2;
	destroyer2->NavigationOfficer->Gunnery = 1;
	destroyer2->NavigationOfficer->Engineering = -4;
	destroyer2->NavigationOfficer->Science = 0;
	destroyer2->NavigationOfficer->Tactics = 2;
	destroyer2->NavigationOfficer->Communication = 1;
	destroyer2->NavigationOfficer->SubsystemRepair = 1;
	destroyer2->NavigationOfficer->ShieldRepair = -5;


	destroyer2->TacticsOfficer->CrewName = "Kristen Maslanka";
	destroyer2->TacticsOfficer->CrewRace = ERace::Human;
	destroyer2->TacticsOfficer->IsMale = false;
	destroyer2->TacticsOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitHumanFemaleKristen"), NULL, LOAD_None, NULL);
	destroyer2->TacticsOfficer->Leadership = -3;
	destroyer2->TacticsOfficer->Navigation = -2;
	destroyer2->TacticsOfficer->Gunnery = -2;
	destroyer2->TacticsOfficer->Engineering = -5;
	destroyer2->TacticsOfficer->Science = 0;
	destroyer2->TacticsOfficer->Tactics = 3;
	destroyer2->TacticsOfficer->Communication = 1;
	destroyer2->TacticsOfficer->SubsystemRepair = -5;
	destroyer2->TacticsOfficer->ShieldRepair = -3;


	destroyer2->ScienceOfficer->CrewName = "Gergely Kovacs";
	destroyer2->ScienceOfficer->CrewRace = ERace::Human;
	destroyer2->ScienceOfficer->IsMale = true;
	destroyer2->ScienceOfficer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitHumanMaleGergely"), NULL, LOAD_None, NULL);
	destroyer2->ScienceOfficer->Leadership = -3;
	destroyer2->ScienceOfficer->Navigation = -2;
	destroyer2->ScienceOfficer->Gunnery = -5;
	destroyer2->ScienceOfficer->Engineering = 1;
	destroyer2->ScienceOfficer->Science = 3;
	destroyer2->ScienceOfficer->Tactics = -5;
	destroyer2->ScienceOfficer->Communication = -1;
	destroyer2->ScienceOfficer->SubsystemRepair = 2;
	destroyer2->ScienceOfficer->ShieldRepair = 1;


	destroyer2->Engineer->CrewName = "Yerla Ieo";
	destroyer2->Engineer->CrewRace = ERace::Malderian;
	destroyer2->Engineer->IsMale = false;
	destroyer2->Engineer->Portrait = LoadObject<UTexture2D>(characterSheet, TEXT("/Game/Textures/Crew/CrewPortraitMalderianFemale1"), NULL, LOAD_None, NULL);
	destroyer2->Engineer->Leadership = 1;
	destroyer2->Engineer->Navigation = 1;
	destroyer2->Engineer->Gunnery = 0;
	destroyer2->Engineer->Engineering = 2;
	destroyer2->Engineer->Science = 1;
	destroyer2->Engineer->Tactics = 1;
	destroyer2->Engineer->Communication = 0;
	destroyer2->Engineer->SubsystemRepair = 2;
	destroyer2->Engineer->ShieldRepair = 1;

	characterSheet->Fleet.Add(destroyer2);

	return characterSheet;
}
