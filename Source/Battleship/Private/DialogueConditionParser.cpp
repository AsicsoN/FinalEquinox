#include "Battleship.h"
#include "DialogueConditionParser.h"

bool UDialogueConditionParser::ParseConditionString(FString input, UCharacterSheet* characterSheet)
{
	FString operation;

	if (input.Contains("<="))
	{
		operation = "<=";
	}
	else if (input.Contains(">="))
	{
		operation = ">=";
	}
	else if (input.Contains("<"))
	{
		operation = "<";
	}
	else if (input.Contains(">"))
	{
		operation = ">";
	}
	else if (input.Contains("=="))
	{
		operation = "==";
	}
	else if (input.Contains("!="))
	{
		operation = "!=";
	}
	
	return Operator(input, characterSheet, operation);
}

bool UDialogueConditionParser::Operator(FString input, UCharacterSheet* characterSheet, FString operation)
{
	FString left;
	FString right;
	if (input.Split(FString(operation), &left, &right))
	{
		left = left.TrimStartAndEnd();
		right = right.TrimStartAndEnd();
		
		FString leftValue = characterSheet->GetVariableValue(left);
		FString rightValue = characterSheet->GetVariableValue(right);

		if (operation == "==")
		{
			if (leftValue == rightValue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (operation == "!=")
		{
			if (leftValue != rightValue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		int32 leftInt = 0;
		int32 rightInt = 0;

		if (leftValue == "N/A")
		{
			leftInt = FCString::Atoi(*left);
		}
		else
		{
			leftInt = FCString::Atoi(*leftValue);
		}

		
		if (rightValue == "N/A")
		{
			rightInt = FCString::Atoi(*right);
		}
		else
		{
			rightInt = FCString::Atoi(*rightValue);
		}

		if (operation == "<=")
		{
			if (leftInt <= rightInt)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (operation == ">=")
		{
			if (leftInt >= rightInt)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (operation == "<")
		{
			if (leftInt < rightInt)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (operation == ">")
		{
			if (leftInt > rightInt)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}
