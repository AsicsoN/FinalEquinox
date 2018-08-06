#include "Battleship.h"
#include "Stardate.h"

#define LOCTEXT_NAMESPACE "Stardate"

UStardate::UStardate()
{

}

UStardate::UStardate(int32 Year, int32 Month, int32 Day)
{
	this->Year = Year;
	this->Month = Month;
	this->Day = Day;
}

FText UStardate::GetFormattedDate()
{
	FText MonthName;
	switch (Month)
	{
	case 1:
		MonthName = LOCTEXT("Month1", "Temple-flame");
		break;
	case 2:
		MonthName = LOCTEXT("Month2", "Wander");
		break;
	case 3:
		MonthName = LOCTEXT("Month3", "Birth");
		break;
	case 4:
		MonthName = LOCTEXT("Month4", "Zek-Ray");
		break;
	case 5:
		MonthName = LOCTEXT("Month5", "Harvest");
		break;
	case 6:
		MonthName = LOCTEXT("Month6", "Red-Dawn");
		break;
	case 7:
		MonthName = LOCTEXT("Month7", "Renew");
		break;
	default:
		MonthName = LOCTEXT("MonthX", "Unknown");
	}


	FFormatNamedArguments Arguments;
	Arguments.Add(TEXT("Day"), FText::AsNumber(Day));
	Arguments.Add(TEXT("Month"), MonthName);
	Arguments.Add(TEXT("Year"), FText::AsNumber(Year));
	return FText::Format(LOCTEXT("FormattedStardate", "{Day} {Month} {Year}"), Arguments);
}

void UStardate::AddDay()
{
	AddDays(1);
}

void UStardate::AddDays(int32 days)
{
	Day = Day + days;
	if (Day > 24)
	{
		Month++;
		Day = Day - 24;
	}
	if (Month > 7)
	{
		Year++;
		Month = Month - 7;
	}
}

#undef LOCTEXT_NAMESPACE
